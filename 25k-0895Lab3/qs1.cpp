
#include <iostream>
using namespace std;

class Node {
public:
    string item;
    int price;
    Node* next;
    Node(string i, int p) {
        item = i;
        price = p;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertFront(string item, int price) {
        Node* newNode = new Node(item, price);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(string item, int price) {
        Node* newNode = new Node(item, price);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAfter(string target, string item, int price) {
        Node* temp = head;
        while (temp && temp->item != target) temp = temp->next;
        if (temp) {
            Node* newNode = new Node(item, price);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void searchItem(string target) {
        Node* temp = head;
        while (temp) {
            if (temp->item == target) {
                cout << target << " price: $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << target << " not found" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->item << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void createInitialList() {
        head = new Node("Laptop", 1000);
        head->next = new Node("Phone", 700);
        head->next->next = new Node("Tablet", 400);
        head->next->next->next = new Node("Headphones", 150);
    }
};

int main() {
    LinkedList cart;
 l1.createInitialList();
 l1.insertFront("Smartwatch", 200);
 l1.insertEnd("Keyboard", 80);
 l1.insertAfter("Phone", "Monitor", 300);
 l1.searchItem("Tablet");
 l1.display();
    return 0;
}
