#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

struct bign {
    int d[1010];
    int len;

    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

//高精度加法
//条件：a和b都为正数
bign add(bign a, bign b) {
    bign c;
    int carry = 0; //进位
    for (int i = 0; i < a.len || i < b.len; i++) {
        //i < a.len || i < b.len 表示以a或b的较长的为界
        //因为bign结构体中构造函数默认给d数组初始化都为0
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) { //最后进位不为0
        c.d[c.len++] = carry;
    }
    return c;
}

bign convert(string str) {
    bign a;
    a.len = str.length();
    for (int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - 1 - i] - '0';
    }
    return a;
}


bool is_palindromic(bign n) {
    int l = n.len / 2;
    for (int i = 0; i < l; i++) {
        if (n.d[i] != n.d[n.len - 1 - i]) {
            return false;
        }
    }
    return true;
}

void show_bign(bign n) {
    for (int i = n.len - 1; i >= 0; i--) {
        printf("%d", n.d[i]);
    }
}

bign reverse(bign n) {
    bign a;
    a.len = n.len;
    for (int i = 0; i < n.len; i++) {
        a.d[n.len - 1 - i] = n.d[i];
    }
    return a;
}

int main() {
    string n_str;
    int k;
    cin >> n_str;
    scanf("%d", &k);
    bign n = convert(n_str);

    if (is_palindromic(n)) {
        show_bign(n);
        printf("\n0");
        return 0;
    }

    for (int i = 1; i <= k; i++) {
        bign temp = reverse(n);
        n = add(n, temp);
        if (is_palindromic(n)) {
            show_bign(n);
            printf("\n%d", i);
            return 0;
        }
        if (i == k) {
            show_bign(n);
            printf("\n%d", k);
        }
    }



    return 0;
}