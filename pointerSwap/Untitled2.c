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

//�g�Ƶ{���N�ݸ̭����ŧi�N�n�F
//���O�n�s�W�h�N�O�o�n�t�XPointer�Mreference 
