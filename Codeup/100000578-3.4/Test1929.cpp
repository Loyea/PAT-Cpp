#include <cstdio>
#include <cstring>

bool isLeap(int year) {
    return (year % 4 == 00 && year % 100 != 0) || (year % 400 == 0);
}

int parseMonth(char ms[]){
    if (strcmp("January", ms) == 0) {
        return 1;
    }
    if (strcmp("February", ms) == 0) {
        return 2;
    }
    if (strcmp("March", ms) == 0) {
        return 3;
    }
    if (strcmp("April", ms) == 0) {
        return 4;
    }
    if (strcmp("May", ms) == 0) {
        return 5;
    }
    if (strcmp("June", ms) == 0) {
        return 6;
    }
    if (strcmp("July", ms) == 0) {
        return 7;
    }
    if (strcmp("August", ms) == 0) {
        return 8;
    }
    if (strcmp("September", ms) == 0) {
        return 9;
    }
    if (strcmp("October", ms) == 0) {
        return 10;
    }
    if (strcmp("November", ms) == 0) {
        return 11;
    }
    if (strcmp("December", ms) == 0) {
        return 12;
    }
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

int month[2][13]= {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                   {0,31,29,31,30,31,30,31,31,30,31,30,31}};

//Because 2013.1.5 is Saturday.
char weekdays[7][20] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};


int main() {
    int d2, y2, m2;
    char ms[20];
    while (scanf("%d %s %d", &d2, ms, &y2) != EOF) {
        m2 = parseMonth(ms);
        int d1 = 5, y1 = 2013, m1 = 1;
        int mark = yearcmp(y1, m1, d1, y2, m2, d2);
        if (mark > 0) {
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
        int count = 0;
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

        int temp = count % 7;
        if (mark <= 0) {
            printf("%s\n", weekdays[temp]);
        } else {
            temp = (7 - temp) % 7;
            printf("%s\n", weekdays[temp]);
        }
    }

    return 0;
}