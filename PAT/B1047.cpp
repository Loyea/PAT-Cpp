#include <stdio.h>

int main() {

    int team[1000];
    int score[1000] = {0};

    for (int i = 0; i < 1000; i++) {
        team[i] = i + 1;
    }

    int size;
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        int a, b, c;
        scanf("%d-%d %d", &a, &b, &c);
        score[a - 1] += c;
    }

    for (int i = 1; i < 1000; i++) {
        for (int j = 0; j < 1000 - i; j++) {
            if (score[j] < score[j + 1]) {
                int temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;

                int temp2 = team[j];
                team[j] = team[j + 1];
                team[j + 1] = temp2;
            }
        }
    }

    printf("%d %d", team[0], score[0]);

    return 0;
}