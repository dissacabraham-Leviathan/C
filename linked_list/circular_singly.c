#include<stdio.h>
#include<stdlib.h>

typedef struct singly_linked_list
{
    int data;
    struct singly_linked_list *next;
}node;

int no_of_elements = 0;

void display(node *head)
{
    if(head == NULL) { printf("List is empty\n"); return; }

    node *temp = head;
    do
    {
        printf("|%d| -> ", temp->data);
        temp = temp->next;
    } while(temp != head); 
    printf("|%d| -> ... loop", head->data);
}

void insertio_at_front(node **head, node **tail, int Data)
{
    node *newnode = (node*)malloc(sizeof(node));
        newnode->next = *head;
        newnode->data = Data;

    *head = newnode;
    (*tail)->next = *head;

    no_of_elements++;
}

void insertio_at_end(node **tail, node *head, int Data)
{
    node *newnode = (node*)malloc(sizeof(node));
        newnode->data = Data;
        newnode->next = head;

    (*tail)->next = newnode;
    *tail = newnode;

    no_of_elements++;
}

void insertio_at_position(node *head, int Data)
{
    int position;
    int flag;
    node *newnode = (node*)malloc(sizeof(node));
        newnode->data = Data;

    do{
        flag = 1;
        printf("\n\nEnter the Position : ");
        scanf("%d",&position);

        if(position <= 1) printf("Invalid position\n");
        else if(position > no_of_elements) printf("Location invalid\n");
        else
        {
            node *temp = head;
            for(int i = 1; i < position - 1; i++)
                temp = temp->next;

            newnode->next = temp->next;
            temp->next = newnode;
            flag = 0;
            no_of_elements++;
        }
    } while(flag == 1);
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    node *first = (node*)malloc(sizeof(node));
        first->data = 1;
        first->next = first;

    head = first;
    tail = first;
    no_of_elements++;

    printf("Initial Circular linked List : %d \n",first -> data);
    display(head);

    insertio_at_front(&head, &tail, 3);
    printf("\n\nfront Insertion : "); 
    display(head);

    insertio_at_end(&tail, head, 4);
    printf("\nend Insertion : "); 
    display(head);

    insertio_at_position(head, 5);
    printf("\n\nCircular Linked list: "); 
    display(head);

    return 0;
}