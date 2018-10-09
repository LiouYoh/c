#include <stdio.h>
void count();
int main(){
	int i;
	for (i = 1; i <= 10; i++)
		count();
	return 0;
}
void count(){
	static cnt = 0;
	cnt++;
	printf(" It have been called %d",cnt,"times\n");
}
 
