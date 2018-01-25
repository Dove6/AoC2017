#include <stdio.h>
#include <stdbool.h>

#define sarr 16

int main()
{
    printf("Goodbye, world.\n");

    short array[sarr] = {0};
    unsigned char crc[65536][sarr] = {0};
    unsigned long long step;
    bool stop = false;

    for (short i = 0; i < sarr; i++) {
        scanf("%hd", &array[i]);
    }
    for (step = 0; ; step++) {
        short max = 0;
        for (short i = 0; i < sarr; i++) {
            if (array[i] > array[max]) max = i;
        }
        for (short i = 0; i < sarr; i++) {
            crc[step][i] = (unsigned char)array[i];
        }
        //            printf("\n%I64u", step);

        if (step) {
            for (short i = 0; i < step; i++) {
                for (short j = 0; j < sarr; j++) {
                    stop = true;
                    if (crc[step][j] != crc[i][j]) {
                        stop = false;
                        break;
                    }
                }
                if (stop) {
                    printf("\n%I64u", step);
                    return 0;
                }
            }
        }

        short buffer = array[max];
        array[max] = 0;
        max++;
        if (buffer > 200) return -1;

        for (; buffer; max++) {
            if (max > sarr) max = 0;
            array[max]++;
            buffer--;
        }
    }
    return 0;
}
