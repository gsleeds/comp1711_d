#include <stdio.h>
int main(){
    int num = 0;
    
    if(num==0){
        printf("zero\n");
    }
    else if(num%2==0){
        printf("even\n");
    }
    else{
        printf("odd\n");
    }

    return 0;
}