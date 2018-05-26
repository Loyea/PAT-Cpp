#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b, temp;
    cin >> a;
    cin >> b;
    int z = a.length() - b.length();
    for(int i = 0; i < abs(z); i++){
        temp += '0';
    }

    if(z > 0){
        b = temp + b;
    } else {
        a = temp + a;
    }

    char result[101] = "";
    int size = 0;
    int len = a.length();
    bool flag = len % 2 == 0;
    for(int i = 0; i < len; i++){
        bool is_even = i % 2 == 0;
        if(!flag) is_even = !is_even;
        int bn = b[i] - '0';
        int an = a[i] - '0';
        if(is_even){
            int res = bn - an;
            if(res < 0) {
                res += 10;
            }
            result[size++] = res + '0';
        } else {
            int res = (an + bn) % 13;
            if(res == 10) {
                result[size++] = 'J';
            } else if (res == 11) {
                result[size++] = 'Q';
            } else if (res == 12) {
                result[size++] = 'K';
            } else {
                result[size++] = res + '0';
            }
        }
    }

    puts(result);

    return 0;
}