// test formula based stack class

#include <iostream>
#include "stack.h"
using namespace std;
int main()
{
   int x;
   Stack<int> S(10);
   S.Add(1).Add(2).Add(3).Add(4);
   
   cout << "Stack should be 123" << endl;
   cout << "Stack top is " << S.Top() << endl;
  
      S.Delete(x);
      cout << "Deleted " << x << endl;
      S.Delete(x);
      cout << "Deleted " << x << endl;
      S.Delete(x);
      cout << "Deleted " << x << endl;
      S.Delete(x);
      cout << "Deleted " << x << endl;
      
  
   system("pause");
   return 0;
}

