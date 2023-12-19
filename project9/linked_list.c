//->11->8->7->x

#include <stdio.h>
#include <stdlib.h>
struct node *create_node(int data, struct node *next);
struct node *insert_at_tail(int data, struct node *head);
//function to give us the size of list
int size_ll(struct node *head);
//function to insert at location
struct node *insert_at_middle(int data, int location, struct node *head);
//Let's build a node...
void print_list(struct node *head);
struct node *delete_node_from_tail (struct node *head);
struct node *delete_at_pos (struct node *head, int pos);
//a struct, containing a payload
//and a pointer to another node (the next one)
struct node {
    int data;
    struct node *next;//<-the pointer
};

int main(void) {
    // Create an empty linked list pointer
    struct node *head = NULL;
    
    //insert_at_middle(13, 0, head);
    //head = insert_at_tail(1, head);
    // Create a linked list that goes 1->5
    head = create_node(5, NULL);
    head = create_node(4, head);
    head = create_node(3, head);
    head = create_node(2, head);
    head = create_node(1, head);
    //print_list(head);
    //insert_at_middle(13, 0, head);

    //insert_at_tail(12, head);
    /*print_list(head);
    head = delete_node_from_tail(head);
    print_list(head);
    head = delete_node_from_tail(head);
    print_list(head);
    head = delete_node_from_tail(head);
    print_list(head);
    head = delete_node_from_tail(head);
    print_list(head);
    head = delete_node_from_tail(head);
    head = delete_node_from_tail(head);*/
    //head = delete_at_pos(head, 2);
    print_list(head);
    printf("The size of the list is %d\n", size_ll(head));
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
    
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct node *insert_at_tail(int data, struct node *head) {
    struct node *current = head;
    
    if (head == NULL) {
        head = create_node(data, NULL);
        return head;
    }
    //traverse the list unsti we get to the lase node
    while (current->next != NULL) {
        current = current->next;
    }
    // current should be pointing at the lasr node
    current->next = create_node(data, NULL);
    return head;
}

//function returs size of the list
//input: head of the list
//output int for size of the list
int size_ll(struct node *head) {
    
    struct node *current = head;
    int size = 0;

    // start moving throug the list

    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}  

struct node *insert_at_middle(int data, int location, struct node *head) {
    if (head == NULL) {
        //head = create_node(data, NULL);
        return head;
    }
    struct node *current = head;
    int counter = 1;

    while (current != NULL) {

        if (counter == location) {
            struct node *new_node = create_node(data, NULL);
            new_node->next = current->next;
            current->next = new_node;
            
        }
        counter++;
        current = current->next;
    }
    return head;
}

struct node *delete_node_from_tail (struct node *head) {
    struct node *current = head;
    struct node *previous = NULL;
    if (head == NULL) {
        return NULL;
    }
    //got to the second final node
    while (current->next != NULL) {
        //the actual traversal
        previous = current;
        current = current->next;
    }
    free(current);
    if (previous == NULL) {
        head = NULL;
    } else {
        previous->next = NULL;
    }
    return head;
    //here the current is the second last node
}

struct node *delete_at_pos (struct node *head, int pos) {
    struct node *current = head;
    struct node *previous = NULL;
    int counter = 0;
    if (head == NULL) {
        return NULL;
    }
    //got to the second final node
    while (current->next != NULL) {
        //the actual traversal
        previous = current;
        current = current->next;
        if (counter == pos) {
            //we want to delee
            if (previous == NULL) {
                head = NULL;
            } else {
                if (current != NULL) {
                    previous->next = current->next;
                } else {
                    previous->next = NULL;
                }
            }
            free(current);
            return head;
        }

        counter++;
    }
    return head;
    //here the current is the second last node
}