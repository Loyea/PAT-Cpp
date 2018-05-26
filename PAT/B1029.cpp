#include <cstdio>
#include <cstring>

int main() {
    bool valid[37] = {false};

    char a[85], b[85];
    scanf("%s %s", a, b);

    int len_b = strlen(b);
    for (int i = 0; i < len_b; i++) {
        if (b[i] >= '0' && b[i] <= '9') {
            int index = b[i] - '0';
            valid[index] = true;
        } else if (b[i] >= 'a' && b[i] <= 'z') {
            int index = b[i] - 'a' + 10;
            valid[index] = true;
        } else if (b[i] >= 'A' && b[i] <= 'Z'){
            int index = b[i] - 'A' + 10;
            valid[index] = true;
        } else {
            valid[36] = true;
        }
    }

    int len_a = strlen(a);
    for (int i = 0; i < len_a; i++) {
        int index = 0;
        if (a[i] >= '0' && a[i] <= '9') {
            index = a[i] - '0';
        } else if (a[i] >= 'a' && a[i] <= 'z') {
            index = a[i] - 'a' + 10;
        } else if (a[i] >= 'A' && a[i] <= 'Z') {
            index = a[i] - 'A' + 10;
        } else {
            index = 36; //underline
        }

        if (!valid[index]) {
            if (a[i] >= '0' && a[i] <= '9') {
                printf("%c", a[i]);
            } else if (a[i] >= 'a' && a[i] <= 'z') {
                char ch = a[i] - 'a' + 'A';
                printf("%c", ch);
            } else if (a[i] >= 'A' && a[i] <= 'Z') {
                printf("%c", a[i]);
            } else {
                printf("_");
            }
            valid[index] = true;
        }
    }
    return 0;
}