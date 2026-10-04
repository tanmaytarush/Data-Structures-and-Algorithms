/*
QUESTION:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.


Example:
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


APPROACH:
To implement the LRU cache, we can use a combination of a hash map and a doubly linked list.
- The hash map will store the key-value pairs, where the key is the cache key and the value is a pointer to the corresponding node in the linked list.
- The doubly linked list will maintain the order of the recently used keys, where the front of the list represents the most recently used key and the back of the list represents the least recently used key.

IMPLEMENTATION:
1. Initialize the LRU cache with the given capacity.
2. Implement the get(key) function:
   - If the key exists in the cache, move the corresponding node to the front of the list (indicating it is the most recently used).
   - Return the value of the key if it exists, otherwise return -1.
3. Implement the put(key, value) function:
   - If the key already exists in the cache, update its value and move the corresponding node to the front of the list.
   - If the key does not exist:
     - If the cache is full, remove the least recently used key (from the back of the list) and remove its entry from the hash map.
     - Add the new key-value pair to the front of the list and insert its entry into the hash map.


INTUITION :-

1.  In this setup, we perform a persistent storage system where a capacity threashold is maintained to 
    retrieve elements faster. In this scenario, we have that case where we define a LRUCache capacity = k.

2.  Now there are 4 operations which we can perform on a set of data, key-value pairs. THose operations are
    add, delete, get, and put. LRU refers to Least Recently Used and MRU refers to Most Recently Used. 

3.  Whenever an element is accessed or added, it becomes MRU, whereas the already existing element becomes
    LRU, and LRU can be popped out if the size of the cache or the capacity becomes more than k in order 
    to ingest the new incoming element.

4.  To keep a track of MRU and LRU we define a Doubly Linked List, and to keep track of what all elements 
    are currently present, we define an unordered_map<int, Node>.

5.  Time Complexity -> O(1) and Space Complexity -> O(1).

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class LRUCache
{
    public:
    class Node
    {
        public:
        int k;
        int v;
        Node* prev;
        Node* next;

        Node(int key, int val)
        {
            this->k = key;
            this->v = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mpp;
    int capacity;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node)
    {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        temp->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node)
    {
        Node* prevDelNode = node->prev;
        Node* nextDelNode = node->next;

        prevDelNode->next = nextDelNode;
        nextDelNode->prev = prevDelNode;
    }

    void moveToHead(Node* node)
    {
        deleteNode(node);
        addNode(node);
    }

    int get(int key)
    {
        if(mpp.find(key) == mpp.end())
        {
            return -1;
        }

        Node* node = mpp[key];
        int ans = node->v;
        moveToHead(node);
        return ans;
    }

    void put(int key, int val)
    {
        if(mpp.find(key) != mpp.end())
        {
            Node* existing = mpp[key];
            existing->v = val;
            moveToHead(existing);
            return;
        }

        if((int)mpp.size() == capacity)
        {
            Node* lru = tail->prev;
            deleteNode(lru);
            mpp.erase(lru->k);
            delete lru;
        }

        Node* newNode = new Node(key, val);
        addNode(newNode);
        mpp[key] = newNode;
    }
};

int main()
{
    int capacity;
    cin>>capacity;

    int q;
    cin>>q;

    LRUCache cache(capacity);
    while(q--)
    {
        string op;
        cin>>op;

        if(op == "get")
        {
            int key;
            cin>>key;
            cout<<cache.get(key)<<endl;
        }

        else if(op == "put")
        {
            int key;
            int val;
            cin>>key>>val;
            cache.put(key, val);
        }
    }

    return 0;
}
