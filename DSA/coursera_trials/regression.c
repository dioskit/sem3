#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_ROWS 1000
float w = 0, b = 0;

void readCSV(const char* filename, int* array1, int* array2, int* rows);
void read_trainCSV(const char* filename, int* array1, int* rows);
void writeCSV(const char* filename,int* trainArray,float *resultArray ,int rows);

// Model functions
float predict(int x);
float cost_function(int* arr_x, int* arr_y, int m);
void opt_gradient_descent(int *arr_x, int* arr_y, int m, float alpha);
void update(int* arr_x, int* arr_y, int m, float alpha);

int main() {
    int array1[MAX_ROWS], array2[MAX_ROWS];
    int trainArray[MAX_ROWS];
    float resultArray[MAX_ROWS];
    int rows = 0;
    int rows2 = 0;

    // Read the CSV file and populate the arrays
    readCSV("input.csv", array1, array2, &rows);
    read_trainCSV("train.csv", trainArray, &rows2); 

    int x;
    printf("Enter x: ");
    scanf("%d", &x);

    float alpha;
    printf("Enter learning rate: ");
    scanf("%f", &alpha);

    // Model training
    update(array1, array2, rows, alpha);
    printf("Model is trained with f(x) = %f*x + %f\n", w, b);

    // writing results
    
    for(int i = 0; i < rows2; i++)
        resultArray[i] = predict(trainArray[i]);
    
    writeCSV("output.csv",trainArray, resultArray, rows2);

    printf("New CSV with results has been created as output.csv\n");

    return 0;
}

void readCSV(const char* filename, int* array1, int* array2, int* rows) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int row = 0;
    while (fscanf(file, "%d,%d", &array1[row], &array2[row]) == 2) {
        row++;
    }

    *rows = row;

    fclose(file);
}
void read_trainCSV(const char* filename,int* trainArray2, int* rows) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int row = 0;
    while (fscanf(file, "%d", &trainArray2[row]) == 1) {
        row++;
    }

    *rows = row;

    fclose(file);
}
void writeCSV(const char* filename,int* trainArray,float *resultArray ,int rows){
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    // Write the new CSV file with a third column containing the predicted values
    for (int i = 0; i < rows; i++)
        fprintf(file, "%d,%.2f\n", trainArray[i], resultArray[i]);
    fclose(file);
}

// Model functions
float predict(int x) {
    return w * x + b;
}
float cost_function(int* arr_x, int* arr_y, int m) {
    float sum = 0;
    for (int i = 0; i < m; i++)
        sum += pow(predict(arr_x[i]) - arr_y[i], 2);
    return (1.0 / (2 * m)) * sum;
}
void opt_gradient_descent(int *arr_x, int* arr_y, int m, float alpha) {
    float derivative_w = 0, derivative_b = 0;
    for (int i = 0; i < m; i++)
        derivative_w += (predict(arr_x[i]) - arr_y[i]) * arr_x[i];
    derivative_w = derivative_w / m;

    for (int i = 0; i < m; i++)
        derivative_b += (predict(arr_x[i]) - arr_y[i]);
    derivative_b = derivative_b / m;

    w -= alpha * derivative_w;
    b -= alpha * derivative_b;
}
void update(int* arr_x, int* arr_y, int m, float alpha) {
    float prev_w, prev_b;
    float current_cost = cost_function(arr_x, arr_y, m);

    while (true) {
        prev_w = w;
        prev_b = b;

        opt_gradient_descent(arr_x, arr_y, m, alpha);

        float new_cost = cost_function(arr_x, arr_y, m);
        if (new_cost >= current_cost) {
            w = prev_w;
            b = prev_b;
            break;
        }
        current_cost = new_cost;
    }
}
