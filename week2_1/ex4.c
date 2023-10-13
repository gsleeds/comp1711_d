#include <stdio.h>
int main(){
    float pi = 3.14159;
    float r;
    float a;
 
    printf("Radius?: ");
    scanf("%f",&r);
    a=pi*r*r;
    printf("Area: %f^2\n",a);

    return 0;
}