#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} element;
typedef struct {
    int rows;
    int cols;
    int totElements;
    element * elementArray;
} Matrix;

Matrix createMatrix(int rows, int cols, int totElements){
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.totElements = totElements;
    matrix.elementArray = (element* )malloc(totElements*sizeof(element));
    return matrix;
}
//add elements to matrix
void addElement(Matrix *matrix, int index, int row, int col, int value){
    matrix->elementArray[index].row = row;
    matrix->elementArray[index].col = col;
    matrix->elementArray[index].value = value;
}

void print_matrix(Matrix matrix){
    printf("sparse matrix in coo format:\n");
    for(int i = 0; i < matrix.totElements; i++){
        printf(
            "( (%d, %d, %d)\n",
            matrix.elementArray[i].row, 
            matrix.elementArray[i].col,
            matrix.elementArray[i].value
        );
    }
}
void printMatrixFormat(Matrix matrix){
    int k = 0;
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (k < matrix.totElements 
                && matrix.elementArray[k].row == i 
                && matrix.elementArray[k].col == j){
                printf("%d ", matrix.elementArray[k].value);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main() {
    int rows = 4, cols = 5, numElements = 4;
    Matrix matrix = createMatrix(rows, cols, numElements);

    addElement(&matrix, 0, 0, 2, 3);
    addElement(&matrix, 1, 1, 4, 5);
    addElement(&matrix, 2, 3, 1, 2);
    addElement(&matrix, 3, 3, 4, 6);

    print_matrix(matrix);
    printf("\n");
    printMatrixFormat(matrix);
    free(matrix.elementArray);
    return 0;
}
