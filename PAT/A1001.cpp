#include <cstdio>
#include <string>

using namespace std;

int main() {

    int a, b;
    scanf("%d%d", &a, &b);
    int x = a + b;
    int absx = abs(x);

    string result = "";

    int count = 1;
    do {
        int temp = absx % 10;
        char c = temp + '0';
        result = c + result;
        absx = absx / 10;
        if (count % 3 == 0 && absx != 0) {
            result = "," + result;
        }
        count++;
    } while(absx != 0);


    if (x < 0) {
        printf("-");
    }

    printf("%s", result.c_str());

    return 0;
}