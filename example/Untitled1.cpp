#include <stdio.h>

int main(){
	char op[15];
	int times;
	scanf("%d",&times);
	for(int i=0;i<times;i++){
		int temp1,temp2;
		scanf("%d%d",&temp1,&temp2);
		if(temp1>temp2){
			op[i]='>';
		}
		else if(temp1<temp2){
			op[i]='<';
		}
		else
			op[i]='=';
	}
	for(int j=0;j<times;j++){
		printf("%d\n",op[j]);
	} 
	
}
