#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    argc--;
    argv++;

    if (argc == 0) {
        return 84;
    }

    int a = atoi(*argv++), b = atoi(*argv);

    if (a > b) {
        printf("Error: the second parameter must be greater than the first one.\n");
        return 84;
    }

    for (int i = a; i <= b; i++) {
        if (i % 3 == 0) {
            printf("Fizz");
        }
        if (i % 5 == 0) {
            printf("Buzz");
        }
        if ((i % 3 != 0) && (i % 5 != 0)) {
            printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}