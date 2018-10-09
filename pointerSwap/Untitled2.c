#include <stdio.h>
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int a=10,b=11;

/*	 
	printf("&a=%p\n",&a);
	printf("&b=%p\n",&b);

	swap(a,b);
	printf("\n");
	printf("&a=%p\n",&a);
	printf("&b=%p\n",&b);
*/
	printf("a=%d,b=%d\n",a,b);
	swap(&a,&b);
	printf("a=%d,b=%d\n",a,b);
	return 0;
}

//寫副程式就看裡面的宣告就好了
//但是要連上去就記得要配合Pointer和reference 
