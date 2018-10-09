#include <stdio.h>
void fun(int * x, int * y) {
    *x = 5;
    *y = 5;
}
int main() {
    int x = 0;
    int y = 0;
    fun(&x, &y);
    printf("%d %d\n", x, y);
    return 0 ;
}
