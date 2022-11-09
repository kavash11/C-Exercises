#include <stdio.h>
#include <assert.h>
#include <math.h>

int binsearch(int* x, int y, int size) {
    int count=0;
    int a = 0;
    int b = size-1;
    while(a<=b) {
        int m = ((a+b)/2);
        count++;
        if(x[m]==y || x[a]==y || x[b]==y) {
            return count;
        }   
        if (x[m]<y) {
            a=m+1;
        }
        else if (x[m]>y) {
            b=m-1;
        }
    } 
    return -1;
}

int main () {
	int x[] = {22, 25, 37, 42, 56, 56, 60, 69, 73, 75, 94, 109, 129, 132, 134, 148, 160, 168, 168, 169, 172,177, 235, 238, 240, 263, 272, 274, 291, 303, 305, 309, 310, 311, 312, 317, 327, 332, 336, 341, 347,358, 359, 373, 387, 389, 392, 404, 425, 428, 431, 438, 444, 481, 490, 491, 496, 503, 506, 511, 521,554, 554, 555, 559, 565, 572, 580, 587, 587, 617, 642, 643, 660, 681, 684, 697, 712, 726, 726, 739,757, 761, 775, 790, 826, 828, 832, 853, 865, 886, 886, 888, 901, 918, 937, 945, 952, 971, 974};
	int y=506;
	int size=sizeof(x)/sizeof(int);
    printf("Total examinations %d", binsearch(x,y,size));
    return 0;
}


