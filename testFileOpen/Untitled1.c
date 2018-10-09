#include <stdio.h>
int main(){
	FILE *fp1;
	FILE *fp2;
	char filename1[80];
	char filename2[80];
	char temp[32];
	
	printf("input:");
	scanf("%s",filename1);
	printf("output:");
	scanf("%s",filename2);
	fp1=fopen(filename1,"r");
	fp2=fopen(filename2,"w");
	while((fgets(temp,32,fp1))!=NULL){
		//printf("%s",temp);
		fputs(temp,fp2);
	}
	
	fclose(fp1);
	fclose(fp2);
	return 0;
} 
