/*

LFU CACHE -> https://leetcode.com/problems/lfu-cache/description/

Problem Statement: Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class with the following functions:

LFUCache(int capacity): Initialize the object with the specified capacity.

int get(int key): Retrieve the value of the key if it exists in the cache; otherwise, return -1.
void put(int key, int value): Update the value of the key if it is present in the cache, or insert the key if it is not already present. If the cache has reached its capacity, invalidate and remove the least frequently used key before inserting a new item. In case of a tie (i.e., two or more keys with the same frequency), invalidate the least recently used key.

A use counter is maintained for each key in the cache to determine the least frequently used key. The key with the smallest use counter is considered the least frequently used.

When a key is first inserted into the cache, its use counter is set to 1 due to the put operation. The use counter for a key in the cache is incremented whenever a get or put operation is called on it. Ensure that the functions get and put run in O(1) average time complexity.


Example 1:
Input:
 ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
Output:
 [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
Explanation:

LFUCache lfu = new LFUCache(2); Initializing cache with capacity of 2.  
lfu.put(1, 1); Cache becomes: [1, _], cnt(1)=1.  
lfu.put(2, 2); Cache becomes: [2, 1], cnt(2)=1, cnt(1)=1.  
lfu.get(1); Returns 1. Cache becomes: [1, 2], cnt(2)=1, cnt(1)=2.  
lfu.put(3, 3); Cache evicts 2 as it has the lowest frequency. Cache becomes: [3, 1], cnt(3)=1, cnt(1)=2.  
lfu.get(2); Returns -1 (not found).  
lfu.get(3); Returns 3. Cache becomes: [3, 1], cnt(3)=2, cnt(1)=2.  
lfu.put(4, 4); Cache evicts 1 (LRU). Cache becomes: [4, 3], cnt(4)=1, cnt(3)=2.  
lfu.get(1); Returns -1 (not found).  
lfu.get(3); Returns 3. Cache becomes: [3, 4], cnt(4)=1, cnt(3)=3.  
lfu.get(4); Returns 4. Cache becomes: [4, 3], cnt(4)=2, cnt(3)=3.  

Example 2:
Input:
 ["LFUCache", "put", "put", "put", "put", "put", "get", "get", "get", "get", "get"]
Output:
 [null, null, null, null, null, null, 3, 4, 5, -1, -1]
Explanation:
LFUCache lfu = new LFUCache(3);
 Initializing cache with capacity of 3.  
lfu.put(5, 7); Cache becomes: [5], cnt(5)=1.  
lfu.put(4, 6); Cache becomes: [4, 5], cnt(4)=1, cnt(5)=1.  
lfu.put(3, 5); Cache becomes: [3, 4, 5], cnt(3)=1, cnt(4)=1, cnt(5)=1.  
lfu.put(2, 4); Cache evicts 5 as it has the lowest frequency. Cache becomes: [2, 3, 4], cnt(2)=1, cnt(3)=1, cnt(4)=1.  
lfu.put(1, 3); Cache evicts 4 as it has the lowest frequency. Cache becomes: [1, 2, 3], cnt(1)=1, cnt(2)=1, cnt(3)=1.  
lfu.get(1); Returns 3. Cache becomes: [1, 2, 3], cnt(1)=2, cnt(2)=1, cnt(3)=1.  
lfu.get(2); Returns 4. Cache becomes: [2, 1, 3], cnt(1)=2, cnt(2)=2, cnt(3)=1.  
lfu.get(3); Returns 5. Cache becomes: [3, 2, 1], cnt(1)=2, cnt(2)=2, cnt(3)=2.  
lfu.get(4); Returns -1 (not found).  
lfu.get(5); Returns -1 (not found).



INTUITION :-

1.  Consider a list of operations being provided from the users end in which I would need to move 
    from freq to another. In this scenario, we need to remove the least frequently used DLL from 
    the list. 

2.  We need to maintain two maps KeyNode and Freq_DLL with KeyNode containing <int, Node*> and 
    FreqDLL containing <int, List*> were List is Doubly-Linked-List.

3.  For each frequency, a DLL will be maintained which will keep all the nodes in that range.
    If an operation is performed, then in that case we will move from one frequency level to 
    another where, freq increases by 1. 

4.  Now, if in Freq_DLL, if a freq map becomes empty then min_freq ++ and in that case we
    remove either the node from previous min_freq and LRU from that freq map.

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Node
{
    public:
    Node *next;
    Node *prev;

    int key; int value;
    int freq;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        freq = 1;
        this->next = NULL;
        this->prev = NULL;
    }
};

class List
{
    public:
    int size;
    Node *head;
    Node *tail;

    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node* node)
    {
        Node *temp = head->next;
        
        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;

        size++;
    }

    void removeNode(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        size--;
    }

    Node* removeLRU()
    {
        if(size == 0) return nullptr;

        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};

class LFUCache
{
    private:
    int capacity;
    int minFreq;
    int currSize;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;

    public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updateFreqMap(Node* node)
    {
        int freq = node->freq;
        
        freqListMap[freq]->removeNode(node); // move to next frequency map

        // increase the min_freq if current freq_map size=0 or min_freq = freq
        if((freq == minFreq) && (freqListMap[freq]->size == 0))
        {
            minFreq++;
        }

        node->freq++; // increase the frequency count because node moves to next

        // if DLL for that new frequency does not exist, in that case create one
        if(freqListMap.find(node->freq) == freqListMap.end())
        {
            freqListMap[node->freq] = new List();
        }

        // add node to top of that new frequency
        freqListMap[node->freq]->addNode(node);
    }

    int get(int key)
    {
        if(keyNode.find(key) == keyNode.end()) return -1;

        Node* node = keyNode[key];
        updateFreqMap(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if(capacity == 0) return;

        // if value or node found, update the value directly
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqMap(node);
            return;
        }

        // if capacity is reached, move to min_freq and remove the LRUCache
        if(currSize == capacity)
        {
            List* list = freqListMap[minFreq];
            Node* nodeToRemove = list->removeLRU();

            keyNode.erase(nodeToRemove->key);

            delete nodeToRemove;

            currSize--;
        }

        // if not exists create a new one and add it into first freqNodeMap with freq=1
        Node* newNode = new Node(key, value);

        minFreq = 1;
        if (freqListMap.find(minFreq) == freqListMap.end()) {
            freqListMap[minFreq] = new List();
        }
        freqListMap[minFreq]->addNode(newNode);
        keyNode[key] = newNode;
        currSize++;
    }
};


int main()
{
    int capacity, q;
    cin>>capacity;

    LFUCache cache(capacity);

    cin>>q;

    while(q--)
    {
        int type;
        cin>>type;

        if(type == 1)
        {
            int key, value;
            cin>>key>>value;
            cache.put(key, value);
        }

        else if(type == 2)
        {
            int key;
            cin>>key;

            cout<<cache.get(key)<<endl;
        }
    }

    return 0;
}