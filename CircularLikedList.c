/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
}Node;




//add node at end 
Node *add_at_end(Node *tail, int data){
    Node *new_p = malloc(sizeof(Node));
    
    new_p->data = data;
    new_p->next = NULL;
    
    new_p->next = tail->next;
    tail->next = new_p;
    tail = tail->next;
}



//create the tail of liste 
Node *circular_singly(int data){
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp;
    return temp;
}




//to print data in liste
void print_liste(Node *tail){
    Node *p = tail->next;
    do{
        
        printf("%d\n", p->data);
        p = p->next;
        
    }while(p != tail->next);
}




//this function concatenate between two circular linked liste
Node *concatenate(Node *l1, Node *l2){
    Node *ptr = l1->next;
    l1->next = l2->next;
    l2->next = ptr;
    l1 = l2;
    return l1;
}



Node *del_pos(Node *tail, int pos){
    Node *temp = tail->next;
    while(pos > 2){
        temp = temp->next;
        pos--;
    }
    
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    temp2 = NULL;
    return tail;
}





int main()
{
    
    Node *tail;
    Node *tail2;
    Node *l1;
    Node *l2;
    
    tail = circular_singly(9);
    tail = add_at_end(tail, 2);
    tail = add_at_end(tail, 12);
    tail = add_at_end(tail, 17);
    tail = add_at_end(tail, 22);
    l1 = tail;
    tail2 = circular_singly(4);
    tail2 = add_at_end(tail2, 8);
    tail2 = add_at_end(tail2, 7);
    tail2 = add_at_end(tail2, 55);
    tail2 = add_at_end(tail2, 6);
    l2 = tail2;
    // print_liste(concatenate(l1, l2));
    print_liste(del_pos(l1, 3));

    return 0;
}