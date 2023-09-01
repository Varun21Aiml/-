#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(vector<int>& arr) {
    int n = arr.size();

   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

   
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int choice, n;

    cout << "Choose an option:\n";
    cout << "1. Manual entry of array elements\n";
    cout << "2. Generate array elements using random number generator\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the array elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        auto start = chrono::high_resolution_clock::now();
        heapSort(arr);
        auto end = chrono::high_resolution_clock::now();

        cout << "Sorted array:\n";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << "\n";

        chrono::duration<double> duration = end - start;
        cout << "Time taken: " << duration.count() << " seconds\n";
    } else if (choice == 2) {
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> arr(n);
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(1, 10000);
        for (int i = 0; i < n; i++) {
            arr[i] = distribution(generator);
        }

        auto start = chrono::high_resolution_clock::now();
        heapSort(arr);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        cout << "Time taken: " << duration.count() << " seconds\n";
    } else {
        cout << "Invalid choice\n";
    }

    return 0;
}
