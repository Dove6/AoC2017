#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define lines 512

int main()
{
    printf("Hello world!\n");
    char passp[lines][80];
    short maxlen = 0;
    short i, OK = 0;
    for (i = 0; i < lines; i++) {
        char *passw[16] = {0};
        bool valid = true;
        if (!(fgets(passp[i], sizeof(passp[i]), stdin))) return -1;
        if (passp[i][0] == '.') {
            i--;
            break;
        }
        if (passp[i][strlen(passp[i]) - 1] != '\n') return -2;
        if (strlen(passp[i]) + 1 > maxlen) maxlen = strlen(passp[i]) + 1;
        passw[0] = strtok(passp[i], " \n");
        short j;
        for (j = 0; passw[j] != NULL; ) {
            j++;
            passw[j] = strtok(NULL, " \n");
        }
        for (short k = 0; passw[k] != NULL; k++) {
            for (short l = 0; passw[l] != NULL; l++) {
                if (k != l) {
                    if(!strcmp(passw[k], passw[l])) valid = false;
                }
            }
        }
        if (valid) OK++;
    }
    //printf("%d wierszy maksymalnie po %d znakow", i, maxlen);
    printf("Poprawnych: %d hasel", OK);
    return 0;
}
