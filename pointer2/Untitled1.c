#include <stdio.h>
int main(){
	
	
	//char *a={'a','b'};			//要用char和string的宣告是一樣的方式 
	char *a[2]={'a','b'};
	printf("%c\n",*a);
	printf("%c\n",*a+1);
	
//	int *b={1,2};				錯誤的 
//	printf("%d\n",b);
//	printf("%d",b+1);

	char s[5]="cool";
//	char a="cool"這樣子是錯的喔 
	char *b="cool";
	printf("%s\n",s);
	printf("%s",b); 

	return 0;
} 
