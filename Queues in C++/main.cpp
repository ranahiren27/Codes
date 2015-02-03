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

class Queue
{
private:

  ListNode * front;
  int length;

public :
    Queue()
    {
        front=NULL;
        length=0;
    }

    void Enqueue(int);
    void Dequeue();
    int size();
    int isEmpty();
    void print();
};

void Queue::Enqueue(int num)
{
    ListNode * new_node = new ListNode(num);
    ListNode * temp=front;
    if(front==NULL)
    {
        front=new_node;
        length++;
        return ;
    }
    while(temp->getNext()!=NULL)
    {
        temp=temp->getNext();;
    }
    length++;
    temp->setNext(new_node);


}

void Queue::print()
{
    ListNode* temp = front;
    while(temp->getNext()!=NULL)
    {
        cout<<temp->getData();
        temp=temp->getNext();
    }
    cout<<temp->getData()<<endl;
}


void Queue::Dequeue()
{
    if(front==NULL)
    {
        return ;
    }
    length--;
    front=front->getNext();
}

int Queue::size()
{
    return length;

}

int Queue::isEmpty()
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
    cout<<"To start press s else press n"<<endl;
    char c;
    cin>>c;

    Queue q;
    while(c=='s')
    {
        int dec;
        cout<<"Enqueue press 1"<<endl;
        cout<<"Dequeue press 2"<<endl;
        cout<<"To print press 3"<<endl;
        cout<<"To get size of queue press 4"<<endl<<endl;
        cin>>dec;

        if(dec==1)
        {
            int value;
            cout<<"enter value to add"<<endl;
            cin>>value;
            q.Enqueue(value);
        }
        else if (dec==2)
        {
            q.Dequeue();
        }
        else if(dec==3)
        {
            q.print();
        }
        else if (dec==4)
        {
            cout<<"the size of the queue"<<q.size();
        }
cout<<"To continue press s else press n"<<endl<<endl;
        cin>>c;

    }

}
