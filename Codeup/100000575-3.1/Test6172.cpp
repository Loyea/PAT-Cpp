#include <cstdio>


char mostWin(int a[], char b[]){
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                char tempc = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tempc;
            }
        }
    }
    return b[0];
}

int main() {

    int aw = 0, al = 0, t = 0;
    char ax[] = {'B', 'C', 'J'};
    char bx[] = {'B', 'C', 'J'};
    int aCount[3] = {0};
    int bCount[3] = {0};
    int n;
    char a, b;
    scanf("%d", &n);
    getchar();
    while (n--) {
        scanf("%c %c", &a, &b);
        getchar();
        if (a == b) {
            t++;
            continue;
        }
        if (a == 'C' && b == 'J') {
            aw++;
            aCount[1]++;
        } else if (a == 'J' && b == 'B') {
            aw++;
            aCount[2]++;
        } else if (a == 'B' && b == 'C') {
            aw++;
            aCount[0]++;
        } else {
            al++;
            if (b == 'J') {
                bCount[2]++;
            } else if (b == 'B') {
                bCount[0]++;
            } else {
                bCount[1]++;
            }
        }
    }

    printf("%d %d %d\n", aw, t, al);
    printf("%d %d %d\n", al, t, aw);

    printf("%c %c", mostWin(aCount, ax), mostWin(bCount, bx));


    return 0;
}