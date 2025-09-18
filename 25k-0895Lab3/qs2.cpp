
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

    void addItemTail(string item, int price) {
        Node* newNode = new Node(item, price);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void searchByName(string target) {
        Node* temp = head;
        while (temp) {
            if (temp->item == target) {
                cout << temp->item << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found" << endl;
    }

    void searchByPosition(int pos) {
        Node* temp = head;
        int count = 1;
        while (temp) {
            if (count == pos) {
                cout << temp->item << " - $" << temp->price << endl;
                return;
            }
            count++;
            temp = temp->next;
        }
        cout << "Invalid position" << endl;
    }

    void displayCart() {
        Node* temp = head;
        while (temp) {
            cout << temp->item << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList cart;
    cart.addItemTail("Cheetos", 1000);
    cart.addItemTail("Snickers", 700);
    cart.addItemTail("Takis", 400);
    cart.addItemTail("Doritos", 150);

    cart.displayCart();
    cout << endl;

    cart.deleteFront();
    cart.displayCart();
    cout << endl;

    cart.searchByName("Cheetos");
    cart.searchByPosition(2);

    return 0;
}

