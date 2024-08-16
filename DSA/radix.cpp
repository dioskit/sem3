#include <iostream>
using namespace std;

void RadixSort(int arr[], int size);
int getMax(int arr[], int size);
void countingSort(int arr[], int size, int div);

int main() {
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " integers in any order:" << endl;

    for (int i = 0; i < size; i++) 
        cin >> arr[i];
    
    cout << endl << "Before sorting:" << endl;
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " ";

    RadixSort(arr, size); // radix sort called here

    cout << endl << "After sorting: " << endl;
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " ";

    return 0;
}

int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)  // Start from 1 because max is initialized to arr[0]
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int size, int div) {
    int output[size];  // Output array
    int count[10] = {0};  // Count array to store occurrences of digits (0 to 9)

    // Store count of occurrences of each digit
    for (int i = 0; i < size; i++) 
        count[(arr[i] / div) % 10]++;
    
    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1];

    // Build the output array by placing elements in correct positions
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++) 
        arr[i] = output[i];
}

void RadixSort(int arr[], int size) {
    int m = getMax(arr, size);

    // Apply counting sort to sort elements based on every digit
    for (int div = 1; m / div > 0; div *= 10) {
        countingSort(arr, size, div);
    }
}
