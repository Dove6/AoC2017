#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long chksum = 0;
    int lcurr, larr[16][16] = {0};
    printf("Hello world! %c\n", 48);
    short i, j, k;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            scanf("%d", larr[i]+j);
        }
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            lcurr = larr[i][j];
            for (k = 0; k < 16; k++) {
                if (k != j && lcurr) {
                    if (!(larr[i][k]%lcurr)) chksum += larr[i][k] / lcurr;
                }
            }
        }
    }
    printf("%I64d", chksum);
    return 0;
}
