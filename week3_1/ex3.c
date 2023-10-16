#include <stdio.h>
int main(){
    int mark = 45;

    if(mark>49){
        if(mark>69){
            printf("distinction.\n");
            return 0;
        }
        printf("pass.\n");
        return 0;
    }
    printf("fail.\n");
    return 0;
}