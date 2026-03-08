#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int power;
    int coeff;
    struct node *next;
} node;

typedef struct equation 
{
    node *head;
    node *tail;
} equation;

node* create_a_node(int coeff, int power) 
{
    node *newnode = (node*)malloc(sizeof(node));
         newnode->power = power;
         newnode->coeff = coeff;

    newnode->next = NULL;
    return newnode;
}

void create_a_equation(equation *eq) 
{
    eq->head = NULL;
    eq->tail = NULL;
}

void insert_term(equation *eq, int coeff, int power)
{
    if (coeff == 0) return;

    node *newnode = create_a_node(coeff, power);

    if (eq->head == NULL) 
    {
        eq->head = newnode;
        eq->tail = newnode;
    } 
    else 
    {
        eq->tail->next = newnode;
        eq->tail = newnode;
    }
}

equation add(equation *f, equation *g)
{
    equation result;
    create_a_equation(&result);

    node *first_eqn = f->head;
    node *second_eqn = g->head;

    while (first_eqn != NULL && second_eqn != NULL) 
    {
        if (first_eqn->power == second_eqn->power)
         {
            insert_term(&result, first_eqn->coeff + second_eqn->coeff, first_eqn->power);
            first_eqn = first_eqn->next;
            second_eqn = second_eqn->next;
         } 
        else if (first_eqn->power > second_eqn->power)
         {
            insert_term(&result, first_eqn->coeff, first_eqn->power);
            first_eqn = first_eqn->next;
         } 
        else
         {
            insert_term(&result, second_eqn->coeff, second_eqn->power);
            second_eqn = second_eqn->next;
         }
    while (first_eqn != NULL) 
    {
         insert_term(&result, first_eqn->coeff, first_eqn->power);
         first_eqn = first_eqn->next;
     }
    while (second_eqn != NULL)
     { 
        insert_term(&result, second_eqn->coeff, second_eqn->power); 
        second_eqn = second_eqn->next;
     }

    return result;
    }
}
void print_equation(equation *eq) 
{
    node *curr = eq->head;
    if(!curr) { printf("0\n"); return; }

    int first_time = 1;
    while(curr != NULL) 
    {
        int coefficient = curr->coeff;
        int power = curr->power;

        if(!first_time)
         {
            printf(coefficient > 0 ? " + " : " - ");
            coefficient = (coefficient < 0) ? -coefficient : coefficient;
         }
         else if (coefficient < 0)
          {
            printf("-");
            coefficient = -coefficient;
          }
        first_time = 0;

        if(power == 0) printf("%d",coefficient);
        else if(power == 1) printf("%dx",coefficient);
        else printf("%dx^%d", coefficient, power);

        curr = curr->next;
    }
    printf("\n");
}

int main() 
{
    equation f, g, result;
    create_a_equation(&f);
    create_a_equation(&g);

    insert_term(&f,5,14);
    insert_term(&f,-3,10);
    insert_term(&f,9,8);
    insert_term(&f,13,6);

    insert_term(&g,7,11);
    insert_term(&g,2,8);
    insert_term(&g,100,0);

    printf("f(x) = "); print_equation(&f);
    printf("\tg(x) = "); print_equation(&g);

    result = add(&f, &g);
    printf("\nf(x)+g(x)  = "); print_equation(&result);

    return 0;
}