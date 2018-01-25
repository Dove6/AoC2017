#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    short list[1152] = {0}, i;
    for (i = 0; !feof(stdin); i++) {
        scanf("%hd", list+i);
    }
    i--;
    //printf("%hd - %hd\n", i, list[i-1]);
    short j = 0;
    unsigned k;
    for (k = 0; j < i && j > -1; k++) {
        //printf("#%ud: %hd -> ", k, j);
        j += list[j]++;
        //printf("%hd\n", j);
    }
    printf("%u (%hd / %hd)", k, j, i);
    return 0;
}
