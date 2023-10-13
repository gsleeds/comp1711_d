#include <stdio.h>

int main(){
    float a,b,c;

    printf("What is side a?: ");
    scanf("%f",&a);
    printf("What is side b?: ");
    scanf("%f",&b);

    c=a*b;
    printf("The area is: %f^2\n\n",c);
    return 0;
}