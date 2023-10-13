#include <stdio.h>
int main(){
    int array[] = {1,2,3,4,5};
    int array2[5];
    int i,z=0;
    int total = sizeof(array)/sizeof(array[0]);
    int x = total-1;
    
    while(i<total){
        array2[x]=array[i];
        i++;
        x--;
    }
    for(int z = 0; z < 5; ++z) {
        printf("%d",array2[z]);
    }
    return 0;
}