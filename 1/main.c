#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long sum = 0;
    char array[4096] = {0};
    printf("Hello world! %c\n", 48);
    //scanf("%c%c%c", array, array+1, array+2);
    if (!(fgets (array, sizeof(array), stdin))) return -1;
    if (array[strlen(array)-1] != '\n') return -2;
    short i;
    for (i = 0; array[i+1] != '\n'; i++) {
        if (array[i] == array[i+1]) sum += array[i] - 48;
    }
    if (array[i] == array[0]) sum += array[i] - 48;
    printf("%I64d", sum);
    return 0;
}
