#include <stdio.h> 

int main(){
	typedef char *str;
	str k= "bool";
	
	typedef int *s;
	int a=10;
	s ll=&a;
	printf("&ll\n%p\n",ll);
	printf("&a\n%p\n",&a);
	return 0;
	
}
