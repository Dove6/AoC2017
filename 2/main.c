#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long sum = 0;
    char array[4096] = {0};
    printf("Hello world! %c\n", 48);
    if (!(fgets (array, sizeof(array), stdin))) return -1;
    if (array[strlen(array)-1] != '\n') return -2;
    short i, len = strlen(array), len1 = len - 1, len2 = len1 / 2;
    for (i = 0; i < len1; i++) {
        if (i < len2) {
            if (array[i] == array[i+len2]) sum += array[i] - 48;
        } else {
            if (array[i] == array[i-len2]) sum += array[i] - 48;
        }
    }
    printf("%I64d", sum);
    return 0;
}
