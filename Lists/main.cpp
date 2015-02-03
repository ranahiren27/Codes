#include <iostream>

using namespace std;
class ListNode
{
private:
    int data;
    ListNode * next;

public :
    ListNode();
    ListNode(int num)
    {
        data = num;
        next=NULL;
    }
    int getData();
    void setData(int);
    void setNext(ListNode *);
    ListNode* getNext();

};

int ListNode::getData()
{
    return data;
}

void ListNode::setData(int x)
{
    data = x;
}

void ListNode::setNext(ListNode * P)
{
    next = P;
}

ListNode * ListNode::getNext()
{
    return next;
}


class List
{
private :
    ListNode * Head ;

public :
    List()
    {
        Head = NULL;
    }

    ListNode * getHead();
    void setHead(ListNode *)
    ListNode * last();
    void append(int);
    void prepend(int);
    void popBack();
    void print();
    void copy(List);
    void printReverse();

    ListNode * prevNode(ListNode * p);
    void popFront();




};

//List Method implementation

ListNode * List::getHead()
{
    return Head;
}


ListNode * List::last()
{
    ListNode * temp = Head ;
    if(Head==NULL)
    {
        return NULL;
    }
    while(temp->getNext()!=NULL)
    {
        temp=temp->getNext();
    }

    return temp;
}

void List:setHead(ListNode * p)
{
    Head= p;
}


void List::append(int num)
{
    ListNode * new_node = new ListNode(num);
    ListNode * temp = Head;
    if(Head==NULL)
    {
        Head=new_node;
        return;
    }
    while(temp->getNext()!=NULL)
    {
        temp=temp->getNext();
    }
    temp->setNext(new_node);
}

void List::prepend(int num)
{
   ListNode * new_node = new ListNode(num);
   new_node->setNext(Head);
   Head = new_node;

}

void List::popBack()
{
    ListNode * temp = Head ;
    ListNode * prev = NULL ;
    if(Head==NULL)
    {
        cout<<"List is empty\n";
    }

    if(Head->getNext()==NULL)
    {
        delete Head;
        Head=NULL;
        return;
    }

    while(temp->getNext()!=NULL)
    {
        prev = temp;
        temp= temp->getNext(0;
        )


    }

    delete temp;
    prev->setNext(NULL);

}

void List::print()
{
    ListNode * temp = Head;
    while(temp!=NULL)
    {
        cout<<temp->getData();
        temp=temp->getNext();
    }
}









int main()
{

}
