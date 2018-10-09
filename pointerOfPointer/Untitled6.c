#include <stdio.h>

int main(){
	
	
	int x=50;
	int *p;
	int **pp;
	p=&x;
	pp=&p;
	printf("&x=%p\n",&x);
//	printf("*p=%d\n",*p);
	printf("p=%p\n",p);
	printf("&p=%p\n",&p);
	
	printf("*pp=%p\n",*pp);
	printf("pp=%p\n",pp);
	return 0;
}
