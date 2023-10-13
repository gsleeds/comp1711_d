#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    char d = CHAR_MAX;

    printf("\nint: %d\n\n",a);
    printf("float: %f\n\n",b);
    printf("double: %f\n\n",c);
    printf("char: %d\n\n",d);

    return 0;
}