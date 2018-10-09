#include <stdio.h>
int main(){
	
	char *input="hello";
	char output[60];
	int i=0;
	while(*(input+i)!='\0'){
		*(output+i)=*(input+i);
		i++;
	}
	output[i]='\0';
	printf("%s",output);
	printf("%s",input);
	return 0;
}
