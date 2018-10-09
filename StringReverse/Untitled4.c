#include <stdio.h>
int main(){
	char in[]="hello";
	
	int i=0,sum=0;
	
	while(in[i]!='\0'){
		sum++;
		i++;
	}
	
	
	char output[sum];
	for(i=0;i<sum;i++){
		output[i]=in[sum-1-i];
	}
	for(i=0;i<=sum;i++){
		printf("%c",output[i]);
	}
	
	
	return 0;
}
