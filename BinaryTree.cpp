#include<iostream>

using namespace std;

struct Node{
    int key;
    Node *leftChild,*rightChild;

    Node(int Key)
    {
        key=Key;
        leftChild=NULL;
        rightChild=NULL;
    }

};
Node *root;

void createTree()
{
    root=NULL;
}

void insertNode(int Key)
{
    Node *current,*parent;
    current=root;

    if(current==NULL)
    {
        root=new Node(Key);
        return;
    }
    else
    {
        while(true){

          parent=current;

          if(current->key>Key)
          {
              current=current->leftChild;

              if(current==NULL)
              {
                  parent->leftChild=new Node(Key);
                  return;
              }
          }

          else if(current->key<Key)
          {
              current=current->rightChild;

              if(current==NULL)
              {
                  parent->rightChild=new Node(Key);;
                  return;
              }
          }

        }
    }

}
void searchKey(int Key)
{
    Node *current;
    current=root;

    while(true)
    {
        if(current==NULL)
        {
            cout<<"Not found."<<endl;
            return;
        }
        else if(current->key==Key)
        {
            cout<<"Found"<<endl;
            return;
        }
        else if(current->key>Key)
            current=current->leftChild;
        else
            current=current->rightChild;

    }
}
void getMinimum()
{
    Node *MinNode;

    MinNode=root;

    if(MinNode==NULL)
    {
        cout<<"No node exits";
        return;
    }
    while(MinNode->leftChild!=NULL)
    {
        MinNode=MinNode->leftChild;
    }

    cout<<"Minimum value is :"<<MinNode->key<<endl;

}


void getMaximum()
{
    Node *MaxNode;

    MaxNode=root;

    if(MaxNode==NULL)
    {
        cout<<"No node exits";
        return;
    }
    while(MaxNode->rightChild!=NULL)
    {
        MaxNode=MaxNode->rightChild;
    }

    cout<<"Maximum value is :"<<MaxNode->key<<endl;

}


int main()
{

    createTree();
    insertNode(10);
    insertNode(16);
    insertNode(34);
    insertNode(14);
    insertNode(45);
    insertNode(4);

    searchKey(10);

    getMinimum();
    getMaximum();

    return 0;
}
