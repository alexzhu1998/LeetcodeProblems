#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 4

int main()
{
    char *buffer;
    size_t bufsize = SIZE + 1;
    char** tfhstring = NULL;
    int size = 0;

    buffer = malloc(bufsize * sizeof(char));
    while(scanf("%s",buffer)==1){
        tfhstring = realloc(tfhstring,(size+1)*(sizeof(char*)));
        tfhstring[size] = malloc(bufsize*sizeof(char));
        strcpy(tfhstring[size],buffer);
        size++;
    }

    free(buffer);
    // loop through the 24hour clock 
    for (int i =0; i < size; i++) {
        char h[3],m[3];
        // extract hours and minutes, deal with them separately
        for (int j =0; j < 3; j++) {
            if (j == 2){
                h[j] = '\0';
                m[j] = '\0';
            } else {
                h[j] = tfhstring[i][j];
                m[j] = tfhstring[i][j+2];
            }
        }
        int hour24 = atoi(h);
        if (hour24 > 12 && hour24 < 24) {
            int newHour = hour24-12;
            // print them out after manipulation
            if (newHour < 10) {
                printf("0%d:%s PM\n",newHour,m);
            } else {
                printf("%d:%s PM\n",newHour,m);
            }
            
        } else {
            if (hour24 == 12) {
                printf("%s:%s PM\n",h,m);
            } else {
                printf("%s:%s AM\n",h,m);
            }
            
        }
        free(tfhstring[i]);
    }

    free(tfhstring);

    return 0;
}