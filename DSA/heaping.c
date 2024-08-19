/*******
 * left child has index 2i
 * right chile has index 2i+1
 * parent has i/2
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity);
void swap(int *a, int* b);
int parent(int i){return (i-1)/2;}
int leftChild(int i){return 2*i+1;}
int rightChild(int i){return 2*i+2;}

void heapify(MaxHeap *heap, int i){
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if(left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;
    if(right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;
    if(largest != i){
        swap(&heap->array[i],&heap->array[i]);
        heapify(heap, largest);
    }
    
}
void insert(MaxHeap *heap, int key){
    if(heap->size == heap->capacity){
        printf("heap is full\n");
        return;
    }

    int i = heap->size++;
    heap->array[i] = key;

    while(i != 0 && heap->array[parent(i)] < heap->array[i]){
        swap(&heap->array[i],&heap->array[parent(i)]);
        i = parent(i);

    }
}

int getMax(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    return heap->array[0];
}

int extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    if (heap->size == 1) {
        return heap->array[--heap->size];
    }

    // Store the maximum value, replace the root with the last element, and heapify
    int root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    heapify(heap, 0);

    return root;
}

void printHeap(MaxHeap *heap) {
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

void freeMaxHeap(MaxHeap *heap) {
    free(heap->array);
    free(heap);
}


int main() {
    int capacity = 10;
    MaxHeap *heap = createMaxHeap(capacity);

    insert(heap, 3);
    insert(heap, 2);
    insert(heap, 15);
    insert(heap, 5);
    insert(heap, 4);
    insert(heap, 45);

    printHeap(heap);

    printf("Extracted max: %d\n", extractMax(heap));
    printHeap(heap);

    printf("Max element is %d\n", getMax(heap));

    freeMaxHeap(heap);
    return 0;
}

MaxHeap* createMaxHeap(int capacity){
    MaxHeap *heap = (MaxHeap*) malloc(sizeof(MaxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity*sizeof(int));
    return heap;
}

void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
