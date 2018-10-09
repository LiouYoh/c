#include <stdio.h> 
#include <string.h>
int main(){
	char s1[20]="happy";
	char s2[]="new year";
	char s3[40]="ddd";//這便記得要初始化 
	//printf("strcat(s1,s2)=%s\n",strcat(s1,s2));
	strncat(s3,s1,6);
	puts(s3);
	
	return 0;
}
