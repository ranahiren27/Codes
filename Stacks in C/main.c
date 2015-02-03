#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
 struct node
{
    int data;
    node* next;


}  ;

typedef struct queue queue;

struct queue
{
  node * top;
  node * bottom;

};

queue * CreateQueue()
{
    queue * new_queue = (queue*)malloc(sizeof(queue));
    new_queue->top=NULL;
    new_queue->bottom=NULL;

    return new_queue;
}

void Enqueue(queue* q, int num)
{
    node * new_node = (node*)malloc(sizeof(node));
    new_node->data=num;
    new_node->next=NULL;
    if(q->top==NULL)
    {
        q->top=new_node;
        q->bottom=new_node;

        return;
    }

    q->bottom->next=new_node;
    q->bottom=new_node;
}

void PrintQueue(queue * q)
{
    node * temp = (node *)malloc(sizeof(node));
    temp=q->top;
    while(temp->next!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    return;
}

void Dequeue(queue * q)
{
    if(q->top==NULL)
    {
        return;
    }

    q->top=q->top->next;
}



int main()
{
    queue * Q = CreateQueue();
    Enqueue(Q,4);
    Enqueue(Q,5);
    Enqueue(Q,6);
    Dequeue(Q);
    PrintQueue(Q);

    return 0;


}
