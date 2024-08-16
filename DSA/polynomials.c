#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Poly
{
    int degree;
    float coeff;
    struct Poly *link;
};

typedef struct Poly poly;

poly *create(poly *head);
poly *insert(poly *head, int co, int ex);
void print(poly* head);
void polyAdd(poly* head1, poly* head2);

int main()
{
    poly *head = NULL;
    printf("enter the polynomial\n");
    head = create(head);

    print(head);
    return 0;

}
void polyAdd(poly* head1, poly* head2){
    poly* ptr1 = head1, *ptr2 = head2, *head3 = NULL;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->degree == ptr2->degree){
            head3 = insert(head3, ptr1->coeff+ptr2->coeff, ptr1->degree);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->degree > ptr2->degree){
            head3 = insert(head3, ptr1->coeff,ptr1->degree);
            ptr1 = ptr1->link;
        }
        else if(ptr1->degree < ptr2->degree){
            head3 = insert(head3, ptr2->coeff, ptr2->degree);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL){
        head3 = insert(head3, ptr1->coeff, ptr1->degree);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL){
        head3 = insert(head3, ptr2->coeff, ptr2->degree);
        ptr2 = ptr2->link;
    }
    printf("\n ADDED polynomial is:");
    print(head3);
}
void print(poly* head){
    if(head == NULL) printf("No polynomial.\n");
    else{
        poly* temp = head;
        while(temp != NULL){
            printf("%.1fx^%d",temp->coeff,temp->degree);
            temp = temp->link;
            if(temp!=NULL) printf(" + ");
            else printf("\n");
        }
    }
}

poly *insert(poly *head, int co, int ex)
{
    poly *temp;
    poly *new = (poly *)malloc(sizeof(poly));
    new->coeff = co;
    new->degree = ex;
    new->link = NULL;

    if (head == NULL || ex > head->degree){
        new->link = head;
        head = new;
    }
    else{
        temp = head;
        while (temp->link != NULL && temp->link->degree > ex)
            temp = temp->link;
            new->link = temp->link;
            temp->link = new; 
    }
    return head;
}
poly *create(poly *head)
{
    int n, i, expo;
    float coeff;

    printf("enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("enter the coefficient for term %d: ", i + 1);
        scanf("%d", &coeff);

        printf("enter the exponent for term %d", i + 1);
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
}
