#include <stdio.h>
int main(){
	
	int i;
	char *week[2]={"sunday","monday"};
	for(i=0;i<2;i++){
		printf("Week[%d]=%s\n",i,*(week+i));
	}
	return 0;
}
