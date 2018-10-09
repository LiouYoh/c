#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
 
int main(){
    char *test = "the answer is 33.23mm + 25mm";
    char *endPtr = test;
    long sum = 0;
     
    while (*test) {
        sum += strtol(test, &endPtr, 0);
        test = endPtr;
         
        while (!isdigit(*test) && *test) {
            test++;
        }
    }
     
    printf("the answer is %d mm\n", sum);
 
    return 0;
}
