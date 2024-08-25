#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int row, col, value;
    struct node* next;
} node;

node* createMatrix(int row, int col, int value){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void insert(node **head, int row, int col, int value){
    node* newNode = createMatrix(row,col,value);
    newNode->next = *head;
    *head = newNode;
}
void print(node *head){
    node* ptr = head;
    while(ptr!=NULL){
        printf("r:%d,c:%d,val:%d\n",ptr->row, ptr->col,ptr->value);
        ptr = ptr->next;
    }
}

node* multiply(node* M1, node* M2, int row1, int col1, int col2){
    node *ptr1 = M1, *ptr2 ;
    node* productM;
    
    while(ptr1!=NULL){
        ptr2 = M2;
        while(ptr2!=NULL){
            if(ptr1->col == ptr2->row){
                int row = ptr1->row;
                int col = ptr2->col;
                int value = ptr1->value*ptr->value;
                
                node* temp = productM;
                bool found = false;
                
                while(temp!=NULL){
                    if(temp->row == row && temp->col == col){
                        temp->value += value;
                        found = true;
                        break;
                    }
                    temp = temp->next;
                }
                if(!found)
                    insert(&productM,row,col,value)
            }
            
            ptr2 = ptr2->next;
        }
        
        ptr1 = ptr1->next;
    }
    return productM;
}


int main(){
    node* matrix1 = NULL;
    insert(&matrix1, 0, 0, 1);
    insert(&matrix1, 0, 2, 2);
    insert(&matrix1, 1, 1, 3);
    print(matrix1);
    return 0;
}
