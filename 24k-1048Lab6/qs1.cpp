#include<iostream>
#include<vector>
using namespace std;

class Call {
public:
    string name;
    string number;
    int duration;

    Call(string n, string num, int d) {
        name = n;
        number = num;
        duration = d;
    }
};

class CallHistory {
    vector<Call> stack;
public:
    void push(Call c) {
        stack.push_back(c);
    }

    void pop() {
        if(stack.size()>0)
            stack.pop_back();
        else
            cout<<"No call to delete"<<endl;
    }

    void top() {
        if(stack.size()>0) {
            Call c = stack[stack.size()-1];
            cout<<"Most recent call:"<<endl;
            cout<<"Name: "<<c.name<<", Number: "<<c.number<<", Duration: "<<c.duration<<" mins"<<endl;
        } else {
            cout<<"No recent call"<<endl;
        }
    }

    bool empty() {
        return stack.size()==0;
    }

    void display() {
        if(stack.size()==0) {
            cout<<"Call history is empty"<<endl;
            return;
        }
        cout<<"Current Call Log:"<<endl;
        for(int i=stack.size()-1;i>=0;i--) {
            cout<<stack[i].name<<" | "<<stack[i].number<<" | "<<stack[i].duration<<" mins"<<endl;
        }
    }
};

int main() {
    CallHistory ch;
    int choice;
    while(true) {
        cout<<"\n1. Add Call\n2. Delete Last Call\n3. View Recent Call\n4. Check if Empty\n5. Display All Calls\n6. Exit\n";
        cin>>choice;
        if(choice==1) {
            string name, number;
            int duration;
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter number: ";
            cin>>number;
            cout<<"Enter duration (mins): ";
            cin>>duration;
            Call c(name, number, duration);
            ch.push(c);
            ch.display();
        }
        else if(choice==2) {
            ch.pop();
            ch.display();
        }
        else if(choice==3) {
            ch.top();
        }
        else if(choice==4) {
            if(ch.empty())
                cout<<"Call history is empty"<<endl;
            else
                cout<<"Call history is not empty"<<endl;
        }
        else if(choice==5) {
            ch.display();
        }
        else if(choice==6) {
            break;
        }
        else {
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
