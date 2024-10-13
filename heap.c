#include<stdio.h>
#include <stdlib.h>

#define MAX 100
int heap_size = 0;

void insert(int* arr, int value);
int max(int* arr);
int extract_max(int* arr);
void increase_key(int* arr, int i, int new_val);
void print(int* arr);
void build_max_heap(int* arr);
void max_heapify(int* arr, int i);

int main() {
    int heap[MAX];
    
    // Example heap insertion (initial heap is empty)
    for(int i = 0; i < 10; i++){
        insert(heap, rand() % 100);  // inserting random values
    }

    print(heap);  // print the heap after insertion

    printf("\nMax value: %d\n", extract_max(heap));  // Extract and print max

    print(heap);  // print the heap after extraction
    
    return 0;
}

// Insert a new element into the heap
void insert(int* arr, int value) {
    heap_size++;
    int i = heap_size - 1;
    arr[i] = value;

    // Fix the max heap property if it is violated
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Get the maximum value from the heap
int max(int* arr) {
    return arr[0];  // root of the heap
}

// Extract the maximum element (root) from the heap
int extract_max(int* arr) {
    if (heap_size <= 0) return -1;  // heap is empty
    if (heap_size == 1) {
        heap_size--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[heap_size - 1];
    heap_size--;
    max_heapify(arr, 0);  // maintain max-heap property

    return root;
}

// Increase the value of element at index i to new_val
void increase_key(int* arr, int i, int new_val) {
    arr[i] = new_val;

    // Fix the max heap property if it is violated
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Print the current heap
void print(int* arr) {
    printf("Current heap: ");
    for (int i = 0; i < heap_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Build max heap from an unsorted array
void build_max_heap(int* arr) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        max_heapify(arr, i);
    }
}

// Heapify a subtree rooted at index i
void max_heapify(int* arr, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < heap_size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        max_heapify(arr, largest);  // recursively heapify the affected subtree
    }
}
