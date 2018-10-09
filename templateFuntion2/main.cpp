#include <iostream>
using namespace std;

template <class T, class U>T GetMin (T a, U b) {
    return (a<b?a:b);
}
int main () {
        int j=6;
        double l=2.3;
		double i;
		//i = GetMin<int,long> (j,l);
		i = GetMin (l,j);
        cout<<i<<endl;
        return 0;
}
