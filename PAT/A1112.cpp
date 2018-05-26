#include <cstdio>
#include <cstring>

int main() {

    int key_status[128] = {0};
    //0 - unknown; 1 - good; -1 - bad

    bool print_flag[128] = {false};

    int k;
    scanf("%d", &k);
    char result[1010];
    scanf("%s", result);

    int len = strlen(result);

    char current = result[0];
    int current_count = 1;
    for (int i = 1; i < len; i++) {
        if (result[i] == current) {
            current_count++;
            if (current_count == k) {
                current = 0;
                current_count = 0;
                if (key_status[result[i]] != 1) {
                    key_status[result[i]] = -1;
                }
            }
        } else {
            key_status[current] = 1;
            current = result[i];
            current_count = 1;
        }
    }

    for (int i = 0; i < len; i++) {
        if (key_status[result[i]] == -1 && !print_flag[result[i]]) {
            printf("%c", result[i]);
            print_flag[result[i]] = true;
        }
    }

    printf("\n");

    for (int i = 0; i < len; i++) {
        printf("%c", result[i]);
        if (key_status[result[i]] == -1) {
            i += (k - 1);
        }
    }

    return 0;
}