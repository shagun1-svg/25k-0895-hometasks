#include <iostream>
using namespace std;

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array)/sizeof(array[0]);
    int c = 0;
    for (int i = 0; i < size- 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            c++;
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\nComparisons: " << c;
   return 0;
}