#include <stdio.h>
int main(){
    int a = 1;
    int b = 2;
    int c;

    c=b;
    b=a;
    a=c;

    printf("%d\n",a);
    printf("%d\n",b);

    return 0;
}