#include <stdio.h>
int main(){
	
	int temp[5];
	int i;
//	for(i=0;i<5;i++){
//		printf("%d=",i);
//		scanf("%d",&temp[i]);
//		
//	}
	for(i=0;i<5;i++){
		printf("%d=",i);
		scanf("%d",temp+i);
	}
	printf("\n");
	for(i=0;i<5;i++){
		printf("%d\n",*(temp+i));
		//printf("%d\n",temp[i]);
	}
	
	return 0;
}
