#include <cstdio>

void swap(int *a, int *b) {
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {

    int n = 0;
    scanf("%d", &n);
    long long sum = 0;      //may more than 10e9
    long long D[100010] = {0}; //fuck! is 10e5 !!!! FIVE digits after 1!!!! IS FIVE!!!!
    for (int i = 1; i <= n; i++) {
        long long temp = 0;
        scanf("%lld", &temp);
        sum += temp;
        //log the each point distance from p1 instead of each point distance from previous point.
        //so the distance between Pn to Pm (m>n) is Pm - Pn.
        //avoid to calculate the sum of each two point distance from Pn to Pm by looping the D array, which will cause TLE.
        D[i] = sum;
    }
    int m = 0, left = 0, right = 0;
    scanf("%d", &m);

    while (m--) {
        scanf("%d%d", &left, &right);
        swap(&left, &right);
        long long d1 = D[right - 1] - D[left - 1];
        long long d2 = sum - d1;

        if (d1 > d2) {
            printf("%lld\n", d2);   //print long long type use %lld format symbol!!!
        } else {
            printf("%lld\n", d1);
        }
    }

    return 0;
}