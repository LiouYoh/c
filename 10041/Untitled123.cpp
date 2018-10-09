/*******************************************************/
/* UVa 10041 Vito's Family                             */
/* Author: LanyiKnight [at] knightzone.org             */
/* Version: 2012/03/18                                 */
/*******************************************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
  int testcase;
  int r, s[505];
  int house, d;
  while( scanf( "%d", &testcase ) != EOF ){
    for( int i = 0 ; i < testcase ; i++ ){
      scanf( "%d", &r );
      for( int j = 0 ; j < r ; j++ )
        scanf( "%d", &s[j] );
      sort( s, s+r );

      d = 0;
      house = s[r/2];
      for( int j = 0 ; j < r ; j++ )
        d += abs( house-s[j] );
      printf( "%d\n", d );
    }
  }
  return 0;
}
