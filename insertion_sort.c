#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int insertionsort(int* x, int size, int (*compare)(int a, int b)) {
    int count = 0;
    void swap (int* num1, int* num2);
    for(int i=1;i<(size);i++) {
        int temp = x[i];
        int j = i-1;
        while(((*compare)(x[j],temp) == true && j>=0)) {
            swap(&x[j],&x[j+1]);
            j--;
            count++;
        }
        if((*compare)(x[j],temp) == false && j>=0) {
            count++;
        }    
    }
    return (count);
}

int ascending (int a, int b) {
    if (a<=b) {
        return false;
    }
    else {
        return true;
    }
}
int descending (int a, int b) {
    if (a>=b) {
        return false;
    }
    else {
        return true;
    }
}
void swap (int* num1, int* num2) {
        int temp=0;
        temp = *num1;
        *num1 = *num2;
        *num2 = temp;
}


int main () {
    int x[] = {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    printf("%d",insertionsort(x,14,ascending));
    /*for (int i=0;i<14;i++) {
        printf("%d\n",x[i]);
    } */   
    return 0;
}
