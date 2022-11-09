#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void reverse(char* str) {
    int length = strlen(str);
    char ch; 
    char *p1 =str; 
    char *p2=str;
    int i=0;
    for(i=0;i<(length-1);i++) {
        p2++;
    }
    for(i=0; i<(length/2);i++) {
        ch = *p2;
        *p2 = *p1;
        *p1 = ch;
        p1++;
        p2--;
    }
}


int count(char* str) {
    int count = 0;
    while(*str != '\0') {
        if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' ||*str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {
            count ++;
        }
        str++; 
    }
    return count;
}



int main () {
    char str[] = "lamb";
    printf("vowels %d",(count(str)));
    reverse(str);
    return 0;
}
