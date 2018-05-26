#include <cstdio>
#include <cstring>

int main() {
    int bad[128] = {0};
    char bad_str[100010];
    gets(bad_str);
    int len = strlen(bad_str);
    for (int i = 0; i < len; i++) {
        bad[bad_str[i]] = 1;
    }

    char output[100010];
    scanf("%s", output);
    int output_len = strlen(output);
    for (int i = 0; i < output_len; i++) {
        if (output[i] >= '0' && output[i] <= '9') {
            if (bad[output[i]] == 0) {
                printf("%c", output[i]);
            }
        } else if (output[i] >= 'a' && output[i] <= 'z') {
            int index = output[i] - 'a' + 'A';
            if (bad[index] == 0) {
                printf("%c", output[i]);
            }
        } else if (output[i] >= 'A' && output[i] <= 'Z') {
            int shift = bad['+'];
            if (!shift && bad[output[i]] == 0) {
                printf("%c", output[i]);
            }
        } else {
            if (bad[output[i]] == 0) {
                printf("%c", output[i]);
            }
        }
    }


    return 0;
}