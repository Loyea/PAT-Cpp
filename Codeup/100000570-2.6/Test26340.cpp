#include <stdio.h>
#include <cstring>

void vowels(char s1[], char s2[]) {
    for (int i = 0; i < strlen(s1); i++) {
        char temp = s1[i];
        if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'
            || temp == 'A' || temp == 'E' || temp == 'I' || temp == 'O' || temp == 'U') {
            sprintf(s2, "%s%c", s2, temp);
        }
    }
}

int main() {

    char s1[255], s2[255] = ""; //import!!!!
    gets(s1);
    vowels(s1, s2);
    puts(s2);
    return 0;
}