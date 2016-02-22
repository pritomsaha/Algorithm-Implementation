#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> heap;

void insertInHeap(int key)
{
    heap.push_back(key);

    if(heap.size()==1)
        return;

    else{

        int pos = heap.size();
        int par = pos/2;
        while(par>=1&&heap[pos-1]>heap[par-1])
        {
            swap(heap[pos-1],heap[par-1]);
            pos=par;
            par=pos/2;
        }

    }

}

void showTheHeap()
{
    int i=0;
    while(i<heap.size())
    {
        cout<<heap.at(i)<<" ";
        i++;
    }
    cout<<endl;
}

int deleteHeap()
{
   int RemovedElement=heap.at(0);
   int last=heap.back();
   swap(heap.front(),heap.back());
   heap.pop_back();
   int heapSize=heap.size();
   int pos=1,Left=2,Right=3;

   while(heapSize>=Right)
   {
       if(last>=heap[Left-1]&&last>=heap[Right-1])
            break;

        if(heap[Left-1]>=heap[Right-1])
        {
            swap(heap[pos-1],heap[Left-1]);
            pos=Left;
        }

        else
        {
            swap(heap[pos-1],heap[Right-1]);
            pos=Right;
        }
       Left=2*pos;
       Right=Left+1;

   }
    if(Left==heapSize)
        if(last<heap[Left-1])
            swap(heap[pos-1],heap[Left-1]);

    return RemovedElement;

}

void heapSort()
{
    stack<int> SortedElements;
    while(!heap.empty())
    {
        SortedElements.push(deleteHeap());
    }

    while(!SortedElements.empty())
    {
        cout<<SortedElements.top()<<" ";
        SortedElements.pop();
    }

}

int main()
{
    for(int i=0;i<8;i++)
    {
        int element;
        cin>>element;
        insertInHeap(element);
    }

    showTheHeap();
    heapSort();

    return 0;
}
