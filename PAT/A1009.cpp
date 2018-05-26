#include <cstdio>

int main() {
    double coe1[1010] = {0};
    double coe2[1010] = {0};

    for (int i = 0; i < 2; i++) {
        int m;
        scanf("%d", &m);
        while (m--) {
            int exp;
            double coe;
            scanf("%d %lf", &exp, &coe);
            if (i == 0) {
                coe1[exp] = coe;
            } else {
                coe2[exp] = coe;
            }
        }
    }

    double coe_product[2010] = {0}; //2010 because exp1 + exp2
    for (int i = 0; i < 1010; i++) {
        for (int j = 0; j < 1010; j++) {
            if (coe1[i] != 0 && coe2[j] != 0) {
                int new_coe = i + j;
                coe_product[new_coe] = coe_product[new_coe] + coe1[i] * coe2[j];
            }
        }
    }

    int count = 0;
    for (int i = 2009; i >= 0; i--) {
        if (coe_product[i] != 0) {
            count++;
        }
    }

    printf("%d", count);

    for (int i = 2009; i >= 0; i--) {
        if (coe_product[i] != 0) {
            printf(" %d %.1f", i, coe_product[i]);
        }
    }

    return 0;
}