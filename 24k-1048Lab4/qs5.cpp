#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter  size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter  elements of array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    int x;
    cout << "Enter value to search: ";
    cin >> x;

    int index = binarySearch(arr, n, x);
    if (index != -1) cout << "Found at index " << index;
    else cout << "Notfound";
}
