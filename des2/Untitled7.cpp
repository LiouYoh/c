#include <sstream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
        string text = "I will pass network security";
        stringstream ss(text);
        string sub_str;
        while(getline(ss,sub_str,' ')){
        	cout << sub_str << endl;
		} 
            
        return 0;
}
