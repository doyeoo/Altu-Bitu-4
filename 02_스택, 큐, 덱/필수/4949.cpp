#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool isBalanced(string sen){
    stack<char> s;

    for(int i=0; i<sen.size(); i++){
        char tmp=sen[i];

        switch (tmp) {
            //여는 괄호 push
            case '(': case '[':
                s.push(tmp);
                break;
            case ']':
                //닫는 괄호가 더 많은 경우는 여기에 걸림(=비었는데 닫는 괄호 남아있을 때)
                if(s.empty() || s.top() != '[') {
                    return false;
                }
                //가장 최근에 넣은 괄호랑 짝 맞으면 스택에서 제거
                s.pop();
                break;
            case ')':
                //여기랑
                if(s.empty() || s.top() != '(') {
                    return false;
                }
                //얘도
                s.pop();
                break;
        }
    }

    //스택 true
    if(s.empty()){
        return true;
    } else {
        return false;
    }
}

int main() {
    string sen;

    while(true) {
        getline(cin, sen);

        if(sen==".") {
            break;
        }

        if(isBalanced(sen)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}