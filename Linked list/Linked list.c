#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// define the structure of node
struct node{
    int data;
    int key;
    struct node *next;
};


// define global node-variables
struct node *head = NULL;
struct node *current = NULL;


// define function to printList
void printList(){
    struct node *ptr = head;
    
    printf("[ ");
    while(ptr != NULL){
        printf("(%d, %d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}


// define function to find value with key
struct node* searchNode(int key){
    if(head == NULL){
        return NULL;
    }
    
    current = head;
    
    while(current->key != key){
        if(current->next == NULL){
            return NULL;
        } else{
            current = current->next;
        }
    }
    
    return current;
}


// define function for insert at the first position
void insertFirst(int key, int data){
    struct node *link = (struct node*) malloc(sizeof(struct node));
    
    link->key = key;
    link->data = data;
    
    link->next = head;
    head = link;
}


// define function for insert at the last position
void insertLast(int key, int data){
    struct node *link = (struct node*) malloc(sizeof(struct node));
    
    link-> key = key;
    link->data = data;
    link->next = NULL;
    
    current = head;
    
    if(head == NULL){
        head = link;
    } else{
        while(current->next != NULL){
            current = current->next;
        }
        current->next = link;
    }
}


// define function to delete the first node
void deleteFirst(){
    if(head != NULL){
        head = head->next;
    } else{
        printf("List is empty!\n");
    }
}


// define function to delete an item with a given key
void deleteWithKey(int key){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    
    current = head;
    struct node *prev = NULL;
    
    while(current->key != key){
        if(current->next == NULL){
            printf("Data not found for given key!\n");
            return;
        } else{
            prev = current;
            current = current->next;
        }
    }
    
    if(current == head){
        head = head->next;
    } else{
        prev->next = current->next;
    }
    printf("item deleted!\n");
    return;
}


// define function to update a node data with key
void updateWithKey(int key, int data){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    
    current = head;
    
    while(current->key != key){
        if(current->next == NULL){
            printf("no data found for given key!\n");
            return;
        }
        current = current->next;
    }
    
    current->data = data;
    printf("data updated!\n");
    return;
}


// define a function to count the node number
int countLength(){
    if(head == NULL){
        printf("List is empty!\n");
        return 0;
    }
    
    int length = 1;
    current = head;
    
    while(current->next != NULL){
        length++;
        current = current->next;
    }
    
    return length;
}


int main()
{
    insertFirst(3, 10);
    insertFirst(5, 6);
    insertFirst(2, 17);
    printList();
    
    insertLast(11, 14);
    insertLast(12, 15);
    printList();
    
    struct node *temp = searchNode(4);
    if(temp == NULL){
        printf("data not found!\n");
    } else{
        printf("data found!/t|/tdata: %d\n", temp->data);
    }
    
    temp = searchNode(2);
    if(temp == NULL){
        printf("data not found!\n");
    } else{
        printf("data found!\t|\tdata: %d\n", temp->data);
    }
    
    deleteFirst();
    printList();
    
    deleteWithKey(7);
    printList();
    
    deleteWithKey(3);
    printList();
    
    updateWithKey(11, 16);
    printList();
    
    printf("Total node number: %d\n", countLength());

    return 0;
}
