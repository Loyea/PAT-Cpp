#include <cstdio>
#include <cstring>



int main() {
    int idx[10010]; //the order of input numeber.
    memset(idx, -1, sizeof(idx));

    int time_count[100010] = {0};
    int individual_count = 0;

    int n;
    scanf("%d", &n);
    while (n--) {
        int temp;
        scanf("%d", &temp);
        if (idx[temp] == -1) {
            idx[temp] = individual_count;
            time_count[individual_count]++;
            individual_count++;
        } else {
            time_count[idx[temp]]++;
        }
    }

    bool valid_exists = false;
    int valid_idx = 0;
    for (int i = 0; i < 100010; i++) {
        if (time_count[i] == 1) {
            valid_idx = i;
            valid_exists = true;
            break;
        }
        if (time_count[i] == 0) {
            break;
        }
    }

    if (!valid_exists) {
        printf("None");
        return 0;
    }

    for (int i = 0; i < 10010; i++) {
        if (idx[i] == valid_idx) {
            printf("%d", i);
            break;
        }
    }



    return 0;
}