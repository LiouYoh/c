#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char N[1005];
    while( gets(N) && !(N[0] == '0') )
    {
        int odd = 0, even = 0, i;
        int N_length = strlen(N);
        for( i = 0 ; i < N_length ; i++ )
            if( i % 2 )
                odd += N[i] - '0';
            else
                even += N[i] - '0';
        if( !(abs(odd - even) % 11 ) )
            printf( "%s is a multiple of 11.\n", N );
        else
            printf( "%s is not a multiple of 11.\n", N );
        
    }
    return 0;
}
