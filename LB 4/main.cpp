#include <iostream>

double QuickPow(double x, int n){
    double c = x, f = 1;
    int k = n;
    while (k != 0) {
        if (k % 2 == 0) {
            c *= c;
            k /= 2;
        } else {
            f *= c;
            k -= 1;
        }
    }
    return f;
}

int main() {
    double x;
    int n;
    std::cout << "x = ";
    std::cin >> x;
    std::cout << "n = ";
    std::cin >> n;
    printf("%5.2f ^ %d = %5.2f", x, n, QuickPow(x, n));
    return 0;
}