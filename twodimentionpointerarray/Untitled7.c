#include <stdio.h>

char *strcopy(char *s,char *t){
	char *ptr;
	ptr=t;
	while((*t=*s)!='\0'){
		s++;
		t++;
	}
	return ptr;
}
int main(){
	char *list1="tatung university";
	char list2[60];
	
	printf("list1=%s\n",list1);
	printf("list2=%s\n",strcopy(list1,list2));
	
	return 0;
}
