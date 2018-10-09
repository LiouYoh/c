#include <stdio.h>

int main(){
	char filename[80];
	FILE *f1,*f2;
	char fileName1[80],fileName2[80];
	char c[32];
	printf("read form :");
	scanf("%s",fileName1);
	printf("write to :");
	scanf("%s",fileName2);
	f1=fopen(fileName1,"r");
	f2=fopen(fileName2,"w");
	if((f1==NULL)||(f2==NULL)){
		printf("error\n");
		exit(1);
	}
	printf("executing\n");
	while((fgets(c,32,f1))!=NULL){
		printf("%s",c);
		fputs(c,f2);
	}
	printf("finish\n");
	fclose(f1);
	fclose(f2);
	return 0;
}
