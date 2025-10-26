#include<iostream>
#include<cmath>
#include<cctype>
using namespace std;

class Stack {
    int arr[100];
    int topIndex;
public:
    Stack() {
        topIndex = -1;
    }

    void push(int val) {
        arr[++topIndex] = val;
    }

    void pop() {
        if(topIndex >= 0)
            topIndex--;
    }

    int top() {
        return arr[topIndex];
    }

    bool empty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack s;
    string exp;
    cout<<"Enter prefix expression: ";
    cin>>exp;

    for(int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];
        if(isdigit(ch)) {
            s.push(ch - '0');
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if(s.size() < 2) {
                cout<<"Invalid Expression"<<endl;
                return 0;
            }

            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            int result;

            if(ch == '+') result = a + b;
            else if(ch == '-') result = a - b;
            else if(ch == '*') result = a * b;
            else if(ch == '/') result = a / b;
            else if(ch == '^') result = pow(a, b);

            s.push(result);
        }
        else {
            cout<<"Invalid Character in Expression"<<endl;
            return 0;
        }
    }

    if(s.size() == 1)
        cout<<"Final Result: "<<s.top()<<endl;
    else
        cout<<"Invalid Expression"<<endl;

    return 0;
}
