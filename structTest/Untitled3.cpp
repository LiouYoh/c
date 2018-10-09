#include <stdio.h>
#include <iostream>
using namespace std;
struct student{
	int number;
	char *name;
};
int main(){
	
	typedef struct student student;
	student s;
	s.name="Harry";
	cout<<s<<endl;
	cout<<&s<<endl;
}
