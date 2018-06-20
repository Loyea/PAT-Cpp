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

bign convert(string str) {
    bign a;
    a.len = str.length();
    for (int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - 1 - i] - '0';
    }
    return a;
}

int cmp(bign a, bign b) {
    if (a.len > b.len) {
        return 1;
    } else if (a.len < b.len) {
        return -1;
    } else {
        for (int i = a.len - 1; i >= 0; i--) {  //从高位开始判断！！！
            if (a.d[i] > b.d[i]) {
                return 1;
            } else if (a.d[i] < b.d[i]) {
                return -1;
            }
            //continue if a.d[i] == b.d[i]
        }
        return 0;
    }
}

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

//高精度减法
//使用前需要比较两个数大小，a必须大于b。如果被减数小于减数，交换位置后结果添加负号
bign sub(bign a, bign b) {
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++) {
        if (a.d[i] < b.d[i]) {
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        //高位可能有多余的0，while循环判断每一位是否是0，保证结果至少有一位数
        //c.len - 1 >= 1 表示 c.len >= 2 进入循环内减一位后剩余1位
        c.len--;
    }
    return c;
}

//高精度与低精度的乘法，即bign与int的乘法
bign multi(bign a, int b) {
    bign c;
    int carry = 0;  //进位
    for (int i = 0; i < a.len; i++) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10; //取结果的个位作为该位结果
        carry = temp / 10; //高位部分作为进位，进位可能不止一位
    }
    while (carry != 0) {    //不同于加法，乘法的进位可能不止一位，所以需要使用while
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}


//高精度与低精度的除法, r是余数  a/b = c...r
//传入的r默认应该为0
bign divide(bign a, int b, int& r) {
    r = 0;
    bign c;
    c.len = a.len; //被除数与商每一位对应，先令长度相等
    for (int i = a.len - 1; i >= 0; i--) {
        r = r * 10 + a.d[i];
        if (r < b) {
            c.d[i] = 0;
        } else {
            c.d[i] = r / b;
            r = r % b;
        }
    }

    //去除高位的0，同时保留至少一位最低位
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}



int main() {
    string a_str;
    int b;
    cin >> a_str;
    scanf("%d", &b);

    bign a = convert(a_str);
    
    int r = 0;

    bign q = divide(a, b, r);

    for (int i = q.len - 1; i >= 0; i--) {
        printf("%d", q.d[i]);
    }

    printf(" %d", r);

    return 0;
}