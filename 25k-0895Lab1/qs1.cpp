#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
private:
    string* authors; 
    int count;       
public:
    
    ResearchPaper(int n) {
        count = n;
        authors = new string[count];
    }


    ~ResearchPaper() {
        delete[] authors;
    }

    
    ResearchPaper(const ResearchPaper& other) {
        count = other.count;
        authors = new string[count];
        for (int i = 0; i < count; i++) {
            authors[i] = other.authors[i];
        }
    }

    
    ResearchPaper& operator=(const ResearchPaper& other) {
        if (this != &other) {
            delete[] authors;  
            count = other.count;
            authors = new string[count];
            for (int i = 0; i < count; i++) {
                authors[i] = other.authors[i];
            }
        }
        return *this;
    }


    void setAuthor(int index, string name) {
        if (index >= 0 && index < count)
            authors[index] = name;
    }

    
    void display() {
        cout << "Authors: ";
        for (int i = 0; i < count; i++)
            cout << authors[i] << (i == count - 1 ? "" : ", ");
        cout << endl;
    }
};

int main() {
    ResearchPaper rp1(2);
    rp1.setAuthor(0, "Alice");
    rp1.setAuthor(1, "Bob");

    cout << "Original ResearchPaper (rp1):\n";
    rp1.display();

    ResearchPaper rp2 = rp1; 
    rp2.setAuthor(0, "Charlie");

    cout << "\nAfter modifying rp2:\n";
    cout << "rp1 : ";
    rp1.display();
    cout << "rp2 :";
    rp2.display();

    return 0;
}
