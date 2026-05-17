/*

HEAP :-

A heap is a data structure which is a complete binary tree and comes with a heap-order priority.
A binary tree means, that the parent node will have two child nodes.

In a complete binary tree, every level is filled except the last level.
And the nodes in a binary tree are always added from the left.

Heap order priority are of two types - max_heap and min_heap.


Operations Associated with Min Heap
Insert() 
Heapify()
getMin()
ExtractMin()
Delete()
Decreasekey()
Let’s see how these operations are done Using Min Heap.

Note: The Binary heap should always be a complete binary tree and should satisfy the corresponding heap property (Min / Max). If any of the two conditions are disturbed we should make necessary modifications in a heap to satisfy the two conditions.

Insert(): 
Insert operation inserts a new key in the Binary Heap.
Steps Followed for inserting the key in Binary Heap: 

First Insert the key at the first vacant position from the left on the last level of the heap. IF the last level is completely filled, then insert the key as the left-most element in the next level.
Inserting a new key at the first vacant position in the last level preserves the Complete binary tree property, The Min heap property may get affected we need to check for it.
If the inserted key parent is less than the key, then the Min heap property is also not violated. 
If the parent is greater than the inserted key value, then swap the values. Now the heap property may get violated at the parent node. So repeat the same process until the heap property is satisfied. 
Inserting an element takes O(logN) Time Complexity. Below shows the animation of how -1 is inserted into a Binary heap by following above described steps.
Heapify():
Suppose there exists a Node at some index i, where the Minheap property is Violated.
We assume that all the subtrees of the tree rooted at index i are valid binary heaps.
The Heapify function is used to restore the Minheap, by fixing the violation.
Steps to be followed for Heapify:

First find out the Minimum among the Violated Node, left, and right child of Violated Node.
If the Minimum among them is the left child, then swap the Violated Node value with the Left child value and recursively call the function on the left Child.
If the Minimum among them is the right child, then swap the Violated Node value with the right child value and recursively call the function right Child.
Recursive call stops when the heap property is not violated.
getMin():
It returns the minimum value in the Binary Heap.
As we all know, the root Node is the Minimum value in Min Heap. Simply return the arr[0].
ExtractMin(): 
This removes the Minimum element from the heap.
Steps to be followed to Remove Minimum value/root Node: 

Copy the last Node value to the Root Node, and decrease the size, this means that the root value is now deleted from the heap, and the size is decreased by 1.
By doing the above step we ensure that the Complete binary tree property is not violated, as we are copying the last node value to the root node value, the Min Heap property gets violated.
Call the Heapify function to convert it into a valid heap.
Decreasekey():
Given an index and a value, we need to update the value at the index with the given value. We assume that the given value is less than the existing value at that index.
Steps to be followed for Decreasekey(): 

Let’s the index be i and the value be new_val. Update existing value at index i with new_val i.e arr[i] = new_val. 
By performing the above step, the Complete binary tree property is not violated, but the Min heap property may get violated.
As the new_val we are inserting is less than the previously existing value, the min-heap property is not violated in subtrees of this rooted tree. 
It may get violated in its ancestors, so as we do in insert operation, check the value of a current node with its parent node, if it violates the min-heap property
Swap the nodes and recursively do the same.

Delete() : 
Given an index, delete the value at that index from the min-heap.
Steps to be followed for Delete operation(): 

First, update the value at the index that needs to be deleted with INT_MIN.
Now call the Decreasekey() function at the index which is need to be deleted. As the value at the index is the least, it reaches the top.
Now call the ExtractMin() operation which deletes the root node in Minheap.
In this way, the desired index value is deleted from the Minheap.

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

class BinaryHeap
{
    public:
    // capacity of the heap
    int capacity;

    // current size of the array
    int size;

    // current array
    int *arr;

    BinaryHeap(int cap)
    {
        cap = capacity;
        size = 0;
        arr = new int[capacity];
    }

    int parent(int ind)
    {
        return (ind - 1)/2;
    }

    int left(int ind)
    {
        return 2*ind + 1;
    }

    int right(int ind)
    {
        return 2*ind + 2;
    }

    // Insertion Operation - Insert a new key x
    void Insert(int x)
    {
        if(size == capacity)
        {
            cout<<"Binary tree already full"<<endl;
            return;
        }

        arr[size] = x;

        int k = size;

        size++;

        while(k!=0 && arr[parent(k)]>arr[k])
        {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    // Heapify is also a re-ordering and insertion algorithm for inserting at an index
    void heapify(int index)
    {
        // right child 
        int ri = right(index);

        // left child
        int li = left(index);

        // smallest consideration
        int smallest = index;

        if(li<size && arr[li] < arr[smallest])
        {
            smallest = li;
        } 

        if(ri<size && arr[ri] < arr[smallest])
        {
            smallest = ri;
        }

        // apply min-heap on complete binary tree
        while(smallest != index)
        {
            swap(&arr[smallest], &arr[index]);
            heapify(smallest);
        }
    }

    // Get the minimum value from the heap
    int getMin()
    {
        return arr[0];
    }

    // Extract the minimum element and remove from the heap
    int extractMin()
    {
        if(size < 0) return INT_MAX;

        // If the size is 1
        if(size == 1)
        {
            size--;
            return arr[0];
        }

        int mini = arr[0];

        // put end node at root
        arr[0] = arr[size - 1];

        // reduce the tree size
        size--;

        heapify(0);

        return mini;
    }

    // DecreaseKey means adding a decreased value at the particular node and updating value
    void decreaseKey(int i, int val)
    {
        // updating the value
        arr[i] = val;

        // maintaining the heap structure
        while(i!=0 && arr[parent(i)]>arr[i])
        {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    // Deleting the least valued node
    void deletefromHeap(int index)
    {
        // decreaseKey for the node
        decreaseKey(index, INT_MIN);
        // extract the minimum node
        extractMin();
    }

    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void print()
    {
        for(int i=0; i<size; ++i)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    BinaryHeap h(20);

    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    cout << "Min value is " << h.getMin() << endl;

    h.Insert(-1);
    cout << "Min value is " << h.getMin() << endl;

    h.decreaseKey(3, -2);
    cout << "Min value is " << h.getMin() << endl;

    h.extractMin();
    cout << "Min value is " << h.getMin() << endl;

    h.deletefromHeap(0);
    cout << "Min value is " << h.getMin() << endl;

    return 0;
}