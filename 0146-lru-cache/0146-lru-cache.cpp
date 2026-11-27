#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        
        dll.splice(dll.begin(), dll, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
            return;
        }
        
        if (dll.size() == cap) {
            int lru_key = dll.back().first;
            dll.pop_back();
            mp.erase(lru_key);
        }
        
        dll.emplace_front(key, value);
        mp[key] = dll.begin();
    }
};