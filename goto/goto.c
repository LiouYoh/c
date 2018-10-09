#include <stdio.h>

int main(int argc, char** argv) {

	int a=11,b=10,c;
	if(a>b)
		goto IF;
	c=b;
	goto EXIT;
IF:
	c=a;
EXIT:
	printf("%d",c);

	system("pause");
	return 0;
}