#include<iostream>
using namespace std;

#define SIZE 10

class Queue {
    string patrons[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string name) {
        if(isFull()) {
            cout<<"Queue is full. No more patrons can be added."<<endl;
            return;
        }
        if(front == -1) front = 0;
        rear++;
        patrons[rear] = name;
        cout<<name<<" has been added to the queue."<<endl;
    }

    void dequeue() {
        if(isEmpty()) {
            cout<<"Queue is empty. No patron to remove."<<endl;
            return;
        }
        cout<<patrons[front]<<" has completed the transaction and left the queue."<<endl;
        front++;
    }

    void display() {
        if(isEmpty()) {
            cout<<"No patrons waiting in queue."<<endl;
            return;
        }
        cout<<"Current patrons in queue:"<<endl;
        for(int i=front; i<=rear; i++) {
            cout<<i - front + 1<<". "<<patrons[i]<<endl;
        }
    }
};

int main() {
    Queue q;
    int choice;
    string name;

    do {
        cout<<"\n--- Library Queue Management ---"<<endl;
        cout<<"1. Add Patron to Queue"<<endl;
        cout<<"2. Complete Transaction (Remove Patron)"<<endl;
        cout<<"3. Display Queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter patron name: ";
                cin>>name;
                q.enqueue(name);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout<<"Exiting program..."<<endl;
                break;
            default:
                cout<<"Invalid choice."<<endl;
        }
    } while(choice != 4);

    return 0;
}
