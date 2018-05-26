#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string to_13(int a){
    string result = "";
    do{
        int temp = a % 13;
        a = a / 13;

        if (temp <= 9) {
            char c = '0' + temp;
            result = c + result;
        } else {
            temp = temp - 10;
            char c = 'A' + temp;
            result = c + result;
        }
    } while (a != 0);

    if (result.length() == 1) {
        result = "0" + result;
    }

    return result;
}



int main() {
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);

    string r_str = to_13(r);
    string g_str = to_13(g);
    string b_str = to_13(b);

    printf("#%s%s%s", r_str.c_str(), g_str.c_str(), b_str.c_str());

    return 0;
}