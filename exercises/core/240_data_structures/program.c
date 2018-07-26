#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
  int data;
  struct node* next;
};

struct node* list_insert_after(struct node** n, int d)
{
  struct node* new_node = malloc(sizeof(struct node));
  if(new_node == NULL)
  {
    fprintf(stderr,"error: malloc failed\n");
    exit(EXIT_FAILURE);
  }
  new_node->next = NULL;
  new_node->data = d;

  // list is empty (return new_node)
  if(n == NULL)
  {}

  // inserting at the tail
  else if((*n)->next == NULL)
  {
    (*n)->next = new_node;
  }

  // inserting somewhere in the middle (still after n but before what originally came after n)
  else
  {
    new_node->next = (*n)->next;
    (*n)->next = new_node;
  }

  return new_node;
}

void list_free(struct node* head)
{
  struct node* n = head;
  struct node* tmp = NULL;
  while(n != NULL)
  {
    tmp = n;
    n = n->next;
    free(tmp);
  }
}

void list_print(struct node* head)
{
  struct node* current = head;
  while(current != NULL)
  {
    printf("%d\n",current->data);
    current = current->next;
  }
}

struct node* list_find(struct node* head, int value)
{
  struct node* current = head;
  while(current != NULL)
  {
    if(current->data == value)
      return current;
    current = current->next;
  }
  return NULL;
}

struct node* list_delete(struct node* head, struct node* unlink)
{
  struct node* h = head; // Assign the provided head as the node h. We will always return the head.
  struct node* current = head; // Use a current node. Initialize it as the head to start at the beginning of the list.
  struct node* prev = head; // Will be used to track the current node before current is reassigned.
  struct node* nodeToDelete; // Will be freed from memory.

  // Check if the struct to delete is the head.
  if (unlink == head)
  {
    nodeToDelete = head; // Assign the head as the node to delete.
    h = head->next; // Assign the next node as the new head.
    free(nodeToDelete); // Free from memory.
    return h; // Always return the head.
  }
  if (unlink == NULL) // If the node to delete is empty,
  {
    return h; // Do nothing, and return head because we aren't deleting anything.
  }

  while (current != NULL) // While we haven't reached the end of the list,
  { 
    if (current == unlink) // Check to see if we've found the match.
    {
      prev->next = current->next; // Take the previous node's next pointer and assign it to the node after what we want to delete.
      nodeToDelete = current; // We've found the node to delete.
      free(nodeToDelete); // Free the memory.
      return h; // Always return the head.
    } 
    else // Unlink is not the head/the tail/null, and we haven't found it yet.
    {
      prev = current; // Assign the current node to be what will become the previous node.
      current = current->next; // Move current to the next node in the list.
    }
  }
  return h;
}

unsigned int list_count(struct node* head)
{
  int count = 0;
  struct node* current = head;
  while(current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
}

int main(void)
{
  time_t t;
  srand((unsigned)time(&t));

  struct node* head = list_insert_after(NULL,0);

  int i;
  for(i = 1; i < 100; i++)
      list_insert_after(&head,rand()%100+1);

  head = list_delete(head, head); // Delete the head and assign the next node as the new head.
  int unlink_count = rand()%50;
  for(i = 0; i < unlink_count; i++)
    head = list_delete(head, list_find(head, rand()%100+1));

  struct node* current = head;
  while(current->next != NULL)
    current = current->next;
  head = list_delete(head,current);

  printf("%d\n",list_count(head));
  list_free(head);
  return 0;
}
