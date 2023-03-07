#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool isBalanced(queue<char> &q){
    stack<char> tmp;
    int n=q.size();

    for(int i=0; i<n; i++){
        //처음 들어오는 괄호가 닫는 괄호면 false
        if(tmp.empty() && (q.front()==']' || q.front()==')')) {
            return false;
        }
        //여는 괄호 들어오면 스택에 push
        if(q.front()=='[' || q.front()=='(') {
            tmp.push(q.front());
            q.pop();
        } else {
            //스택 맨 마지막 요소와 짝 맞으면 pop
            if((q.front()==')'&&tmp.top()=='(') || (q.front()==']'&&tmp.top()=='[')) {
                q.pop();
                tmp.pop();
            }
        }
    }

    //둘 다 비었으면 true
    if(q.empty() && tmp.empty()){
        return true;
    } else {
        return false;
    }
}

int main() {
    string sen;
    queue<char> q;

    while(true) {
        getline(cin, sen);

        if(sen==".") {
            break;
        }

        //큐만 괄호에 push
        for(int i=0; i<sen.size(); i++) {
            if(sen[i]=='[' || sen[i]==']' || sen[i]=='(' || sen[i]==')'){
                q.push(sen[i]);
            }
        }

        if(isBalanced(q)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }

        //큐 비우기
        while(!q.empty()) q.pop();
    }

    return 0;
}