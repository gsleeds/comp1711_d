#include <stdio.h>

int main(){
    int i;
    
    printf("value?: ");
    scanf("%d",&i);

    if (i%2==0){
        printf("even\n");
    }
    else{
        printf("odd\n");
    }

    return 0;
}