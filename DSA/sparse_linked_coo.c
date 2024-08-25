#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int row, col, value;
    struct Node* next;
} node;

node* create(int row, int col, int value){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}
void insert(node** head, int row, int col, int value){
    node* newNode = create(row,col,value);
    if(*head == NULL)
        *head = newNode;
    else{
        node* temp = *head;
        while(temp->next != NULL) temp = temp -> next;
        temp->next = newNode;
    }
}
void print(node *head){
    node* tmep = head;
    while(temp!=NULL){
        printf("r: %d r: %d value: %d\n",
        temp->row,
        temp->col,
        temp->value);
        temp = temp->next;
    }
}
node* multiply(node* M1, node* M2){
    node* temp1 = M1, *temp2, *result = NULL;
    while(temp1!=NULL){
        temp2 = M2;
        while(temp2 != NULL){
            
            if(temp1->col == temp2->row){
                int row = temp1->row, col = temp2->col;
                int value = temp1->value*temp2->value;
                int found = 0;
                node* temp = result;
                while(temp!=NULL){
                    if(temp->row == row && temp->col == col){
                        temp->value += value;
                        found = 1;
                        break;
                    }
                    temp = temp->next;
                }
                if(!found) insert(&result,row,col,value);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}
node* add(node* M1, node* M2){
    node* result = NULL, *ptr1 = M1, *ptr2 = M2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->row == ptr2-row && ptr1->col == ptr2->col){
            int sum = ptr1->value+ptr2->value;
            if(sum != 0) insert(&result, ptr1->row, ptr1->col, sum);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->row < ptr2->row|| (ptr1->row == ptr2->row && ptr1->col < ptr2->col)){
            insert(&result, ptr1->row, ptr1->col, ptr1->value);
            ptr1 = ptr1->next;
        }
        else{
            insert(&result, ptr2->row, ptr2->col, ptr2->value);
            ptr2 = ptr2->next;
        }   
    }
    while(ptr1 != NULL){
        insert(&result, ptr1->row, ptr1->col, ptr1->value);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL){
        insert(&result, ptr2->row, ptr2->col, ptr2->value);
        ptr2 = ptr2->next;
    }
    return result;
}
node* sub(node* M1, node* M2){
    node* result = NULL, *ptr1 = M1, *ptr2 = M2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->row == ptr2-row && ptr1->col == ptr2->col){
            int sum = ptr1->value-ptr2->value;
            if(sum != 0) insert(&result, ptr1->row, ptr1->col, sum);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->row < ptr2->row|| (ptr1->row == ptr2->row && ptr1->col < ptr2->col)){
            insert(&result, ptr1->row, ptr1->col, ptr1->value);
            ptr1 = ptr1->next;
        }
        else{
            insert(&result, ptr2->row, ptr2->col, ptr2->value);
            ptr2 = ptr2->next;
        }   
    }
    while(ptr1 != NULL){
        insert(&result, ptr1->row, ptr1->col, ptr1->value);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL){
        insert(&result, ptr2->row, ptr2->col, ptr2->value);
        ptr2 = ptr2->next;
    }
    return result;
}
int main() {
    node* mat1 = NULL;
    node* mat2 = NULL;

    // Example: Sparse matrix 1
    insert(&mat1, 0, 0, 5);
    insert(&mat1, 1, 1, 8);
    insert(&mat1, 2, 2, 3);

    // Example: Sparse matrix 2
    insert(&mat2, 0, 0, 2);
    insert(&mat2, 1, 1, -8);
    insert(&mat2, 2, 0, 6);

    // Add the two sparse matrices
    node* result = add(mat1, mat2);

    // Print the result
    printf("Resultant Sparse Matrix:\n");
    print(result);
    
    node* result = multiply(mat1, mat2);

    // Print the result
    printf("Resultant Sparse Matrix:\n");
    print(result);


    return 0;
    return 0;
}
