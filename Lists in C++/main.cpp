#include <iostream>

using namespace std;

class ListNode
{
private:
    int data;
    ListNode * next;

public:
    ListNode();
    ListNode(int x)
    {
        data=x;
        next=NULL;
    }
    int getData();
    void setData(int );
    void setNext(ListNode *);
    ListNode* getNext();
};

int ListNode::getData()
{
    return data;
}

void ListNode::setData(int x)
{
    data=x;
}

void ListNode::setNext(ListNode * p)
{
    next=p;
}

ListNode* ListNode::getNext()
{
    return next;
}


class List
{

private:
    ListNode *head;
public:
    List()
    {
        head=NULL;
    }

    ListNode * getHead();
    void setHead(ListNode *);
    ListNode* last();
    void append(int);
    void prepend(int);
    void popBack();
    void print();
    void copy(List);
    void printReverse();
    ListNode * prevNode(ListNode *p);
    void popFront();

};

ListNode * List::getHead()
{
    return head;
}

void List::setHead(ListNode * p)
{
    head=p;
}

ListNode * List::last()
{
    ListNode* temp = head;
    if(head==NULL)
    {
        return NULL;
    }
    while(temp->getNext()!=NULL)
    {
        temp=temp->getNext();
    }


    return temp;
}

void List::append(int num)
{
    ListNode* new_node = new ListNode(num);
    ListNode * temp = head;

    if(head==NULL)
    {
        head=new_node;
        return ;
    }

    while(temp->getNext()!=NULL)
    {
        temp=temp->getNext();
    }
    temp->setNext(new_node);
}

void List::prepend(int num)
{
    ListNode* new_node = new ListNode(num);
    new_node->setNext(head);
    head=new_node;
}

void List::print()
{
    ListNode * temp=head;
    while(temp->getNext()!=NULL)
    {
        cout<<temp->getData();
        temp=temp->getNext();
    }
    cout<<temp->getData();

}





int main()
{
    List l ;
    l.append(4);
    l.append(5);
    l.append(6);
    l.append(7);

    l.print();



}
