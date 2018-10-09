#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int add1, add2, carry, count;
  while( scanf( "%d%d", &add1, &add2 ) != EOF && (add1 || add2) ){
    carry = 0;
    count = 0;
    while( add1 || add2 ){
      carry = add1%10 + add2%10 + carry;
      carry /= 10;
      add1 /= 10;
      add2 /= 10;
      if( carry )
        count++;
    }
    if( count == 1 )
      printf( "1 carry operation.\n" );
    else if( count > 1 )
      printf( "%d carry operations.\n", count );
    else
      printf( "No carry operation.\n" );
  }
  return 0;
}
