#include <stdio.h>
typedef struct student *pr;
struct student{
	int number;
	char *name;
};
int main(){
	pr s1;
	struct student kk;
	s1=&kk;
	s1->name="cool";
	printf("%s\n",kk.name);
}
