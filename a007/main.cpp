#include <iostream>
using namespace std;
int isPrime(int a){
	for(int i=2;i<a;i++){
		if(a/i==0)
			return 0;
	}
	return 1;
	
}
int main(int argc, char** argv) {
	int a;
	while(cin>>a){
		if(isPrime(a)==0)
			cout<<"非質數"<<endl;
		else{
			cout<<"質數"<<endl; 
		} 
		
	}
	return 0;
}
