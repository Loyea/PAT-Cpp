#include <cstdio>
#include <cmath>

int main() {

    int column;
    char c;
    scanf("%d %c", &column, &c);
//    int row = round(((double)column / 2)); //round(double), cast the divisor to double before calculate.

    int row;
    if (column % 2 == 0) {
        row = column / 2;
    } else {
        row = column / 2 + 1;
    }


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (j == 0 || j == column - 1) {
                printf("%c", c);
            } else {
                if (i == 0 || i == row - 1) {
                    printf("%c", c);
                } else {
                    printf(" ");
                }
            }
            if (j == column - 1) {
                printf("\n");
            }
        }
    }


    return 0;
}