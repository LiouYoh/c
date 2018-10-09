#include <stdio.h>
int main(){
	
	int array[]={2,4,6,8,10};
	int *parray;
	//parray=array;
	parray=&array[0];
	int s=*(array+3);
	printf("%d\n",*parray); 
	return 0;
}
