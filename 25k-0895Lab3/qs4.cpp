#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string customer;
    string ride;
    Node* next;
    Node(int i, string c, string r) {
        id = i;
        customer = c;
        ride = r;
        next = nullptr;
    }
};

class TicketSystem {
private:
    Node* last;
public:
    TicketSystem() {
        last = nullptr;
    }

    void issueEnd(int id, string customer, string ride) {
        Node* node = new Node(id, customer, ride);
        if (!last) {
            last = node;
            last->next = last;
            return;
        }
        node->next = last->next;
        last->next = node;
        last = node;
    }

    void issueFront(int id, string customer, string ride) {
        Node* node = new Node(id, customer, ride);
        if (!last) {
            last = node;
            last->next = last;
            return;
        }
        node->next = last->next;
        last->next = node;
    }

    void cancelByID(int id) {
        if (!last) return;
        Node* curr = last->next;
        Node* prev = last;
        do {
            if (curr->id == id) {
                if (curr == last && curr == last->next) {
                    delete curr;
                    last = nullptr;
                    return;
                }
                prev->next = curr->next;
                if (curr == last) last = prev;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);
    }

    void cancelFront() {
        if (!last) return;
        Node* first = last->next;
        if (first == last) {
            delete first;
            last = nullptr;
            return;
        }
        last->next = first->next;
        delete first;
    }

    void searchByID(int id) {
        if (!last) return;
        Node* temp = last->next;
        do {
            if (temp->id == id) {
                cout << temp->id << " " << temp->customer << " " << temp->ride << endl;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Not found" << endl;
    }

    void displayAll() {
        if (!last) return;
        Node* temp = last->next;
        do {
            cout << temp->id << " " << temp->customer << " " << temp->ride << endl;
            temp = temp->next;
        } while (temp != last->next);
    }

    int countTickets() {
        if (!last) return 0;
        int c = 0;
        Node* temp = last->next;
        do {
            c++;
            temp = temp->next;
        } while (temp != last->next);
        return c;
    }

    void nextAfter(int id) {
        if (!last) return;
        Node* temp = last->next;
        do {
            if (temp->id == id) {
                cout << temp->next->id << " " << temp->next->customer << " " << temp->next->ride << endl;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Not found" << endl;
    }
};

int main() {
    TicketSystem t;
    t.issueEnd(1, "Ali", "RollerCoaster");
    t.issueEnd(2, "Sara", "FerrisWheel");
    t.issueFront(3, "Ahmed", "PirateShip");

    t.displayAll();
    cout << "Total: " << t.countTickets() << endl;
    t.nextAfter(1);

    return 0;
}
