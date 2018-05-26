#include <cstdio>

int main() {

    int n;
    while (scanf("%d", &n) != EOF) {
        int a1 = 0;
        int a2[1010] = {0};
        int a2Index = 0;
        int a3 = 0;
        int a4[1010] = {0};
        int a4Index = 0;
        int a5 = 0;
        int temp, mod;
        while (n--) {
            scanf("%d", &temp);
            mod = temp % 5;
            switch (mod) {
                case 0:
                    if (temp % 2 == 0) {
                        a1 += temp;
                    }
                    break;
                case 1:
                    a2[a2Index] = temp;
                    a2Index++;
                    break;
                case 2:
                    a3++;
                    break;
                case 3:
                    a4[a4Index] = temp;
                    a4Index++;
                    break;
                case 4:
                    if (temp > a5) {
                        a5 = temp;
                    }
                    break;
                default:break;
            }
        }
        if (a1 > 0) {
            printf("%d ", a1);
        } else {
            printf("N ");
        }

        //use a2 counter number to check whether number corresponding a2 rule exists.
        //because sum may be 0. use sum to check is not safe.(e.g. 2 6 6)
        if (a2Index > 0) {
            int sumA2 = 0;
            for (int i = 0; i < a2Index; i++) {
                sumA2 += (i % 2 == 0 ? 1 : -1) * a2[i];
            }
            printf("%d ", sumA2);
        } else {
            printf("N ");
        }

        if (a3 > 0) {
            printf("%d ", a3);
        } else {
            printf("N ");
        }

        if (a4Index > 0) {
            double sumA4 = 0;
            for (int i = 0; i < a4Index; i++) {
                sumA4 += a4[i];
            }
            printf("%.1f ", sumA4/a4Index);
        } else {
            printf("N ");
        }

        if (a5 > 0) {
            printf("%d\n", a5);
        } else {
            printf("N\n");
        }
    }

    return 0;
}