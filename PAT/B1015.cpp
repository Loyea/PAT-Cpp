#include <cstdio>
#include <algorithm>
using namespace std;

struct testee {
    int num, d, c, sum;
};

bool cmp(testee t1, testee t2) {
    if(t1.sum != t2.sum) {
        return t1.sum > t2.sum;
    } else {
        if(t1.d != t2.d){
            return t1.d > t2.d;
        } else {
            return t1.num < t2.num;
        }
    }
}

testee t[100010];
testee t1[100010], t2[100010], t3[100010], t4[100010];
int size1 = 0, size2 = 0, size3 = 0, size4 = 0;

int main() {
    int size = 0;
    int n, l, h;
    scanf("%d%d%d", &n, &l, &h);
    for(int i = 0; i < n; i++){
        int num, d, c, sum;
        scanf("%d %d %d", &num, &d, &c);
        if(d >= l && c >= l){
            sum = d + c;
            t[size].num = num;
            t[size].d = d;
            t[size].c = c;
            t[size].sum = sum;
            size++;
        }
    }


    for(int i = 0; i < size; i++){
        if(t[i].d >= h && t[i].c >= h){
            t1[size1++] = t[i];
            continue;
        }

        if(t[i].d >= h && t[i].c < h){
            t2[size2++] = t[i];
            continue;
        }

        if(t[i].d < h && t[i].c < h && t[i].d >= t[i].c){
            t3[size3++] = t[i];
            continue;
        }

        t4[size4++] = t[i];
    }

    sort(t1, t1 + size1, cmp);
    sort(t2, t2 + size2, cmp);
    sort(t3, t3 + size3, cmp);
    sort(t4, t4 + size4, cmp);

    printf("%d\n", size);
    for(int i = 0; i < size1; i++){
        printf("%d %d %d\n", t1[i].num, t1[i].d, t1[i].c);
    }
    for(int i = 0; i < size2; i++){
        printf("%d %d %d\n", t2[i].num, t2[i].d, t2[i].c);
    }
    for(int i = 0; i < size3; i++){
        printf("%d %d %d\n", t3[i].num, t3[i].d, t3[i].c);
    }
    for(int i = 0; i < size4; i++){
        printf("%d %d %d\n", t4[i].num, t4[i].d, t4[i].c);
    }
    return 0;
}