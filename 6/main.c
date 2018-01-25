#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define msize 21

int main()
{
    printf("Hello world!\n");
    int memory[msize][msize] = {0}, i = (msize - 1) / 2, j = i, side = 3, sw_side = 1, side_add = 1;
    short tic_side = 1;
    memory[i][j] = 1;
    do {
        memory[i][j] += memory[i-1][j-1];
        memory[i][j] += memory[i-1][j];
        memory[i][j] += memory[i-1][j+1];
        memory[i][j] += memory[i][j-1];
        memory[i][j] += memory[i][j+1];
        memory[i][j] += memory[i+1][j-1];
        memory[i][j] += memory[i+1][j];
        memory[i][j] += memory[i+1][j+1];

        printf("%d\t[%d | %d]\n", memory[i][j], i, j);
        if (memory[i][j] > 289326) break;

        switch (side) {
            case 0: j--;
                break;
            case 1: i--;
                break;
            case 2: j++;
                break;
            case 3: i++;
                break;
        }
        sw_side--;
        if (!sw_side) {
            sw_side += side_add;
            if (++tic_side > 1){
                side_add++;
                tic_side = 0;
            }
            side++;
            if (side > 3) side = 0;
        }
    } while (1);

    /*int memval[1024] = {0}, i, unless = 2, memexp = 1, memsum = 0;

    for (i = 0; ; i++) {
        if ((memexp * memexp) < (i + 1)) memexp += 2;
        unless--;
        if (memsum) {
            memval[i] += memval[i-1];
            ;
        }
        if (!unless && i) {
            unless += memexp - 2;
        }

        if (memval[i] > 289326) break;
    }*/
    return 0;
}
