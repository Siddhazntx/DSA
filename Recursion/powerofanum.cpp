#include <iostream>
#include <vector>
using namespace std;

double power(double x, int n){
    if(n == 0) return 1;

    double half = power(x, n/2);
    if(n%2 == 0){
        return half*half;
    }
    return half*half*x;
}
int powerofnum(double x, int n){
    long long num = n;

    if(num < 0){
        return 1.0/power(x, -num);
    }
    return power(x, num);
}

int main() {
    double x = 2;
    int n = 5;

    double result = powerofnum(x, n);

    cout << "Answer: " << result << endl;

    return 0;
}