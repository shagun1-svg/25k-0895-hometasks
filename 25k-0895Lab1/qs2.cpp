#include <iostream>
using namespace std;

class Box {
private:
    int* volume;
public:
    Box() {
        volume = new int(0);
    }

    Box(int v) {
        volume = new int(v);
    }

    Box(const Box& other) {
        volume = new int(*other.volume);
    }

    ~Box() {
        delete volume;
    }

    void setVolume(int v) {
        *volume = v;
    }

    void display() {
        cout << "Box Volume: " << *volume << endl;
    }
};

int main() {
    Box b1;
    cout << "b1: ";
    b1.display();

    Box b2(50);
    cout << "b2: ";
    b2.display();

    Box b3 = b2;
    b3.setVolume(100);

    cout << "\nAfter modifying b3:\n";
    cout << "b2 : ";
    b2.display();
    cout << "b3 : ";
    b3.display();

    return 0;
}
