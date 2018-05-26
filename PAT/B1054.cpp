#include <cstdio>
#include <cstring>

int main() {

    int n;
    char a[50], b[50];
    int count = 0;
    double sum = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", a);
        double temp;
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f", temp);
        int len = strlen(a);
        bool same = true;
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                same = false;
                break;
            }
        }
        if (!same || (temp > 1000 || temp < -1000)) {
            printf("ERROR: %s is not a legal number\n", a);
        } else {
            count++;
            sum += temp;
        }
    }

    if (count == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (count == 1) {
        printf("The average of 1 number is %.2f\n", sum);
    } else {
        printf("The average of %d numbers is %.2f\n", count, sum / count);
    }

    return 0;
}