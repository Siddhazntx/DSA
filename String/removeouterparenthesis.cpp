#include <iostream>
#include <vector>
using namespace std;

string removeOuterParentheses(string s){
    if(s.size() == 0) return "";

    int depth = 0;
    string ans = "";

    for(char ch : s){
        if(ch == '('){
            depth++;
            if(depth > 1) ans+=ch;
        }
        else{
        depth--;
        if(depth>0) ans+=ch;
    }
}
    return ans;
}



int main() {
    // Test Case 1
    string s1 = "(()())(())";
    cout << "Original: " << s1 << "\n";
    cout << "Result:   " << removeOuterParentheses(s1) << "\n\n";
    // Expected: "()()()"

    // Test Case 2
    string s2 = "(()())(())(()(()))";
    cout << "Original: " << s2 << "\n";
    cout << "Result:   " << removeOuterParentheses(s2) << "\n";
    // Expected: "()()()()(())"
    
    return 0;
}