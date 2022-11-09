#include <stdio.h>
#include <assert.h>
#include <math.h>


int insertionsort(int* x, int size) {
    int count = 0;
    for(int i=1;i<(size);i++) {
        int temp = x[i];
        int j = i-1;
        while((temp<x[j]) && j>=0) {
            x[j+1] = x[j];
            j--;
            count++;
        }
        if(temp>x[j]&& j>=0) {
            count++;
        }
        x[j+1]=temp;
    }
    return (count);
}
    
int main () {
    int x[] = {100};
    int size = sizeof(x)/sizeof(int);
    printf("list %d",(insertionsort(x,size)));
    return 0;
}

