#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to get the maximum length of strings in the array
int getMaxLen(char **nums, int size) {
    int maxLen = 0;
    for (int i = 0; i < size; i++) {
        int len = strlen(nums[i]);
        if (len > maxLen) {
            maxLen = len;
        }
    }
    return maxLen;
}

// Function to perform counting sort based on a specific digit
void countingSort(char **arr, int size, int exp, int maxLen) {
    char *output[size];
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < size; i++) {
        int digit = (arr[i][maxLen - exp] - '0');
        count[digit]++;
    }

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i][maxLen - exp] - '0');
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(char **arr, int size, int maxLen) {
    for (int exp = 1; exp <= maxLen; exp++) {
        countingSort(arr, size, exp, maxLen);
    }
}

// Function to trim strings and store them in separate arrays
void trimStrings(char **nums, int size, int maxLen, char ***trimmedArrays) {
    for (int len = 1; len <= maxLen; len++) {
        for (int i = 0; i < size; i++) {
            trimmedArrays[len - 1][i] = (char *)malloc((len + 1) * sizeof(char));
            strncpy(trimmedArrays[len - 1][i], &nums[i][maxLen - len], len);
            trimmedArrays[len - 1][i][len] = '\0';
        }
    }
}

// Function to find the k-th smallest element
char* findKthSmallest(char **arr, int size, int k) {
    return arr[k - 1];
}

int main() {
    char *nums[] = {"102", "473", "251", "814"};
    int size = sizeof(nums) / sizeof(nums[0]);
    int maxLen = getMaxLen(nums, size);

    // Allocate memory for trimmed arrays
    char ***trimmedArrays = (char ***)malloc(maxLen * sizeof(char **));
    for (int i = 0; i < maxLen; i++) {
        trimmedArrays[i] = (char **)malloc(size * sizeof(char *));
    }

    // Trim strings
    trimStrings(nums, size, maxLen, trimmedArrays);

    // Sort each trimmed array and find the k-th smallest element
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    for (int len = 1; len <= maxLen; len++) {
        radixSort(trimmedArrays[len - 1], size, len);
        char *kthSmallest = findKthSmallest(trimmedArrays[len - 1], size, k);
        printf("The %d-th smallest element in Trim%d is: %s\n", k, len, kthSmallest);
    }

    // Free allocated memory
    for (int i = 0; i < maxLen; i++) {
        for (int j = 0; j < size; j++) {
            free(trimmedArrays[i][j]);
        }
        free(trimmedArrays[i]);
    }
    free(trimmedArrays);

    return 0;
}
