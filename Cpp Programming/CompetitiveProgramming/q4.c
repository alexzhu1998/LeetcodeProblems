
#include <stdio.h>
int main()
{
    int i = 7;
    int *ip = &i;
    printf("%d\n", *ip);
    *ip = *ip * 6;
    printf("%d\n", i);
    i = 24;
    printf("%d\n", *ip);
}