
#include <stdio.h>
#include <stdlib.h> // want to use malloc

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data, struct node *next);
void print_list(struct node *head);
struct node *insert_at_tail(int data, struct node *head);

int main(void) {

    struct node *head = create_node(7, NULL);
    head = create_node(8, head);
    head = create_node(11, head);

    print_list(head);

    insert_at_tail(12, head);
    print_list(head);

    // Testing the empty list case (see comments in insert_at_tail function)
    // struct node *head2 = NULL;
    // head2 = insert_at_tail(8, head2);
    // print_list(head2);

    return 0;
}

struct node *create_node(int data, struct node *next) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = next;

    return new;
}

void print_list(struct node *head) {
    printf("The linked list: \n");
    
    struct node *current = head;

    // keep looping until we reach the end of the linked list
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

}

struct node *insert_at_tail(int data, struct node *head) {
    // NOTE: This function coded in wk7 lecture 2 works for this particular code 
    // example,
    // However, it is not quite complete.
    // That is, we are missing:
    // If the given list is empty, we will need to insert at the end differently
    // if (head == NULL) {
    //     head = malloc(sizeof(struct node));
    //     head->data = data;
    //     head->next = NULL;
    //     return head;
    // }

    struct node *current = head;

    // traverse the list until we get to the last node
    while (current->next != NULL) {
        current = current->next;
    }
    // current should be pointing at the last node in the list atm
    current->next = create_node(data, NULL);

    return head;
}