#include <stdio.h>

int main() {
    int num;
    scanf("%d",&num);
    int temp;

    int array[num][num];
    
    int i = 0;
    for  (int size = 0; size < num; size++) {
        char newline = '\0';
        int j = 0;
        while (newline != '\n') {
            int flag = scanf("%d%c",&temp,&newline);
            if (flag == EOF) {
                break;
            }
            array[i][j] = temp;
            j++;
        }
        i++;
        // printf("\b\n");
    }

    // check for duplicates
    int dupArray[__INT16_MAX__] = {0};
    // for (int i = 0; i < 100; i++) {
    //     printf("%d ", dupArray[i]);
    // }
    // printf("\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (dupArray[array[i][j]] == 0) {
                dupArray[array[i][j]] = array[i][j];
            } else {
                printf("Invalid data: missing or repeated number\n");
                return 0;
            }
        }
    }

    for (int i = 0; i< num; i++) {
        int sum = 0;
        for (int j = 0; j < num; j++) {
            sum += array[i][j];
        }
        if (sum != num*(num*num+1)/2) {
            printf("Not a Magic Square\n");
            return 0;
        }
    }

    for (int j = 0; i< num; i++) {
        int sum = 0;
        for (int i = 0; j < num; j++) {
            sum += array[i][j];
        }
        if (sum != num*(num*num+1)/2) {
            printf("Not a Magic Square\n");
            return 0;
        }
    }

    int diagSum = 0;
    for (int i =0; i < num;) {
        for (int j = 0; j < num;) {
            diagSum += array[i][j];
            i++;
            j++;
        }
        if (diagSum != num*(num*num+1)/2) {
            printf("Not a Magic Square\n");
            return 0;
        }
    }

    int offdiagSum = 0;
    for (int i =0; i < num;) {
        for (int j = num-1; j >= 0;) {
            offdiagSum += array[i][j];
            i++;
            j--;
        }
        if (offdiagSum != num*(num*num+1)/2) {
            printf("Not a Magic Square\n");
            return 0;
        }
    }



   
    printf("Magic Square\n");
    return 0;
    
}