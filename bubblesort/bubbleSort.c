#include <stdio.h>
void bubble(int *arr,int len){
	int i,k;
	for(i=0;i<len;i++){
		for(k=0;k<len-i;k++){
			if(arr[k]>arr[k+1]){
				int temp;
				temp=arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=temp;
			} 
		}
	}	
}
int main(){
	int array[]={1,1,22,4,333,4,5,98};
	int l;
	bubble(array,8);
	for(l=0;l<=8;l++){
		printf("%d  ",array[l]);
	}
	return 0;
}
