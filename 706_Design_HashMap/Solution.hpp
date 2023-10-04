#include <vector>
#include <iostream> // header in standard library
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

namespace leetcode
{
    class MyHashMap
    {
        public:
            struct map {             
                int key;        
                int value;  
                struct map* next;
            };

            struct map** head_ref ;

            MyHashMap();
            ~MyHashMap();
            void put(int key, int value);
            int get(int key);
            void remove(int key);
    };
}