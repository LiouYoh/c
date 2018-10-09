#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char** argv) {
	
	int a,b,c;
	double r1,r2;
	
	
		
		cin>>a>>b>>c;
	
		if(((b*b)-(4*a*c))==0){
			r1=(-b+sqrt(b*b-4*a*c))/(2*a);
			cout<<"two same root x="<<r1<<endl;
		}
		else if ((b*b-4*a*c)<0){
			cout<<"no real root"<<endl;
		}
		else {
			r1=(-b+sqrt(b*b-4*c*a))/(2*a);
			r2=(-b-sqrt(b*b-4*c*a))/(2*a);
			cout<<"two different roots x1="<<r1<<" , x2="<<r2<<endl;
		}
	
	
	return 0;
}
