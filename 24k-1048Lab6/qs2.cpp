#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

class Stack {
    vector<int> arr;
public:
    void push(int val) {
        arr.push_back(val);
    }

    void pop() {
        if(arr.size()>0)
            arr.pop_back();
    }

    int top() {
        return arr[arr.size()-1];
    }

    bool empty() {
        return arr.size()==0;
    }

    int size() {
        return arr.size();
    }
};

int main() {
    Stack s;
    string exp;
    cout<<"Enter postfix expression: ";
    cin>>exp;

    for(int i=0;i<exp.size();i++) {
        char ch = exp[i];
        if(isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            if(s.size()<2) {
                cout<<"Invalid Expression"<<endl;
                return 0;
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result;
            if(ch=='+') result = a + b;
            else if(ch=='-') result = a - b;
            else if(ch=='*') result = a * b;
            else if(ch=='/') result = a / b;
            else {
                cout<<"Invalid Operator"<<endl;
                return 0;
            }
            s.push(result);
        }
    }

    if(s.size()==1)
        cout<<"Final Result: "<<s.top()<<endl;
    else
        cout<<"Invalid Expression"<<endl;

    return 0;
}
