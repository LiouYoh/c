#include <stdio.h>
int main(){
	
	
	//char *a={'a','b'};			//�n��char�Mstring���ŧi�O�@�˪��覡 
	char *a[2]={'a','b'};
	printf("%c\n",*a);
	printf("%c\n",*a+1);
	
//	int *b={1,2};				���~�� 
//	printf("%d\n",b);
//	printf("%d",b+1);

	char s[5]="cool";
//	char a="cool"�o�ˤl�O������ 
	char *b="cool";
	printf("%s\n",s);
	printf("%s",b); 

	return 0;
} 
