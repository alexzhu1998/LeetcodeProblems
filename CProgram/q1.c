#include <stdio.h>
#include <stdlib.h>


int main() {
    // int num;
    int size = 0;
    int *num = NULL;
    int val;
    while(scanf("%d", &val)==1) {
        // printf("%d", num);
        num = realloc(num,(size+1)*sizeof(int));
        
        num[size] = val;
        size++;
        
    }
    // size 
    if (size == 0) return 0;
    // sort
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (num[i]> num[j]) {
                int a = num[i];
                num[i] = num[j];
                num[j] = a;
            }
        }
    }
    // 
    int *res = NULL;
    int newsize = 0;
    // res[0] = num[0];
    // res = realloc(res,(newsize+1)*sizeof(int));
    // newsize++;
    int i = 0;
    for (i = 0; i < size-1; i++) {
        if (num[i] != num[i+1]) {
            res = realloc(res,(newsize+1)*sizeof(int));
            res[newsize] = num[i];
            newsize++;
        }
    }
    if (num[i] != num[i-1]) {
        res = realloc(res,(newsize+1)*sizeof(int));
        res[newsize] = num[i];
        newsize++;
    };

    printf("[");
    int j =0;
    for (j = 0 ; j< newsize-1; j++) {
        printf("%d ",res[j]);
    }
    printf("%d]\n\n",res[j]);
    free(num);
    free(res);
    return 0;
    // int i,j,number[n];
}