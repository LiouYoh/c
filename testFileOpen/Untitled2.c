#include <stdio.h>
int main(){
	FILE *fp1,*fp2;
	char filename1[80],filename2[80];
	char tempstr[32];
	printf("input:");
	scanf("%s",filename1);
	printf("output:");
	scanf("%s",filename2);
	fp1=fopen(filename1,"r");
	fp2=fopen(filename2,"w");
	
	while((fscanf(fp1,"%s",tempstr))!=EOF){
		fprintf(fp2,"%s\n",tempstr);
	}
	
	fclose(fp1);
	fclose(fp2);
	return 0;
}
