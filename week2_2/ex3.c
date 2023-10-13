#include <stdio.h>
int main(){
    int array[] = {1,8,3,12,5};
    int max=0;
    for(int i=0; i<5; ++i){
        if(array[i]>max){
            printf("%d is greater than %d\n",array[i],max);
            max=array[i];
            printf("max: %d\n",max);
        }
    }
    printf("max: %d\n",max);
    return 0;
}