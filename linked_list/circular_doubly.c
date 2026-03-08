#include<stdio.h>
#include<stdlib.h>

typedef struct doubly_linked_list
{
    int data;
    struct doubly_linked_list *next,*prev;
}node;

void display(node *head)
{
    if(head == NULL) { printf("List is empty\n"); return; }

    node *temp = head;
    do
    {
        printf("|%d| -> ", temp->data);
        temp = temp->next;
    } while(temp != head); 
    printf("|%d| -> ... loop\n", head->data);
}

node* create_a_node(int data)
{
    node *newnode = (node*)malloc(sizeof(node));
        newnode -> data = data;
        newnode -> prev = NULL;
        newnode -> next = NULL;
    return newnode; 
}

void deleto_at_front(node **head) 
{
   node *temp = *head;
   temp -> prev -> next = (*head) -> next;
   temp -> next -> prev = temp -> prev;

   (*head) = (*head) -> next;
   free(temp); 
}

void deleto_at_end(node **tail)
{
   node *temp = *tail;
   temp -> prev -> next = (*tail) -> next;
   temp -> next -> prev = temp -> prev;

   (*tail) = (*tail) -> prev;
   free(temp);
}


int main()
{
    node *head = NULL;
    node *tail = NULL;

    node *first = create_a_node(2);
    node *second = create_a_node(1);
    node *third = create_a_node(0);
    node *four = create_a_node(7);
    node *five = create_a_node(7);

    first -> next = second; first -> prev = five;
    second -> next = third; second -> prev = first;
    third -> next = four; third -> prev = second; 
    four -> next = five; four -> prev = third; 
    five -> next = first; five -> prev = four;

    head = first;
    tail = five;

    printf("Original Linked List : "); display(head);

    deleto_at_front(&head);
    deleto_at_end(&tail);
    deleto_at_front(&head);
    printf("\n\nDeletion at front,back,front");

    printf("\n\tLinked List after : "); display(head);
    
    return 0;
}
