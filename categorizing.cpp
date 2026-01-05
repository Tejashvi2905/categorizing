#include <iostream>
using namespace std;

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}

// Merge function for Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search (array must be sorted)
int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// Display Array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[10], n, choice, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Display Array\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            selectionSort(arr, n);
            cout << "Array Sorted using Selection Sort:\n";
            display(arr, n);
            break;

        case 2:
            mergeSort(arr, 0, n - 1);
            cout << "Array Sorted using Merge Sort:\n";
            display(arr, n);
            break;

        case 3:
            cout << "Enter element to search: ";
            cin >> key;
            int pos;
            pos = linearSearch(arr, n, key);
            if (pos != -1)
                cout << "Element found at index " << pos << endl;
            else
                cout << "Element not found!\n";
            break;

        case 4:
            cout << "Enter element to search: ";
            cin >> key;
            pos = binarySearch(arr, 0, n - 1, key);
            if (pos != -1)
                cout << "Element found at index " << pos << endl;
            else
                cout << "Element not found!\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
