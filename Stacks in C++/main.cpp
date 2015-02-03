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




class Stack
{
private:

    ListNode * top;
    int length;

public:
    Stack()
    {
        top=NULL;
        length=0;
    }
    void Push(int);
    void Pop ();
    ListNode * getTop();
    int size();
    int isEmpty();
    void print();


};

void Stack::print()
{
    ListNode * temp = top;
    while(temp->getNext()!=NULL)
    {
        cout<<temp->getData();
        temp=temp->getNext();
    }
    cout<<temp->getData();
}

void Stack::Push(int num)
{
    ListNode * new_node = new ListNode(num);
    if(top==NULL)
    {
        top=new_node;
        length++;
        return ;
    }

    new_node->setNext(top);
    top=new_node;
    length++;
    return;


}

void Stack::Pop()
{
    if(top==NULL)
    {
        return;
    }

    top=top->getNext();
    length--;
    return;
}

ListNode * Stack::getTop()
{
    if(top==NULL)
    {
        return NULL;
    }
    return top;
}

int Stack::size()
{
    return length;
}

int Stack::isEmpty()
{
    if(length==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



int main()
{
    Stack s;
    s.Push(4);
    s.Push(5);
    s.Push(3);
    s.Pop();
    cout<<"size is "<<s.size()<<endl;
    cout<<s.getTop()->getData()<<endl;

    s.print();
}
