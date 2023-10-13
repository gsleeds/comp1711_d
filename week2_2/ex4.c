#include <stdio.h>
int main(){
    int array[] = {4,3,5,1,2};
    int array2[] = {0,4,3,5}
    int t;
    t=array2[0];
    array2[0]=array[4];
    array2[4]=t;

    for(int i=0; i<3; ++i){
        array2[i+1]=array[i];
    }
    for(int z=0; z<5; ++z){
        
    }
}