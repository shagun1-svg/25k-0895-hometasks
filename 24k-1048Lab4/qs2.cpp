#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n, int &c) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            c++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n, int &c) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            c++;
            arr[j + 1] = arr[j];
            j--;
        }
        if (j >= 0) c++;
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &c) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            c++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void combSort(int arr[], int n, int &c) {
    int gap = n;
    bool swapped = true;
    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;
        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            c++;
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    const int n = 20;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = 1 + rand() % 100;

    cout << "Original Array: ";
    printArray(arr, n);

    int b1[n], b2[n], b3[n], b4[n];
    for (int i = 0; i < n; i++) {
        b1[i] = arr[i];
        b2[i] = arr[i];
        b3[i] = arr[i];
        b4[i] = arr[i];
    }

    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    bubbleSort(b1, n, c1);
    cout << "Bubble Sort: ";
    printArray(b1, n);
    cout << "Comparisons: " << c1 << "\n\n";

    insertionSort(b2, n, c2);
    cout << "Insertion Sort: ";
    printArray(b2, n);
    cout << "Comparisons: " << c2 << "\n\n";

    selectionSort(b3, n, c3);
    cout << "Selection Sort: ";
    printArray(b3, n);
    cout << "Comparisons: " << c3 << "\n\n";

    combSort(b4, n, c4);
    cout << "Comb Sort: ";
    printArray(b4, n);
    cout << "Comparisons: " << c4<<"\n";
}
