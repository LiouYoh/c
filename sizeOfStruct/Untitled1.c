#include <stdio.h>
struct student {
	int id;
	char name[10];
};
int main(){
//	struct student{
//		int id;
//		char name[10];
//	};
//	struct student s1;
//	printf("%d\n",sizeof(s1));

	struct student *p;
	struct student s1;
	p=&s1;
	s1.id=10;
	//s1.name=" ";
	
	printf("%p\n",p);
	printf("%d\n",(*p).id);
	
	return 0;
} 
