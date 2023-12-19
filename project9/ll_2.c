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
struct node *weave_lists(struct node *head_1, struct node *head_2);
struct node *weave_lists_jake(struct node *head_1, struct node *head_2);
struct node *take_max_of_pair(struct node *head_1, struct node *head_2);

int main(int argc, char *argv[]) {
  // Create an empty linked list pointer
  struct node *head = NULL;
  struct node *head_2 = NULL;

  // create a linked list that goes 1 -> 5
  head = create_node(9, NULL);
  head = create_node(7, head);
  head = create_node(5, head);
  head = create_node(3, head);
  head = create_node(1, head);

  head_2 = create_node(14, NULL);
  head_2 = create_node(12, head_2);
  head_2 = create_node(10, head_2);
  head_2 = create_node(8, head_2);
  head_2 = create_node(6, head_2);
  head_2 = create_node(4, head_2);
  head_2 = create_node(2, head_2);

  print_list(head);

//   struct node *weaved = weave_lists_jake(head, head_2);
  struct node *max = take_max_of_pair(head, head_2);
  printf("max:\n");
  print_list(max);

  return 0;
}

// iterate over two LLs in pairs
// create a new LL with the larger of the two pairs
// always the same size
struct node *take_max_of_pair(struct node *head_1, struct node *head_2) {
  struct node *current_1 = head_1;
  struct node *current_2 = head_2;

  struct node *result = NULL;

  // while there is data in both pairs of lls
  // as soon as one list is null, we stop looping
  while (current_1 != NULL && current_2 != NULL) {
    if (current_1->data >= current_2->data) {
      result = insert_at_tail(current_1->data, result);
    } else {
      // else result_2 has the larger value, so add it instead
      result = insert_at_tail(current_2->data, result);
    }

    current_1 = current_1->next;
    current_2 = current_2->next;
  }
  return result;
}

struct node *weave_lists_jake(struct node *head_1, struct node *head_2) {
  struct node *current_1 = head_1;
  struct node *current_2 = head_2;

  struct node *result = NULL;

  while (current_1 != NULL && current_2 != NULL) {
    result = insert_at_tail(current_1->data, result);
    result = insert_at_tail(current_2->data, result);

    current_1 = current_1->next;
    current_2 = current_2->next;
  }

  while (current_1 != NULL) {
    result = insert_at_tail(current_1->data, result);
    current_1 = current_1->next;
  }

  while (current_2 != NULL) {
    result = insert_at_tail(current_2->data, result);
    current_2 = current_2->next;
  }

  return result;
}

struct node *weave_lists(struct node *head_1, struct node *head_2) {
  struct node *head = NULL;
  struct node *current_1 = head_1;
  struct node *current_2 = head_2;

  for (int i = 0; i < 2 * (size_ll(head_1)); i++) {
    if (!(i % 2)) {
      head = insert_at_tail(current_1->data, head);
      current_1 = current_1->next;
    } else {
      head = insert_at_tail(current_2->data, head);
      current_2 = current_2->next;
    }
  }

  return head;
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