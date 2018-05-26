#include <cstdio>
#include <cstring>
#include <string>


using namespace std;

int main() {
    string a = "21313123";
    int x;
    sscanf(a.c_str(), "%d", &x);
    printf("%d", x);
    return 0;
}