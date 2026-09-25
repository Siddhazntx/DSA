#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

string addstring(string num1, string num2){
    int i = num1.size()-1;
    int j = num2.size()-1;

    int carry = 0;
    string ans = "";

    while(i>=0 || j>=0 || carry){
        int sum = carry;
        if(i>=0){
            sum+= num1[i] - '0';
            i--;
        }
        if(j>=0){
            sum+= num2[j] - '0';
            j--;
        }
        ans += char((sum%10) + '0');
        carry = sum/10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // Test Case 1: Standard addition (Same length)
    string num1 = "123";
    string num2 = "456";
    cout << num1 << " + " << num2 << " = " << addstring(num1, num2) << "\n";

    // Test Case 2: Different lengths with a carry at the end
    string num3 = "999";
    string num4 = "1";
    cout << num3 << " + " << num4 << " = " << addstring(num3, num4) << "\n";

    // Test Case 3: Massive numbers (Why we use strings instead of long long)
    string num5 = "12345678901234567890";
    string num6 = "98765432109876543210";
    cout << num5 << " + " << num6 << "\n= " << addstring(num5, num6) << "\n";

    return 0;
}