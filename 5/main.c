#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int mempos = 0, memsteps = 0, memlayer = 0, memlpos = 0, memexp = 0;
    printf("Hello world!\n");
    //while (1) {
        //memsteps = 0;
        //memlayer = 0;
        //memlpos = 0;
        //memexp = 0;
        scanf("%d", &mempos);
        for (memexp = 1; mempos > (memexp * memexp); memexp += 2) memlayer++;
        if (memlayer > 1) memlpos = (mempos - 1) % (memexp - 1);
        else memlpos = !(mempos % 2);
        memsteps = memlayer;
        memsteps += abs(memlayer - memlpos);
        //printf("%d - memlayer (%d - memexp)\n%d - memlpos\n%d - memsteps\n------\n\n", memlayer, memexp, memlpos, memsteps);
        printf("%d", memsteps);
    //}
    return 0;
}
