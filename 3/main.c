#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long chksum = 0;
    int buffer, lmin[16] = {0}, lmax[16] = {0};
    printf("Hello world! %c\n", 48);
    short i, j;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            scanf("%d", &buffer);
            if (!j) {
                lmin[i] = buffer;
                lmax[i] = buffer;
            } else {
                if (lmin[i] > buffer) lmin[i] = buffer;
                if (lmax[i] < buffer) lmax[i] = buffer;
            }
        }
        chksum += lmax[i] - lmin[i];
    }
    printf("%I64d", chksum);
    return 0;
}
