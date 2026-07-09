/*

Program for Least Recently Used (LRU) Page Replacement Algorithm

Problem Statement: Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
int get(int key): Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value): Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Examples
Input: ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output: [null, null, null, 1, null, -1, null, -1, 3, 4]
Explanation: 
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
Input: ["LRUCache","put","get"]
[[1],[2,1],[2] 
Output: [null, null, 1]
Explanation: 
LRUCache lRUCache = new LRUCache(1);
lRUCache.put(2, 1); // cache is {2=1}
lRUCache.get(2);    // return 1

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class LRUCache
{
    public:
    class Node
    {
        public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode)
    {
        Node* temp = head->next;
        newNode->prev = head;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode)
    {
        Node* prevDel = delNode->prev;
        Node* nextDel = delNode->next;
        prevDel->next = nextDel;
        nextDel->prev = prevDel;
    }

    int get(int key)
    {
        // if the key exists in the map
        if(mpp.find(key) != mpp.end())
        {
            Node* resNode = mpp[key];
            int res = resNode->value;
            mpp.erase(key);

            // add to the priority
            deleteNode(resNode);
            addNode(resNode);
            mpp[key] = head->next;

            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // if the key already exists
        if(mpp.find(key) != mpp.end())
        {
            Node* resNode = mpp[key];
            mpp.erase(key);
            deleteNode(resNode);
        }

        // if the capacity is reached
        if(mpp.size() == capacity)
        {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // add to priority
        addNode(new Node(key, value));
        mpp[key] = head->next;
    }
};

int main()
{
    // Create cache with capacity 2
    LRUCache cache(2);

    // Put values in cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get value for key 1
    cout << cache.get(1) << endl; 

    // Insert another key (evicts key 2)
    cache.put(3, 3);

    // Key 2 should be evicted
    cout << cache.get(2) << endl; 

    // Insert another key (evicts key 1)
    cache.put(4, 4);

    // Key 1 should be evicted
    cout << cache.get(1) << endl; 

    // Key 3 should be present
    cout << cache.get(3) << endl; 

    // Key 4 should be present
    cout << cache.get(4) << endl; 

    return 0;
}