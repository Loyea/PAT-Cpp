#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = pow(2, 31) - 1;


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

    s[n].start = d;
    s[n].price = 0;
    //一共有n+1个加油站，重点在第n个

    sort(s, s + n, cmp);

    if (s[0].start != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    int current_station = 0;

    double fare = 0, gas_left = 0;

    while (current_station < n) {
        int next_station = -1;
        double cheapest_price = INF;
        for (int i = current_station + 1; i <= n && s[current_station].end >= s[i].start; i++) {
            //i <= n是因为现在一共有n+1个站
            if (s[i].price < cheapest_price) {
                cheapest_price = s[i].price;
                next_station = i;
                if (s[i].price < s[current_station].price) {
                    break;
                }
            }
        }

        if (next_station == -1) {
            //说明未找到有效的下一个加油站
            break;
        }

        double gas_need = (s[next_station].start - s[current_station].start) / d_avg;
        if (cheapest_price < s[current_station].price) {
            //说明next_station的价格比当前还便宜，只需刚好能跑到next_station的油量
            if (gas_left < gas_need) {
                fare += (gas_need - gas_left) * s[current_station].price;
                gas_left = 0;
            } else {
                gas_left -= gas_need;
            }
        } else {
            //说明没有找到比当前加油站更便宜的加油站，直接在当前加满
            fare += (c - gas_left) * s[current_station].price;
            gas_left = c - gas_need;
        }
        current_station = next_station;
    }

    if (current_station == n) {
        //重点是第n个加油站
        printf("%.2f", fare);
    } else {
        printf("The maximum travel distance = %.2f", s[current_station].start + max_distance);
    }



    return 0;
}