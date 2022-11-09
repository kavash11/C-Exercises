#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

void removeDups(int* in, int size){
    int i=0, j=0, k=0, temp=0;
    for(i=0;i<(size);i++) {
        for(j=i+1;j<(size);j++) {
            if (in[i]==in[j]) {
                in[j] = 0;
            }
        }
    }
    for(i=0;i<(size);i++) {
        for(j=i+1;j<(size);j++) {
            if (in[i]==0) {
                temp = in[i];
                in[i] = in[j];
                in[j] = temp;
            }
        }

    }
}



int main () {
    int in[] = {1,7,5,5,5,2,9,9,11,11,11,1,5,9};
    removeDups(in,14);
    for (int i=0;i<14;i++) {
        printf("%d",in[i]);
    }
    return 0;
}
