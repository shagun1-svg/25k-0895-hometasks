#include<iostream>
using namespace std;

struct Node {
    string url;
    Node* next;
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void addFront(string site) {
        Node* newNode = new Node;
        newNode->url = site;
        newNode->next = head;
        head = newNode;
    }

    void removeFront() {
        if(head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display() {
        Node* temp = head;
        cout<<"Current Browsing History (most recent first): ";
        while(temp != NULL) {
            cout<<temp->url<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

class Stack {
    string arr[100];
    int topIndex;
public:
    Stack() {
        topIndex = -1;
    }

    void push(string site) {
        arr[++topIndex] = site;
    }

    void pop() {
        if(topIndex >= 0)
            topIndex--;
    }

    string top() {
        if(topIndex >= 0)
            return arr[topIndex];
        return "";
    }

    bool empty() {
        return topIndex == -1;
    }
};

int main() {
    LinkedList history;
    Stack backStack;

    string sites[5] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};

    for(int i=0;i<5;i++) {
        history.addFront(sites[i]);
        backStack.push(sites[i]);
    }

    cout<<"After visiting 5 websites:"<<endl;
    history.display();

    cout<<"\nUser clicks BACK twice..."<<endl;
    for(int i=0;i<2;i++) {
        if(!backStack.empty()) {
            backStack.pop();
            history.removeFront();
        }
    }

    cout<<"\nAfter going back twice:"<<endl;
    history.display();

    cout<<"Current page: "<<backStack.top()<<endl;

    return 0;
}
