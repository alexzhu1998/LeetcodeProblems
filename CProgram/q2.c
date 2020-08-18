#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int input(char *s,int length);

int main()
{
    char *buffer;
    size_t bufsize = 5;
    // size_t characters;
    char** charArray = NULL;
    int size = 0;

    buffer = malloc(bufsize * sizeof(char));
    while(1){
        int tmp = scanf("%s",buffer);
        if (tmp == EOF) {
            break;
        }
        // printf("%s",buffer);
        char temp[bufsize];
        strcpy(temp,buffer);
        charArray = realloc(charArray,(size+1)*(sizeof(char*)));
        charArray[size] = malloc(bufsize*sizeof(char));
        
        strcpy(charArray[size++],temp);

    }

    free(buffer);
    for (int i =0; i < size; i++) {

        
        char hour[3];
        strncpy(hour,charArray[i],2);
        hour[0] = charArray[i][0];
        hour[1] = charArray[i][1];
        hour[2]= '\0';
        // hour[1] = charArray[i][1];
        char minutes[3];
        minutes[0] = charArray[i][2];
        minutes[1] = charArray[i][3];
        minutes[2] = '\0';
        int d = atoi(hour);
        if (d > 12 && d <=23) {
            int newHour = d-12;
            // printf
            if (newHour < 10) {
                printf("0%d:%s PM\n",newHour,minutes);
            } else {
                printf("%d:%s PM\n",newHour,minutes);
            }
            
        } else {
            if (d == 12) {
                printf("%s:%s PM\n",hour,minutes);
            } else {
                printf("%s:%s AM\n",hour,minutes);
            }
            
        }
    }

    for (int i =0; i < size ; i++) {
        free(charArray[i]);
    }
    free(charArray);

    return(0);
}