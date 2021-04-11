#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(0));
    int a = rand()%12+1;
    srand(time(0)+1);
    int b = rand()%12+1;
    int ans;
    while (1) {
        printf("What is %d x %d? ", a,b);
        int tmp = scanf("%d", &ans);
        if (tmp == EOF) {
            break;
        }
        if (a*b == ans) {
            printf("Correct!\n");
            return 0;
        } else {
            printf("Incorrect - try again\n");
        }
    }
    

    return 0;
}