#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;


MyHashMap::MyHashMap() {
    head_ref = (struct map**)malloc(sizeof(struct map*));
    *head_ref = nullptr;
}

MyHashMap::~MyHashMap() {
    
    struct map* current = *head_ref;
    struct map* next;
    
    while (current != nullptr)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(head_ref);
}


void MyHashMap::put(int key, int value) {

    struct map* val = (struct map*)malloc(sizeof(struct map));
    val->key = key;
    val->value = value;
    val->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = val;
        return;
    }

    struct map* tmp = *head_ref;
    struct map* prev = nullptr;

    while(tmp != nullptr)
    {   
        if(tmp->next == nullptr && tmp->key != key)
        {
            tmp->next = val;
            return;
        }
        
        if(tmp->key != key) tmp = tmp->next;
        else {
            tmp->value = value;
            free(val);
            return;
        } 
    }
    free(val);
}

int MyHashMap::get(int key) {

    struct map* tmp = *head_ref;
    while(tmp != nullptr)
    {
        if(tmp->key != key) tmp = tmp->next;
        else return (tmp->value);
    }
    return -1;
}

void MyHashMap::remove(int key) {

    struct map* tmp = *head_ref;
    struct map* prev = nullptr;
    struct map* rm = nullptr;

    while(tmp != nullptr)
    {            
        if(tmp->key != key) {
            prev = tmp;
            tmp = tmp->next;
        }
        else {
            if(prev != nullptr) prev->next = tmp->next;
            else *head_ref = tmp->next;
            rm = tmp;
            free(rm);
            return;    
        }  
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
