#include <stdio.h>
#include <stdbool.h>

int main(){
    bool c = true;
    while(c){
        int v;
        printf("value?\n");
        scanf("%d",&v);

        if(v>=0&&v<=100){printf("value in range.\n");}
        else if(v==-1){c=false;}
        else{printf("value not in range.\n");}
    }
    printf("termination.\n");
    return 0;
}