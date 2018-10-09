#include <stdio.h>
typedef struct student stu;
struct student {
	int number;
	stu *p;
};
int main(){
	stu s1;
	stu s2;
	s2.number=11;
	s1.p=&s2;
	(*(s1.p)).number=10;
	printf("%d\n",(*(s1.p)).number);
	printf("%d\n",(s1.p)->number);
}
