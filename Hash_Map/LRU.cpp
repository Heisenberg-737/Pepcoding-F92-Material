#include <iostream>
#include <unordered_map> //for Hash-Map
#include <list>          //for linked list

using namespace std;

class LRU
{
    list<int> ll;
    unordered_map<int, int> map;
    int defaultSize = 4;

    void set(int key, int val)
    {
        if (map.find(key) == map.end())
        {
            if (ll.size() == defaultSize)
            {
                int lastkey = ll.back();
                ll.pop_back();
                map.erase(lastkey);
            }

            ll.push_front(key);
            map[key] = val;
        }
        else
        {
            ll.remove(key);
            ll.push_front(key);
            map[key] = val;
        }
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
            return -1;
        else
        {
            ll.remove(key);
            ll.push_front(key);
            return map[key];
        }
    }
};