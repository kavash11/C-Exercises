#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size) {
    int count = 0;
    for(int j=0;j<(size-1);j++) {
        for(int i=0;i<(size-j-1);i++) {
            if(x[i]>x[i+1]) {
                count++;
                int temp = x[i];
                x[i] = x[i+1];
                x[i+1] = temp;
            }
        }
    }
    return count;
}

int main () {
    int x[] = {100};
    int size = 1;
    printf("list %d",(bubblesort(x,size)));
    return 0;
}