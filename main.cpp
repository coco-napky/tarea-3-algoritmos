#include "Test.h"
#include <iostream>
using namespace std;

void print(vector<int> min_heap) {
    for(int i = 0; i < min_heap.size(); ++i)
        cout << min_heap[i] << " ";
    cout << endl;
}

int getFatherPos(int son)
{
    if(son % 2 == 0)
        return (son - 2) / 2;
    return (son -1 ) / 2;
}

int getRightChild(int father)
{
    return 2*father+1;
}


int getLeftChild(int father)
{
    return 2*father;
}

vector<int> replace(vector<int> min_heap, int replaced_value, int replacement)
{
    cout << "Start: ";
    print(min_heap);
    int i;
    for(i = 0; i < min_heap.size(); i++)
        if(min_heap[i] == replaced_value) {
            min_heap[i] = replacement;
            break;
        }

    int father = getFatherPos(i);
    int right = getRightChild(i);
    int left = getLeftChild(i);

    if(min_heap[i] < min_heap[father]){
          while(father >= 0 && min_heap[i] < min_heap[father] )
        {
            int son = min_heap[i];
            min_heap[i] = min_heap[father];
            min_heap[father] = son;
            i = father;
            father = getFatherPos(i);
        }
    }else if(min_heap[i] > min_heap[left]  || min_heap[i] > min_heap[right])
    {
        while(i*2+1 < min_heap.size() && (min_heap[i] > min_heap[left]  || min_heap[i] > min_heap[right]) )
        {
            int smallest = min_heap[left] > min_heap[right] ? right : left;
            int child = min_heap[smallest];
            min_heap[smallest] = min_heap[i];
            min_heap[i] = child;
            i = smallest;
            left = getLeftChild(i);
            right = getRightChild(i);
        }

    }
    return min_heap;
}


int main ()
{
    test();
    return 0;
}
