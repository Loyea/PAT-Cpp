#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct record{
    string name, status;
    int m, d, h, mi;

    record(){
        name = "";
    }
};

bool cmp(record r1, record r2) {
    if (r1.name != r2.name) {
        return r1.name < r2.name;
    } else {
        if (r1.d != r2.d) {
            return r1.d < r2.d;
        } else {
            if (r1.h != r2.h) {
                return r1.h < r2.h;
            } else {
                return r1.mi < r2.mi;
            }
        }
    }
}


int rate[24];

double compute_fare(int d1, int h1, int m1, int d2, int h2, int m2) {
    double fare = 0;
    while ((d1 < d2) || (h1 < h2) || (m1 < m2)) {
        m1++;
        fare = fare + rate[h1];
        if (m1 == 60) {
            h1++;
            m1 = 0;
            if (h1 == 24) {
                d1++;
                h1 = 0;
            }
        }
    }
    return fare / 100;
}



int main() {
    record records[1010];

    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char name[21], status[10];
        int m, d, h, mi;
        scanf("%s %d:%d:%d:%d %s", name, &m, &d, &h, &mi, status);
        records[i].name = name;
        records[i].status = status;
        records[i].m = m;
        records[i].d = d;
        records[i].h = h;
        records[i].mi = mi;
    }

    sort(records, records + n, cmp);

    record previous_record;
    double fare = 0;
    bool vaild_pair_exists = false;
    bool name_printed = false;
    for (int i = 0; i < n; i++) {
        if (records[i].name != previous_record.name) {
            vaild_pair_exists = false;
            name_printed = false;
            previous_record = records[i];
            fare = 0;
        }

        if (previous_record.status == "on-line" && records[i].status == "off-line") {
            vaild_pair_exists = true;
            if (!name_printed) {
                name_printed = true;
                printf("%s %02d\n", records[i].name.c_str(), records[i].m);
            }
            int duration = records[i].d * 24 * 60 + records[i].h * 60 + records[i].mi -
                           (previous_record.d * 24 * 60 + previous_record.h * 60 + previous_record.mi);
            double current_fare = compute_fare(previous_record.d, previous_record.h, previous_record.mi,
                                               records[i].d, records[i].h, records[i].mi);
            fare = fare + current_fare;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", previous_record.d, previous_record.h, previous_record.mi,
                   records[i].d, records[i].h, records[i].mi, duration, current_fare);
        }

        //update previous record
        previous_record = records[i];


        if (records[i + 1].name != records[i].name) {
            if (vaild_pair_exists) {
                printf("Total amount: $%.2f\n", fare);
            }
        }
    }

    return 0;
}