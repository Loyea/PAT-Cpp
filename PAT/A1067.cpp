#include <cstdio>

int main() {
    int a[100010];
    int a_index[100010];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a_index[a[i]] = i;
    }

    int count = 0;
    int k = 1;
    while (true) {
        int index_0 = a_index[0];
        int target_index = a_index[index_0];

        if (index_0 == target_index) {
            for (int i = k; i < n; i++) {
                if (a[i] != i) {
                    target_index = i;
                    k = i + 1;
                    break;
                }
            }
        }

        if (index_0 == target_index) {
            //finish
            break;
        }

        //swap
        a[index_0] = a[target_index];
        a[target_index] = 0;

        a_index[0] = target_index;
        a_index[a[index_0]] = index_0;
        count++;
    }

    printf("%d", count);


    return 0;
}