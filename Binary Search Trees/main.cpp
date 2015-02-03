#include <iostream>

using namespace std;

class Node
{
public:
    Node* left;
    Node* right;
    Node* parent;
    int data;

    Node()
    {
        data =0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    Node(int x)
    {
        data= x;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

};


class BST
{
public:
    Node* root = new Node();

    BST()
    {
        root->data = 0;
        root->left = NULL;
        root-> right = NULL;
        root->parent = NULL;
    }
    BST(int x)
    {

        root->data =x;
        root->left = NULL;
        root-> right = NULL;
        root -> parent = NULL;
    }



    void insert(int x)
    {
        int inserted = 0;
        Node* temp = root;
        while(inserted==0)
        {
            if (x<=temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left = new Node(x);
                    temp->left->parent = temp;
                    inserted = 1;
                }
                else
                {
                  temp=temp->left;
                }
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right = new Node(x);
                    temp->right->parent = temp;
                    inserted = 1;
                }
                else
                {
                  temp=temp->right;

                }
            }
        }
    }


    int Search(Node* start,int value)
    {
        // Return 1 if node with given value is present
        Node* temp = root;

        int found=0;

        while(found ==0)
        {
           if (temp->data ==value)
           {
               return 1;
           }

           if (value<=temp->data)
           {
               if(temp->left==NULL)
               {
                   return 0;
               }
               else
               {
                   temp=temp->left;
               }
           }
           else
           {
               if(temp->right==NULL)
               {
                   return 0;
               }
               else
               {
                   temp=temp->right;
               }
           }
        }
}


    Node* SearchNode(Node* start,int value)
    {
        //Returns the pointer to the node having data = value
        Node* temp = root;

        int found=0;

        while(found ==0)
        {
           if (temp->data ==value)
           {
               return temp;
           }

           if (value<=temp->data)
           {
               if(temp->left==NULL)
               {
                   return NULL;
               }
               else
               {
                   temp=temp->left;
               }
           }
           else
           {
               if(temp->right==NULL)
               {
                   return NULL;
               }
               else
               {
                   temp=temp->right;
               }
           }
        }
}

    void printTree(Node* start)
    {
        //Prints the tree
            if(start->left!=NULL)
            {
               printTree(start->left);
            }

            cout<<start->data<<endl;
            if(start->right!=NULL)
            {
                printTree(start->right);
            }


            return ;
        }

    int minValue(Node* start)
    {
        //returns the minimum value of a subtree starting at Node start
        Node* temp =start;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }

        return temp->data;
    }

    Node* minValueNode(Node* start)
    {
        //Returns the node with the minimum value for a subtree starting at start Node
        Node* temp =start;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }

        return temp;
    }

    Node* maxValueNode(Node* start)
    {
        //Returns the node with the minimum value for a subtree starting at start Node
        Node* temp =start;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }

        return temp;
    }

    int maxValue(Node* start)
    {
        Node* temp =start;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }

        return temp->data;
    }

    void deleteNode(Node* start)
    {

        Node* temp = start;

        if(temp->left==NULL && temp->right == NULL)
        {
            if(temp->parent->left == temp)
            {
                temp->parent->left = NULL;
            }
            else
            {
                temp->parent->right = NULL;
            }
            return;
        }
        else if (temp->right == NULL && temp->left != NULL)
        {
            temp->data = temp->left->data;
            temp->left = NULL;
            return;
        }
        else if (temp->right != NULL && temp->left == NULL)
        {
            temp->data = temp->right->data;
            temp->right = NULL;
            return;
        }
        else if (temp->right!=NULL && temp->left!=NULL)
        {
            Node* mins = maxValueNode(temp->left);
            temp->data = mins->data;
            if(mins->parent->left== mins)
            {
                mins->parent->left = NULL;
            }
            else
            {
                mins->parent->right =NULL;
            }
            return;
        }
    }


    void deletes(int value)
    {
        Node* mins = SearchNode(root,value);

        deleteNode(mins);
    }





};

int main()
{
    BST A =  BST(5);
    A.insert(2);
    A.insert(12);
    A.insert(6);
    A.insert(8);
    A.insert(4);
    A.insert(13);
    A.deletes(13);

    A.printTree(A.root);





}
