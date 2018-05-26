#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct record{
    string num, status;
    int time;
};

bool cmp(record r1, record r2) {
    if (r1.num != r2.num) {
        return r1.num < r2.num;
    } else {
        return r1.time < r2.time;
    }
}

bool cmp_by_time(record r1, record r2) {
    return r1.time < r2.time;
}

int time_to_sec(int hh, int mm, int ss) {
    return hh * 60 * 60 + mm * 60 + ss;
}

string format_time(int secs) {
    int ss = secs % 60;
    int mm = secs % (60 * 60) / 60;
    int hh = secs / (60 * 60);
    char result[10];
    sprintf(result, "%02d:%02d:%02d", hh, mm, ss);
    string time = result;
    return time;
}

int main() {
    record rec[10010], valid[10010];

    map<string, int> m;

    int valid_count = 0;

    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int hh, mm, ss;
        char num[10], status[5];
        scanf("%s %d:%d:%d %s", num, &hh, &mm, &ss, status);
        rec[i].num = num;
        rec[i].status = status;
        rec[i].time = time_to_sec(hh, mm, ss);
    }

    sort(rec, rec + n, cmp);


    int max_duration = 0;
    for (int i = 0; i < n - 1; i++) {
        if (rec[i].num == rec[i+1].num && rec[i].status == "in" && rec[i + 1].status == "out") {
            //save in valid array.
            valid[valid_count++] = rec[i];
            valid[valid_count++] = rec[i+1];

            //save parking time.
            if (m.find(rec[i].num) == m.end()) {
                m[rec[i].num] = 0;
            }
            int duration = rec[i + 1].time - rec[i].time;
            m[rec[i].num] = m[rec[i].num] + duration;

            max_duration = max(max_duration, m[rec[i].num]);

            i++;//当前这对匹配的话可以跳过下一个
        }

    }

    sort(valid, valid + valid_count, cmp_by_time);

    int car_count = 0;
    int now = 0;
    for (int i = 0; i < k; i++) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int query_time = time_to_sec(hh, mm, ss);
        while (now < valid_count && valid[now].time <= query_time) {
            if (valid[now].status == "in") {
                car_count++;
            } else {
                car_count--;
            }
            now++;
        }
        printf("%d\n", car_count);
    }


    //遍历map
    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == max_duration) {
            printf("%s ", iter->first.c_str());
        }
    }

    string max_duration_str = format_time(max_duration);
    printf("%s", max_duration_str.c_str());

    return 0;
}