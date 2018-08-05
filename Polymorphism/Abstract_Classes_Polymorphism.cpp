/*
Sample Input

3 1
set 1 2
get 1
get 2
Sample Output

2
-1
Explanation

Since, the capacity of the cache is 1, the first set results in setting up the key 1 with it's value 2. 
The first get results in a cache hit of key 1, so 2 is printed as the value for the first get. 
The second get is a cache miss, so -1 is printed.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: protected Cache {
    
public:
    
    LRUCache(int c){
        cp = c;
    }
    
    void set(int k, int v) {
        Node *N;
        
        if(mp.empty()){
            N = new Node(k,v);
            head = N;
            tail = N;
            mp[k] = N;
            //mp.insert(pair<int,Node*>(k,&nd));
            
            return;
        }
        
        //auto it = mp.find(k)
        map<int,Node*>::iterator it;
        it = mp.find(k);
        
        if (it != mp.end()){
            //mp.erase(it);
            //Node nd = Node(head->prev,head,k,v);
            //head->prev = &nd;
            //head = &nd;
            //mp.insert(pair<int,Node*>(k,&nd));
            
            it->second->value = v;
            if(head == it->second)
                return;
            
            it->second->prev->next = it->second->next;
            
            if(tail == it->second){
                tail = tail->prev;
            } else {
                it->second->next->prev = it->second->prev;
            }
            
            it->second->next = head;
            head->prev = it->second;
            
            it->second->prev = NULL;

            head = it->second;
              
        } else {
            N = new Node(head->prev,head,k,v);
            head->prev = N;
            head = N;
            
            mp[k] = N;
            
            if(mp.size() > cp){
                mp.erase(tail->key);
                tail = tail->prev;
                delete tail->next;
                tail->next = NULL;
            }
            
            //mp.insert(pair<int,Node*>(k,&nd));
        }
            
        
        
    }
    
    int get(int k) {
        map<int,Node*>::iterator it;
        it = mp.find(k);
        if(it != mp.end()){
            return (mp[k]->value);
        } else{
            return -1;
        }
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}