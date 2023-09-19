#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool hasNonRepeatingLetters(const char* word) {
    int charSet[26] = {0};

    for (int i = 0; word[i]; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            int index = word[i] - 'a';
            if (charSet[index] == 1) {
                return false;
            }
            charSet[index] = 1;
        }
    }

    return true;
}

int main() {
    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char word[31];

    printf("Words with non-repeating letters:\n");

    while (fscanf(file, "%30s", word) != EOF) {
        if (hasNonRepeatingLetters(word)) {
            printf("%s\n", word);
        }
    }

    fclose(file);

    return 0;
}