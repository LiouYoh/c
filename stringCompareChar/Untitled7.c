#include <stdio.h>
#include <string.h>

int main(){
	
	const char *string1="the value is 3.14159";
	const char *string2="124567890";
	printf("%d\n",strcspn(string1,string2));
}
