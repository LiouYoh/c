#include <iostream>
using namespace std;

template <class T> class Show {
    public:
        Show( T a) {
           cout<<a<<endl;
            
        } 
        
        
};

int main(int argc, char** argv) {
	
	Show <double> show(1.1);
	
	return 0;
}
