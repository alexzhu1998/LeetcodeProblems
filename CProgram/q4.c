#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
    // printf("%s\n",argv[1]);
    
    size_t length = strlen(argv[1]);
    int sum = 0;
    for (int i = 0; i < length;) {
        if (argv[1][i] == 'I') {
            if (argv[1][i+1] == 'V') {
                sum+=4;
                i+=2;
            } else if (argv[1][i+1] == 'X') {
                sum+=9;
                i+=2;
            } else {
                sum+=1;
                i++;
            }
        } else if (argv[1][i] == 'V') {
            sum+=5;
            i++;
        } else if (argv[1][i] == 'X') {
            if (argv[1][i+1] == 'L') {
                sum+=40;
                i+=2;
            } else if (argv[1][i+1] == 'C') {
                sum+=90;
                i+=2;
            } else {
                sum+=10;
                i++;
            }
        } else if (argv[1][i] == 'L') {
            sum += 50;
            i++;
        } else if (argv[1][i] == 'C') {
            if (argv[1][i+1] == 'D') {
                sum+=400;
                i+=2;
            } else if (argv[1][i+1] == 'M') {
                sum+=900;
                i+=2;
            } else {
                sum+=100;
                i++;
            }
        } else if (argv[1][i] == 'D') {
            sum += 500;
            i++;
        } else if (argv[1][i] == 'M') {
            sum+=1000;
            i++;
        }
    }

    printf("%d\n", sum);
    return 0;
}