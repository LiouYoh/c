#include <stdio.h>
int main(){
	int a=10;
	short int *p;
	int *q;
	float *r;
	double *s;
	p=(short int)&a;
	
	printf("%p\n",p);

	p++;
	printf("%p\n",p);
	p++;
	printf("%p\n",p);
	
	return 0;
}
