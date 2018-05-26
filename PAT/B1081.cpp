#include <cstdio>
#include <cstring>

bool isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

bool isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool isDot(char c){
    return c == '.';
}

void check(char a[]) {
    int len = strlen(a);
    if (len < 6) {
        printf("Your password is tai duan le.\n");
        return;
    }

    bool letter = false, digit = false;

    for (int i = 0; i < len; i++) {
        if (isLetter(a[i])) {
            letter = true;
            continue;
        } else if (isDigit(a[i])) {
            digit = true;
            continue;
        } else if (isDot(a[i])) {
            continue;
        } else {
            printf("Your password is tai luan le.\n");
            return;
        }
    }

    if (letter && digit) {
        printf("Your password is wan mei.\n");
        return;
    }
    if (!digit) {
        printf("Your password needs shu zi.\n");
    }
    if (!letter){
        printf("Your password needs zi mu.\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char s[81];
    while (n--) {
        gets(s);
        check(s);
    }

    return 0;
}