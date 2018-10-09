#include <stdio.h>
int main(){
	FILE *fp;
	char temp[50];
	fp=fopen("data4","rb");
	fread(temp,sizeof(char),1,fp);
	int i=0;
	while(temp[i]!='\0'){
		printf("%c\n",temp[i]);
		i++;
	}
	return 0;
}
