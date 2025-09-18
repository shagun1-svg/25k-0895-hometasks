#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string name;
    int price;
    Node* next;
    Node* prev;
    Node(int i, string n, int p) {
        id = i;
        name = n;
        price = p;
        next = prev = nullptr;
    }
};

class doublylinkedlist {
private:
    Node* head;
    Node* tail;
public:
    doublylinkedlist() {
        head = tail = nullptr;
    }

    void addEnd(int id, string name, int price) {
        Node* node = new Node(id, name, price);
        if (!head) {
            head = tail = node;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void addFront(int id, string name, int price) {
        Node* node = new Node(id, name, price);
        if (!head) {
            head = tail = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
    }

    void removeFront() {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    void removeEnd() {
        if (!tail) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void searchByID(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << temp->id << " " << temp->name << " $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not found" << endl;
    }

    void updatePrice(int id, int newPrice) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                temp->price = newPrice;
                return;
            }
            temp = temp->next;
        }
    }

    void showForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->id << " " << temp->name << " $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void showBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->id << " " << temp->name << " $" << temp->price << endl;
            temp = temp->prev;
        }
    }

    int countItems() {
        int c = 0;
        Node* temp = head;
        while (temp) {
            c++;
            temp = temp->next;
        }
        return c;
    }

    void mostExpensive() {
        if (!head) return;
        Node* temp = head;
        Node* maxNode = head;
        while (temp) {
            if (temp->price > maxNode->price) maxNode = temp;
            temp = temp->next;
        }
        cout << maxNode->id << " " << maxNode->name << " $" << maxNode->price << endl;
    }
};

int main() {
    doublylinkedlist d1;
    d1.addEnd(1, "flat", 1000);
    d1.addEnd(2, "car", 700);
    d1.addFront(3, "iphone", 400);

    d1.showForward();
    cout << "Total: " << d1.countItems() << endl;
    d1.mostExpensive();

    return 0;
}
