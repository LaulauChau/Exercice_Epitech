#include <stdio.h>
#include <stdlib.h>

int countOccurence(char letter, char *word);

int main(int argc, char *argv[]) {
    argc--;

    if (argc == 0) {
        return 84;
    }

    int group = 0, sort = 0;
    char *string = NULL, *searchCharacters = NULL, *stringToLoop;

    for (int i = 1; i <= argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'r':
                    group = 1;
                    break;
                case 't':
                    sort = 1;
                    break;
                default:
                    return 84;
            }
        } else {
            if (string == NULL) {
                string = argv[i];
                stringToLoop = string;
            } else {
                searchCharacters = argv[i];
                stringToLoop = searchCharacters;
            }
        }
    }

    char *lettersSeen = NULL;
    int *lettersOccurences = NULL;
    int lettersSeenLength = 1;

    for (int i = 0; stringToLoop[i]; i++) {
        char letter = stringToLoop[i];

        if (countOccurence(letter, lettersSeen) == 0) {
            lettersSeen = realloc(lettersSeen, (lettersSeenLength + 1) * sizeof(char));
            lettersOccurences = realloc(lettersOccurences, (lettersSeenLength) * sizeof(int));

            lettersSeen[lettersSeenLength - 1] = letter;
            lettersSeen[lettersSeenLength] = '\0';
            lettersOccurences[lettersSeenLength - 1] = countOccurence(letter, string);

            lettersSeenLength++;
        }
    }

    for (int i = 0; lettersSeen[i]; i++) {
        for (int j = i + 1; lettersSeen[j]; j++) {
            if (lettersOccurences[i] < lettersOccurences[j]) {
                int temp = lettersOccurences[i];
                lettersOccurences[i] = lettersOccurences[j];
                lettersOccurences[j] = temp;

                char tempLetter = lettersSeen[i];
                lettersSeen[i] = lettersSeen[j];
                lettersSeen[j] = tempLetter;
            }
        }
    }
    int i = 0;
    int bool = 0;

    while (lettersSeen[i]) {
        printf("%c", lettersSeen[i]);

        if (group == 1) {
            int *temp = lettersOccurences;
            for (int j = i + 1; lettersSeen[j]; j++) {
                if (lettersOccurences[i] == temp[j]) {
                    bool++;
                    printf(",%c", lettersSeen[j]);
                }
            }
        }

        printf(":%d\n", lettersOccurences[i]);

        i++;

        if (bool > 0) {
            i += bool;
            bool = 0;
        }
    }

    return 0;
}

int countOccurence(char letter, char *word) {
    if (word == NULL) {
        return 0;
    }

    int occurence = 0;

    for (int i = 0; word[i]; i++) {
        if (word[i] == letter) {
            occurence += 1;
        }
    }

    return occurence;
}