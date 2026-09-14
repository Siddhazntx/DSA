#include <iostream>
#include <vector>
using namespace std;

void reverse(string& s,int low,int high){
    int n = s.size();


    while(low <= high){
        swap(s[low], s[high]);
        low++;
        high--;
    }
}
void rotatestring(string& s, int k){
    int n = s.size();
    if(s.empty()) return;

    k = k%n;

    reverse(s, 0, k-1);
    reverse(s, k, n-1);
    reverse(s, 0, n-1);
}

int main() {
    string s = "abcdefg";
    int k = 2;

    cout << "Original: " << s << "\n";
    
    rotatestring(s, k);
    
    cout << "Rotated:  " << s << "\n";
    // Expected output: cdefgab
    
    return 0;
}