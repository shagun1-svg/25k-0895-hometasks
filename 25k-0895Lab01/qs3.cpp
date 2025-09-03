#include <iostream>
using namespace std;

class Exam {
private:
    int* marks;
    int size;
public:
    Exam(int n) {
        size = n;
        marks = new int[size];
        for (int i = 0; i < size; i++) marks[i] = 0;
    }

    ~Exam() {
        delete[] marks;
    }

    void setMark(int index, int value) {
        if (index >= 0 && index < size)
            marks[index] = value;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << marks[i] << " ";
        cout << endl;
    }
};

int main() {
    Exam e1(3);
    e1.setMark(0, 85);
    e1.setMark(1, 90);
    e1.setMark(2, 75);

    cout << "Original Exam (e1): ";
    e1.display();

    Exam e2 = e1;

    e2.setMark(1, 50);

    cout << "\nAfter modifying e2:\n";
    cout << "e1 : ";
    e1.display();
    cout << "e2 : ";
    e2.display();

    return 0;
}
