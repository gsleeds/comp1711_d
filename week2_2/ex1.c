#include <stdio.h>
int main(){
    int array[] = {1,2,3,4,5};
    int length = sizeof(array)/sizeof(array[0]);
    int i=0;
    int total=0;
    while(i<length)
    {
        total = total+array[i];
        i++;
    }
    printf("%d\n",total);
    return 0;
}