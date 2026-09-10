#include <iostream>
#include <vector>
#include<stack>
using namespace std;

bool isValid(string s){
    
    stack<char>st;

    for(int x : s){
        if(x=='(' || x == '{' || x == '['){
            st.push(x);
        }
        else{
            if(st.empty()) return true;
            char top = st.top();
            st.pop();
            if((x == ')' && top == '(') ||
            (x == '}' && top == '{') ||
            (x == ']' && top == '[' )) return true;
       }
    }  
    return st.empty();
}

int main() {

    string s = "([)]";

    if(isValid(s))
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}