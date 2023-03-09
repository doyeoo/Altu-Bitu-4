#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

int getPriority(char ch) {
    switch(ch){
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
}

string getPostfix(string input) {
    string result="";
    stack<char> s;

    for(int i=0; i<input.size(); i++) {
        switch(input[i]) {
            case '(':
                s.push(input[i]);
                break;
            //닫는 괄호는 여는 괄호 만날 때까지 계속 pop
            case ')':
                while(s.top()!='(') {
                    result+=s.top();
                    s.pop();
                }
                s.pop();
                break;
            case '+': case '-': case '*': case '/':
                while(!s.empty() && getPriority(input[i])<=getPriority(s.top())) {
                    result+=s.top();
                    s.pop();
                }
                //스택 비었거나 우선순위 더 높은 기호 들어오면 push
                //괄호는 우선순위 제일 낮음
                //괄호 안 기호들 계속 쌓아줘야 하니까
                s.push(input[i]);
                break;
            default:
                result+=input[i];
                break;
        }
    }

    while(!s.empty()) {
        result += s.top();
        s.pop();
    }

    return result;
}

int main() {
    string input;

    cin >> input;

    cout << getPostfix(input);

    return 0;
}