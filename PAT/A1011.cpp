#include <cstdio>
#include <cmath>

int main() {
    char game[3] = {'W', 'T', 'L'};

    double profit = 1;
    int n = 3;
    while (n--) {
        double max = 0;
        char max_c;

        for (int i = 0; i < 3; i++) {
            double temp;
            scanf("%lf", &temp);
            if (temp > max) {
                max = temp;
                max_c = game[i];
            }
        }
        printf("%c ", max_c);

        profit = profit * max;
    }

    profit = (profit * 0.65 - 1) * 2;

    printf("%.2f", profit);

    return 0;
}