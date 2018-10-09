#include <stdio.h>
#include <string.h>
int main(){
	
	char x[]="happy birthday to you ";
	char y[25];
	char z[10];
	printf("x=%s\n",x);
	printf("y=%s\n",strcpy(y,x));
	strncpy(z,x,9);//後面不會自動綁你補\0
	z[10]='\0';
	printf("%s\n",z);
	
	return 0;
} 
