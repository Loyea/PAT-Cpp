#include <cstdio>

int main() {
    int distance_from_start[100010] = {0};

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int distance_temp;
        scanf("%d", &distance_temp);
        distance_from_start[i] = distance_from_start[i - 1] + distance_temp;
    }



    int m;
    scanf("%d", &m);
    while (m--) {
        int start, end;
        scanf("%d%d", &start, &end);
        if (start > end) {
            int temp = start;
            start = end;
            end = temp;
        }

        int distance1 = distance_from_start[end - 1] - distance_from_start[start - 1];
        int distance2 = distance_from_start[n] - distance1;

        if (distance1 > distance2) {
            distance1 = distance2;
        }

        printf("%d\n", distance1);
    }

    return 0;
}