#include <cstdio>
#include <cstring>

int to_index(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    } else {
        return c - 'A' + 36;
    }
}

int main() {
    int count[62] = {0};
    char a[1010], b[1010];
    scanf("%s %s", a, b);

    int len_a = strlen(a);
    for (int i = 0; i < len_a; i++) {
        char c = a[i];
        int index = to_index(c);
        count[index]++;
    }

    int len_b = strlen(b);
    int lack = 0;
    for (int i = 0; i < len_b; i++) {
        char c = b[i];
        int index = to_index(c);
        if (count[index] == 0) {
            lack++;
        } else {
            count[index]--;
        }
    }

    if (lack > 0) {
        printf("No %d", lack);
    } else {
        int left = 0;
        for (int i = 0; i < 62; i++) {
            left += count[i];
        }
        printf("Yes %d", left);
    }
    
    return 0;
}