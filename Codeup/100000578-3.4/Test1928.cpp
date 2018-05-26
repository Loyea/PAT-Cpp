#include <cstdio>

//LeapYear: 1. divisible by 4 but *not* divisible by 100
//Or, 2.divisible by 400.
bool isLeap(int year) {
    return (year % 4 == 00 && year % 100 != 0) || (year % 400 == 0);
}


int yearcmp(int y1, int m1, int d1, int y2, int m2, int d2){
    if (y1 > y2) {
        return 1;
    } else if (y1 < y2) {
        return -1;
    } else {
        if (m1 > m2) {
            return 1;
        } else if (m1 < m2) {
            return -1;
        } else {
            if (d1 > d2) {
                return 1;
            } else if (d1 < d2) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}


//there are 29 days in february of leap year.
int month[2][13] = {{0, 31,28,31,30,31,30,31,31,30,31,30,31},  //common year
                    {0, 31,29,31,30,31,30,31,31,30,31,30,31}};  //leap year

int main() {

    int y1, m1, d1, y2, m2, d2;
    while (scanf("%4d%2d%2d%4d%2d%2d", &y1, &m1, &d1, &y2, &m2, &d2) != EOF) {
        if (yearcmp(y1, m1, d1, y2, m2, d2) > 0) {
            int tempy, tempm, tempd;
            tempy = y1;
            y1 = y2;
            y2 = tempy;
            tempm = m1;
            m1 = m2;
            m2 = tempm;
            tempd = d1;
            d1 = d2;
            d2 = tempd;
        }

        int count = 1;
        while (yearcmp(y1, m1, d1, y2, m2, d2) != 0) {
            d1++;
            int isY1Leap = isLeap(y1);
            int currentMonthDays = month[isY1Leap][m1];
            if (d1 > currentMonthDays) {
                if (m1 != 12) {
                    m1++;
                    d1=1;
                } else {
                    y1++;
                    m1=1;
                    d1=1;
                }
            }
            count++;
        }

        printf("%d\n", count);
    }
    return 0;
}