#include <cstdio>
#include <algorithm>

using namespace std;

//测试数据：
//50 1300 12 8
//7.10 0
//7.00 150
//7.50 400
//8.00 600
//7.20 900
//7.30 1000
//6.00 1250
//6.85 1280
//-------------------
//正确答案为   767.50

struct station {
    double price, start, end;
};

bool cmp(station a, station b) {
    if (a.start != b.start) {
        return a.start < b.start;
    } else {
        return a.price < b.price;
    }
}

int main() {
    station s[510];

    double c, d, d_avg;
    int n;
    scanf("%lf %lf %lf %d", &c, &d, &d_avg, &n);

    double max_distance = d_avg * c;

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &s[i].price, &s[i].start);
        s[i].end = s[i].start + max_distance;
    }

    sort(s, s + n, cmp);

    if (s[0].start != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    int last_station = 0;

    double fare = 0;
    double distance = 0;

    double gas_remain = 0;

    while (true) {
        bool valid_station_exists = false;
        int next_station_index = last_station + 1;
        bool find_best = false;

        for (int i = last_station + 1; i < n; i++) {
            if (s[i].start <= s[last_station].end) {
                valid_station_exists = true;
                if (s[i].price < s[last_station].price) {
                    next_station_index = i;
                    find_best = true;
                    break;
                } else {
                    if (s[i].price < s[next_station_index].price) {
                        next_station_index = i;
                    }
                }
            } else {
                break; //因为从近到远排列，如果程序运行到else这里，后面的也不用判断了。
            }
        }


        //log
//        printf("fare: %f\n", fare);
//        printf("gas_remain: %f\n", gas_remain);
//        printf("last_station: %d\n", last_station);
//        printf("valid_station_exists? : %d\n", valid_station_exists);
//        printf("find_best? : %d\n", find_best);
//        printf("next_station: %d\n", next_station_index);
//        printf("----------\n");


        if (valid_station_exists) {
            if (d <= s[next_station_index].start) {
                fare += (d - s[last_station].start) / d_avg * s[last_station].price;
                printf("%.2f", fare);
                return 0;
            } else {
                //都是要根据上个路程是否有剩余决定加多少油
                if (find_best) {
                    double gas_need = (s[next_station_index].start - s[last_station].start) / d_avg - gas_remain;
                    gas_remain = 0;
                    distance += s[next_station_index].start - s[last_station].start;
                    fare += gas_need * s[last_station].price;
                } else {
                    if (d <= s[last_station].end) {
                        fare += (d - s[last_station].start) / d_avg * s[last_station].price;
                        printf("%.2f", fare);
                        return 0;
                    }
                    double gas_need = c - gas_remain;
                    distance += s[next_station_index].start - s[last_station].start;
                    fare += gas_need * s[last_station].price;
                    gas_remain = c - (s[next_station_index].start - s[last_station].start) / d_avg;
                }
                last_station = next_station_index;
            }
        } else {
            if (s[last_station].end < d) {
                distance = s[last_station].end;
                printf("The maximum travel distance = %.2f", distance);
                return 0;
            } else {
                fare += (d - s[last_station].start) / d_avg * s[last_station].price;
                printf("%.2f", fare);
                return 0;
            }
        }


    }

    return 0;
}