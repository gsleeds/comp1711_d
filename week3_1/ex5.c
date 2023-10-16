#include <stdio.h>
int main(){
    int a;
    printf("0-4. pick.\n");
    scanf("%d",&a);
    switch (a){
        case 0: printf("option 1...\n");
        break;
        case 1: printf("option 2...\n");
        break;
        case 2: printf("option 3...\n");
        break;
        case 3: printf("option 4...\n");
        break;
        case 4: printf("option 5...\n");
        break;
        default: printf("error.\n");
    }
    return 0;
}