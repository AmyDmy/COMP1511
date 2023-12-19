// [12:29 pm] Jake Renzella
#include <stdio.h>
#include <stdlib.h>
 
// a struct, containing a payload
// and a pointer to another node (the next one)
struct node {
  int data;
  struct node *next;  // <- the pointer
};
 
void print_list(struct node *head);
struct node *create_node(int data, struct node *next);
struct node *insert_at_tail(int data, struct node *head);
int size_ll(struct node *head);
struct node *insert_at_loc(int data, int location, struct node *head);
struct node *delete_node_from_tail(struct node *head);
struct node *delete_at_pos(struct node *head, int pos);
 
int main(int argc, char *argv[]) {
  printf("%d\n", argc);
 
  for (int i = 0; i < argc; i++) {
    printf("arg %d is %s\n", i, argv[i]);
  }
  // printf("%d\n", argc);
  struct node *head = NULL;
 
  insert_at_loc(13, 1, head);
  // insert_at_tail(1, head);
  //  Let's create a node!
  head = create_node(5, NULL);
  head = create_node(7, head);
  head = create_node(11, head);
  head = create_node(18, head);
 
  print_list(head);
  printf("The size of the list is %d\n", size_ll(head));
 
  insert_at_loc(13, 1, head);
 
  // insert_at_tail(12, head);
  print_list(head);
 
  head = delete_at_pos(head, 2);
  print_list(head);
  // head = delete_node_from_tail(head);
  // print_list(head);
  // head = delete_node_from_tail(head);
  // print_list(head);
  // head = delete_node_from_tail(head);
  // print_list(head);
  // head = delete_node_from_tail(head);
  // print_list(head);
 
  return 0;
}
 
// This function will create a new node by mallocing some memory
// Input: data, address next
// Output: pointer to that node that I've just created
struct node *create_node(int data, struct node *next) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = next;
  return new_node;
}
 
struct node *delete_at_pos(struct node *head, int pos) {
  struct node *current = head;
  struct node *previous = NULL;
 
  if (head == NULL) {
    return NULL;
  }
 
  int counter = 0;
 
  // get to the final node
  while (current->next != NULL) {
    if (counter == pos) {
      // we want to delete
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
    // the actual traversal
    previous = current;
    current = current->next;
    counter++;
  }
  return head;
}
 
struct node *delete_node_from_tail(struct node *head) {
  struct node *current = head;
  struct node *previous = NULL;
 
  if (head == NULL) {
    return NULL;
  }
 
  // get to the final node
  while (current->next != NULL) {
    // the actual traversal
    previous = current;
    current = current->next;
  }
 
  // here, the current is the last node
  free(current);
 
  if (previous == NULL) {
    head = NULL;
  } else {
    previous->next = NULL;
  }
 
  return head;
}
 
// This function will print out a linked list
// Input: the head of the list
// Output: void (nothing)
void print_list(struct node *head) {
  struct node *current = head;
 
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}
// This function will insert a node at the end of a linked list
// Input: data which to insert, the head of the list
// Output: pointer to the head of the list
 
struct node *insert_at_tail(int data, struct node *head) {
  struct node *current = head;
 
  if (head == NULL) {
    head = create_node(data, NULL);
    return head;
  }
 
  // traverse the list until we get to the last node
  while (current->next != NULL) {
    current = current->next;
  }
  // current should be pointing at the last node in the list atm
  current->next = create_node(data, NULL);
 
  return head;
}
 
// Function returns size of the list
// Input: head of the list
// Output int for size of the list
 
int size_ll(struct node *head) {
  struct node *current = head;
  int size = 0;
 
  // start moving through the list
  while (current != NULL) {
    size++;
    current = current->next;
  }
  // when we exit the loop : current = NULL
 
  return size;
}
 
// this function assumes a non-empty list
struct node *insert_at_loc(int data, int location, struct node *head) {
  if (head == NULL) {
    return head;
  }
 
  struct node *current = head;
 
  int counter = 1;
 
  while (current != NULL) {
    if (counter == location) {
      struct node *new_node = create_node(data, NULL);
 
      new_node->next = current->next;
      current->next = new_node;
      return head;
    }
    counter++;
    current = current->next;
  }
 
  return head;
}