#include <cstdio>
#include <algorithm>

using namespace std;

/* 区间贪心
 * 给出N个开区间(x, y)，从中选择尽可能多的开区间，使得这些开区间两两没有交集
 *
 * 测试输入：
 * 4
 * 1 3
 * 2 4
 * 3 5
 * 6 7
 *
 * 测试输出：
 * 3
 */

 struct interval{
     int x, y;
 };

bool cmp(interval a, interval b) {
    if (a.x != b.x) {
        return a.x > b.x;   //先按左端点从大到小排序
    } else {
        return a.y < b.y;   //左端点相同按右端点从小到大排序
    }
}

int main() {

    interval I[1000];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &I[i].x, &I[i].y);
    }

    sort(I, I + n, cmp); //把区间排序

    int count = 1, lastX = I[0].x;
    printf("%d %d\n", I[0].x, I[0].y);
    for (int i = 1; i < n; i++) {
        if (I[i].y <= lastX) { //因为是开区间，同一点可以同时取到
            count++;
            lastX = I[i].x;
            printf("%d %d\n", I[i].x, I[i].y);
        }
    }

    printf("%d", count);


    return 0;
}