#include <stdio.h>
int main(){
	FILE *fp1;
	char filename[80]="aa.txt";
	char tempstr[32];
	//printf("input the file:");
	//scanf("%s",filename);
	fp1=fopen(filename,"r");
	
	fseek(fp1,-1,SEEK_END);
	fscanf(fp1,"%s",tempstr);
	
	printf("tempstr=%s\n",tempstr);
	fclose(fp1);
	return 0;
}
