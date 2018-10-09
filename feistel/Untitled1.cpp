#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROUNDS 8

#define ACTION_ENCRYPT "-e"
#define ACTION_DECRYPT "-d"
#define MODE_ECB "ecb"
#define MODE_CBC "cbc"

enum { ACTION = 1, MODE };

uint32_t f(uint32_t block, uint32_t key);
uint64_t encrypt(uint32_t left, uint32_t right, uint32_t rounds, uint32_t keys[]);
uint64_t decrypt(uint32_t left, uint32_t right, uint32_t rounds, uint32_t keys[]);

void encrypt_ecb(FILE *infile, FILE *outfile, uint32_t rounds, uint32_t keys[]);
void decrypt_ecb(FILE *infile, FILE *outfile, uint32_t rounds, uint32_t keys[]);
void encrypt_cbc(FILE *infile, FILE *outfile, uint32_t rounds, uint32_t keys[]);
void decrypt_cbc(FILE *infile, FILE *outfile, uint32_t rounds, uint32_t keys[]);

void usage(void);

int main(int argc, char *argv[]) {
        uint32_t keys[ROUNDS] = { 0xDEADBEEF, 0xBAADF00D, 0xFEEDFACE, 0xCAFEBABE, 0xDEADBABE, 0xD15EA5E, 0xDECEA5ED, 0xBAADAC1D };
        FILE *infile, *outfile;
        /* Check argc */
        if(argc < 5) {
                fprintf(stderr,"An insufficient amount of arguments supplied\n");
                return EXIT_FAILURE;
        }
        /* Open in/out files */
        fprintf(stderr,"Trying to open file '%s' as input file\n",argv[3]);
        infile = fopen(argv[3],"r");
        if(!infile) {
                perror("fopen");
                return EXIT_FAILURE;
        }
        fprintf(stderr,"Trying to open file '%s' as output file\n",argv[4]);
        outfile = fopen(argv[4],"w");
        if(!outfile) {
                perror("fopen");
                return EXIT_FAILURE;
        }
        /* Parse cmdline */
        if(!strcmp(argv[ACTION],ACTION_ENCRYPT)) {
                if(!strcmp(argv[MODE],MODE_ECB)) {
                        encrypt_ecb(infile,outfile,ROUNDS,keys);
                } else if(!strcmp(argv[MODE],MODE_CBC)) {
                        encrypt_cbc(infile,outfile,ROUNDS,keys);
                } else {
                        usage();
                }
        } else if(!strcmp(argv[ACTION],ACTION_DECRYPT)) {
                if(!strcmp(argv[MODE],MODE_ECB)) {
                        fprintf(stderr,"decrypt_ecb()\n");
                        decrypt_ecb(infile,outfile,ROUNDS,keys);
                } else if(!strcmp(argv[MODE],MODE_CBC)) {
                        decrypt_cbc(infile,outfile,ROUNDS,keys);
                } else {
                        usage();
                }
        } else {
                usage();
        }
        /* Close files */
        fclose(infile);
        fclose(outfile);
        return 0;
}

void usage(void) {
        fprintf(stderr,"NOPE.\n");
}

uint32_t f(uint32_t block, uint32_t key) {
        return block ^ key;
}

uint64_t encrypt(uint32_t left, uint32_t right, uint32_t rounds, uint32_t keys[]) {
        uint32_t i, left1, right1;
        for(i = 0;i < rounds;i++) {
                left1 = f(left,keys[i]) ^ right;
                right1 = left;
                if(i == (rounds-1)) {
                        left = right1;
                        right = left1;
                } else {
                        left = left1;
                        right = right1;
                }
        }
        return (uint64_t)left<<32 | right;
}

uint64_t decrypt(uint32_t left, uint32_t right, uint32_t rounds, uint32_t keys[]) {
        uint32_t i, left1, right1;
        for(i = 0;i < rounds;i++) {
                left1 = f(left,keys[rounds-i-1]) ^ right;
                right1 = left;
                if(i == (rounds-1)) {
                        left = right1;
                        right = left1;
                } else {
                        left = left1;
                        right = right1;
                }
        }
        return (uint64_t)left<<32 | right;
}

void encrypt_ecb(FILE *infile, FILE *outfile, uint32_t rounds, uint32_t keys[]) {
        uint32_t left, right;
        size_t ret;
        uint64_t sblock;
        while(!feof(infile)) {
                memset(&sblock,0,sizeof(sblock));
                ret = fread(&sblock,1,sizeof(sblock),infile);
                if(!ret) break;
                left = (sblock>>32) & 0xFFFFFFFF;
                right = sblock & 0xFFFFFFFF;
                sblock = encrypt(left,right,ROUNDS,keys);
                ret = fwrite(&sblock,1,sizeof(sblock),outfile);
        }
}

void decrypt_ecb(FILE *infile, FILE *outfile, uint32_t rounds, uint32_t keys[]) {
        uint32_t left, right;
        size_t ret;
        uint64_t sblock;
        while(!feof(infile)) {
                memset(&sblock,0,sizeof(sblock));
                ret = fread(&sblock,1,sizeof(sblock),infile);
                if(!ret) break;
                left = (sblock>>32) & 0xFFFFFFFF;
                right = sblock & 0xFFFFFFFF;
                sblock = decrypt(left,right,ROUNDS,keys);
                ret = fwrite(&sblock,1,sizeof(sblock),outfile);
        }
}

void encrypt_cbc(FILE *infile, FILE *outfile, uint32_t rounds, uint32_t keys[]) {
        uint32_t left, right;
        size_t ret;
        uint64_t sblock, sblock_prev = 0xFEEDFACE;
        while(!feof(infile)) {
                memset(&sblock,0,sizeof(sblock));
                ret = fread(&sblock,1,sizeof(sblock),infile);
                if(!ret) break;
                /* CBC */
                sblock ^= sblock_prev;
                left = (sblock>>32) & 0xFFFFFFFF;
                right = sblock & 0xFFFFFFFF;
                sblock = encrypt(left,right,ROUNDS,keys);
                sblock_prev = sblock;
                fwrite(&sblock,1,sizeof(sblock),outfile);
        }
}

void decrypt_cbc(FILE *infile, FILE *outfile, uint32_t rounds, uint32_t keys[]) {
        int first = 1;
        uint32_t left, right;
        size_t ret;
        uint64_t sblock, sblock_prev, saved;
        while(!feof(infile)) {
                memset(&sblock,0,sizeof(sblock));
                ret = fread(&sblock,1,sizeof(sblock),infile);
                if(!ret) break;
                saved = sblock;
                left = (sblock>>32) & 0xFFFFFFFF;
                right = sblock & 0xFFFFFFFF;
                sblock = decrypt(left,right,ROUNDS,keys);
                if(first) {
                        sblock ^= 0xFEEDFACE;
                        first = 0;
                } else {
                        sblock ^= sblock_prev;
                }
                /* CBC */
                sblock_prev = saved;
                fwrite(&sblock,1,sizeof(sblock),outfile);
        }
}
