#include <cstdio>
#include <string>

using namespace std;

bool is_prime(int a) {
    if (a == 2) {
        return true;
    }
    if (a % 2 == 0 || a < 2) {
        return false;       //1 is not a prime number.
    }
    for (int i = 3; i * i <= a; i += 2) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

string to_radix(int n, int radix) {
    string result = "";
    do {
        int temp = n % radix;
        char temp_c = temp + '0';
        result = result + temp_c;
        n = n / radix;
    } while (n > 0);
    return result;
}

string reverse_string(string s) {
    int len = s.length();
    string result = "";
    for (int i = len - 1; i >= 0; i--) {
        result = result + s[i];
    }
    return result;
}

int to_decimal(string num, int radix) {
    int len = num.length();
    int result = 0;
    int product = 1;
    for (int i = 0; i < len; i++) {
        int current = num[i] - '0';
        result += current * product;
        product *= radix;
    }
    return result;
}

int reverse_number(int n, int radix) {
    string temp = to_radix(n, radix);
    string reverse_temp = reverse_string(temp);
    int reverse_number = to_decimal(reverse_temp, radix);
    return reverse_number;
}


int main() {

    int n, d;
    while (scanf("%d", &n), n > 0) {
        scanf("%d", &d);
        int reverse_num = reverse_number(n, d);

        if (is_prime(n) && is_prime(reverse_num)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}