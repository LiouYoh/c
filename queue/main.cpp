// test formula based queue class

#include <iostream>
#include "queue.h"
using namespace std;
int main()
{
   Queue<int> Q(3);
   int x;
   Q.Add(1).Add(2).Add(3).Add(4);
        cout << "No queue add failed" << endl;
  
   cout << "Queue is now 123" << endl;
   Q.Delete(x);
   cout << "Deleted " << x << endl;
   cout << Q.First() << " is at front" << endl;
   cout << Q.Last() << " is at end" << endl;
   
      Q.Delete(x);
      cout << "Deleted " << x << endl;
      Q.Delete(x);
      cout << "Deleted " << x << endl;
      Q.Delete(x);
      cout << "Deleted " << x << endl;
      cout << "No queue delete failed " << endl;
     
   
      return 0;
}

