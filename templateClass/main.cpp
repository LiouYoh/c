#include <iostream>
using namespace std;
template <class T> class Demo {
    public:
        Demo( T a, T b) {
            this->a = a;
            this->b = b;
        } 
        
        T do_something() {
            return a + b;
        }
    	//那一個T為回傳的型別 
    private:
        T a;
        T b;
};

int main(void) {
    Demo<int> d1(20, 25);
    cout << d1.do_something() <<endl;
    Demo<double> d2(5.2, 3.95);
    cout << d2.do_something() << endl;
    Demo<char> d3('1', '2');
    cout << d3.do_something() << endl;
    
    return 0;
}
