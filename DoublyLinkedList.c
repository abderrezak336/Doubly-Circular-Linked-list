// Online C compiler to run C program online
//this note for doubly linked liste
#include <stdio.h>
#include <stdlib.h>


//doubly linked list exercises 1
// add new comment 


typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
}Node;





//revers the liste
Node *reverse(Node *head){
    Node *ptr1 = head;
    Node *ptr2 = ptr1->next;
    
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while(ptr2 != NULL){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
        
    }
    head = ptr1;
    return head;
}


//this function insert a node at the end
Node *InsertAtEnd(Node *head, int value){
    Node *New_node = malloc(sizeof(Node));
    New_node->data = value;
    New_node->next = NULL;
    New_node->prev = NULL;
    Node *pr = head;
    while(pr->next != NULL){
        pr = pr->next;
    }
    pr->next = New_node;
    New_node->prev = pr;
    return head;
    
    
    
}

//delete a node at particualar pos
Node *deletePos(Node *head, int pos){
    Node *temp = head;
    Node *temp2 = NULL;
    while(pos > 1){
        temp = temp->next;
        pos--;
    }
    temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    temp = NULL;
    return head;
    
}


//this function add node at certain position 
Node *AddAfterPos(Node *head, int value, int pos){
    Node *NewP = malloc(sizeof(Node));
    Node *temp1 = head;
    Node *temp2 = NULL;
    NewP->data = value;
    NewP->prev = NULL;
    NewP->next = NULL;
    while(pos != 1){
        temp1 = temp1->next;
        pos--;
    }
    temp2 = temp1->next;
    temp1->next = NewP;
    temp2->prev = NewP;
    NewP->next = temp2;
    NewP->prev = temp1;
    return head;
}


//this function add node at beginning of liste
Node *InsertAtBegin(Node *head, int value){
    Node *New_node = malloc(sizeof(Node));
    New_node->data = value;
    New_node->prev = NULL;
    New_node->next = NULL;
    New_node->next = head;
    head = New_node;
    return head;
}




//this function creat a liste of nodes 
Node *create_liste(Node *head){
    int i;
    int data;
    int n;
    printf("enter the number of nodes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("enter the element for node %d: ", i+1);
        scanf("%d", &data);
        head = InsertAtEnd(head, data);
    }
    return head;
    
}



//this function print all data in liste
void print_data(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}




int main() {
    // practice doubly linked liste
    Node *head = malloc(sizeof(Node));
    head->prev = NULL;
    head->data = 40;
    head->next = NULL;
    head = create_liste(head);
    // head = InsertAtBegin(head, 100);
    // head = AddAfterPos(head, 88, 2);
    // head = deletePos(head, 2);
    print_data(head);
    printf("here is the data after reversed\n");
    head = reverse(head);
    print_data(head);


    return 0;
}
