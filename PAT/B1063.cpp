#include <stdio.h>
#include <cmath>

int main() {

    double max = 0;
    int size;
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        double temp = sqrt(a * a + b * b);
        if (temp > max) {
            max = temp;
        }
    }

    printf("%.2f", max);

    return 0;
}