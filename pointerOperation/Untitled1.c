#include <stdio.h>
int main(){
	
	int a;
	short int *p;
	int *q;
	float *r;
	double *s;
	p=&a;
	q=&a;
	r=&a;
	s=&a;
	printf("p=%p\n",p);
	printf("q=%p\n",q);
	printf("r=%p\n",r);
	printf("s=%p\n",s);
	printf("============\n");
	p=p+1;
	q=q+1;
	r=r+1;
	s=s+1;
	printf("p=%p\n",p);
	printf("q=%p\n",q);
	printf("r=%p\n",r);
	printf("s=%p\n",s);
	return 0;
} 
