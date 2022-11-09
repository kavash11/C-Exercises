#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

float fkgrade(char str[]) {
    int syllables = 0;
    int words = 0;
    int sentences = 0;
    int size = strlen(str); 
    int i=0;
    int j=0;
    float difficulty=0;
    while (str[j]!='\0') {
        if (str[j]=='!' || str[j]=='.' || str[j]=='?') {
            sentences++;
        }
        j++;
    }
    char delimiter[] = " \t\r\n\v\f";
    char* pointer = strtok(str,delimiter);


    while (pointer!=NULL) {
        int alpha = 0;
        for (int i=0; i<strlen(pointer); i++) {
            if (pointer[i]=='a' || pointer[i]=='e' || pointer[i]=='i' || pointer[i]=='o' || pointer[i]=='u' || pointer[i]=='A' || pointer[i]=='E' || pointer[i]=='I' || pointer[i]=='O' || pointer[i]=='U') {
                syllables++;
                if (pointer[i-1]=='a' || pointer[i-1]=='e' || pointer[i-1]=='i' || pointer[i-1]=='o' || pointer[i-1]=='u' || pointer[i-1]=='A' || pointer[i-1]=='E' || pointer[i-1]=='I' || pointer[i-1]=='O' || pointer[i-1]=='U') {
                    syllables--;
                }
            }
            if(isalpha(pointer[i])) {
                alpha++;
            }
        }
        if (alpha!=0) {
            words++;
        }
        pointer = strtok(NULL," ");
    }
    printf("%d\n", sentences);
    printf("%d\n", words);
    printf("%d\n", syllables);        
    if (sentences==0 || words==0) {
        difficulty=0;
    }
    else {
        difficulty = (0.39*words/sentences) + (11.8*syllables/words) - 15.59;
    }
    return difficulty;
}


int main() {
    char plato[] = "He who is the real tyrant, whatever men may think, is the real slave, and is obliged to practise the greatest adulation and servility, and to be the flatterer of the vilest of mankind.  He has desires which he is utterly unable to satisfy, and has more wants than any one, and is truly poor, if you know how to inspect the whole soul of him: all his life long he is beset with fear and is full of convulsions and distractions, even as the State which he resembles: and surely the resemblance holds?";

    char aurelius[] = "Nothing pertains to human beings except what defines us as human.  No other things can be demanded of us.  They aren't proper to human nature, nor is it incomplete without them.  It follows that they are not our goal, or what helps us reach it -- the good.  If any of them were proper to us, it would be improper to disdain or resist it.  If the things themselves were good, it could hardly be good to give them up.  But in reality, the more we deny ourselves such things (and things like them) -- or are deprived of them involuntarily, even -- the better we become.";

    char descartes[] = "I suppose, accordingly, that all the things which I see are false (fictitious); I believe that none of those objects which my fallacious memory represents ever existed; I suppose that I possess no senses; I believe that body, figure, extension, motion, and place are merely fictions of my mind.  What is there, then, that can be esteemed true?  Perhaps this only, that there is absolutely nothing certain.";
    
    char empty[] = "ouiijaeohello";

    //fkgrade(empty);
    printf("Plato...\nexpected sentences = 2\ne  xpected words = 94\n  expected syllables = 135\n");
    float out = fkgrade(plato);
    printf("> Reading Level = %f\n", out);
    printf("Marcus Aurelius...\n  expected sentences = 7\n   expected words = 104\n    expected syllables = 151\n");
    out = fkgrade(aurelius);
    printf("> Reading Level = %f\n", out);
    printf("Rene Descartes...\n  expected sentences = 3\n   expected words = 67\n    expected syllables = 111\n");
    out = fkgrade(descartes);
    printf("> Reading Level = %f\n", out);
    
    out = fkgrade(empty);
    printf("> Reading Level = %f\n", out);
}