// Online C compiler to run C program online
#include <stdio.h>

typedef struct poly{
    int deg;
    float coeff;
    struct poly* link;
} poly;

poly* create(poly* head);
poly* insert(poly*head, float coeff, int deg);
poly* add(poly* head1, poly* head2);
poly* sub(poly* head1, poly* head2);
poly* multi(poly* head1, poly* head2);
void removeCopies(poly* product);
void print(poly* head);
void freepoly(poly* head);


int main() {
    // Write C code here
    printf("Try programiz.pro");

    return 0;
}
poly* create(poly* head){
    int terms;
    printf("enter number  of terms: ");
    scanf("%d",&terms);
    
    for(int i = 0; i < terms; i++){
        printf("enter exponent: ");
        scanf("%d", &deg);
        printf("enter coefficient: ");
        scanf("%.2f", &coff);
        head = insert(head,coff,deg);
    }
    return head;
}
poly* insert(poly*head, float coeff, int deg){
    poly* newterm = (poly*)malloc(sizeof(poly));
    newterm->coeff = coeff;
    newterm->deg = deg;
    newterm->link = NULL;
    
    if(deg > head->deg || head == NULL){
        newterm->link = head;
        head = newterm;
    }
    else{
        poly* temp = head;
        while(temp->deg > deg) temp = temp->next;
        newterm->link = temp->link;
        temp->link = newterm;
    }
    return head;
}
poly* add(poly* head1, poly* head2){
    poly* temp1 = head1, *temp2 = head2, sum;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->deg == temp2->deg){
            sum = insert(sum,temp1->coeff+temp2->coeff,temp1->deg);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else if(temp1->deg > temp2->deg){
            sum = insert(sum,temp1->coeff,temp1->deg);
            temp1 = temp1->link;
        }
        else{
            sum = insert(sum, temp2->coeff, temp2->deg);
            temp2 = temp2->link
        }
    }
    while(temp1!=NULL){
        sum = insert(sum,temp1->coeff,temp1->deg);
        temp1 = temp1->link;
    }
    while(temp2!=NULL){
        sum = insert(sum, temp2->coeff, temp2->deg);
        temp2 = temp2->link
    }
    return sum;
}
poly* sub(poly* head1, poly* head2){
    poly* temp1 = head1, *temp2 = head2, sum;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->deg == temp2->deg){
            sum = insert(sum,temp1->coeff-temp2->coeff,temp1->deg);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else if(temp1->deg > temp2->deg){
            sum = insert(sum,temp1->coeff,temp1->deg);
            temp1 = temp1->link;
        }
        else{
            sum = insert(sum, temp2->coeff, temp2->deg);
            temp2 = temp2->link
        }
    }
    while(temp1!=NULL){
        sum = insert(sum,temp1->coeff,temp1->deg);
        temp1 = temp1->link;
    }
    while(temp2!=NULL){
        sum = insert(sum, temp2->coeff, temp2->deg);
        temp2 = temp2->link
    }
    return sum;
}
void removeCopies(poly* product){
    poly *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->link != NULL) {
        ptr2 = ptr1;
        while (ptr2->link != NULL) {
            if (ptr1->power == ptr2->link->power) {
                ptr1->coeff += ptr2->link->coeff;
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(dup);
            } else {
                ptr2 = ptr2->link;
            }
        }
        ptr1 = ptr1-linkt;
    }
/*
Step-by-Step Explanation
Initialization:
ptr1 is initialized to the start of the linked list.
ptr2 is used to traverse the list starting from ptr1.

Outer Loop:
The outer loop (while (ptr1 != NULL && ptr1->next != NULL)) iterates through each node in the list using ptr1.

Inner Loop:
The inner loop (while (ptr2->next != NULL)) checks each node following ptr1 using ptr2.

Checking for Duplicates:
If ptr1->power is equal to ptr2->next->power, it means there is a duplicate term.
The coefficients of the duplicate terms are added together (ptr1->coeff += ptr2->next->coeff).

Removing the Duplicate Node:
The duplicate node (ptr2->next) is removed from the list.
ptr2->next is updated to skip the duplicate node (ptr2->next = ptr2->next->next).
The duplicate node is freed from memory (free(dup)).

Moving to the Next Node:
If no duplicate is found, ptr2 moves to the next node (ptr2 = ptr2->next).
After the inner loop completes, ptr1 moves to the next node (ptr1 = ptr1->next)
*/
}
poly* multi(poly* head1, poly* head2){
    poly* temp1 = head1, *temp2 = head2, product = NULL;
    float coeff;
    int expo;
    while(temp1 != NULL){
        while(temp2 != NULL){
            coeff = temp2->coeff*temp1->coeff;
            expo = temp1->deg+temp2->deg;
            product = insert(product, coeff,deg);
            temp2 = temp2->next;
        }
        temp2 = head2;  //reset pointer to head2's head pointer so that is can iterate again
        temp1 = temp->next;
    }
    removeCopies(product);
    return product;
}
void print(poly* head){
    poly* temp = head;
    while(temp->next != NULL){
        printf("%.2fx^%d+",temp->coeff,temp->deg);
        temp = temp->next;
    }
    printf("%.2fx^%d\n",temp->coeff,temp->deg);
}
void freepoly(poly* head){
    if(head == NULL){
        return;
    }
    freepoly(head->next);
    free(head);
}




