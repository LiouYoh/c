#include <stdio.h>
typedef struct student *bbb;
struct student {
	int number;
};
int main(){
	bbb s1;
	struct student s2;
	s2.number=11;
	s1=&s2; 
	printf("%d\n",s1->number);
	printf("%d\n",(*s1).number);
}
