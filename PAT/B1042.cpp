#include <stdio.h>

int main() {

    int count[26] = {0}; //initialize is important!!
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    while(true) {
        char temp;
        scanf("%c", &temp);
        if (temp == '\n') {
            break;
        }
        if (temp >= 'a' && temp <= 'z') {
            count[temp - 'a']++;
        } else if (temp >= 'A' && temp <= 'Z') {
            count[temp - 'A']++;
        }
    }

    for (int i = 1; i < 26; i++) {
        for (int j = 0; j < 26 - i; j++) {
            if (count[j] < count[j + 1]) {
                int temp = count[j];
                count[j] = count[j + 1];
                count[j + 1] = temp;

                char c = alphabet[j];
                alphabet[j] = alphabet[j + 1];
                alphabet[j + 1] = c;
            }
        }
    }

    printf("%c %d", alphabet[0], count[0]);

    return 0;
}