class LFUCache {
    struct Node {
        int key, val, freq;
        Node(int k, int v, int f) : key(k), val(v), freq(f) {}
    };

    int cap, min_freq;
    unordered_map<int, list<Node>> freq_list;
    unordered_map<int, list<Node>::iterator> key_map;

    void touch(list<Node>::iterator it) {
        int key = it->key;
        int val = it->val;
        int freq = it->freq;

        freq_list[freq].erase(it);
        if (freq_list[freq].empty()) {
            freq_list.erase(freq);
            if (min_freq == freq) {
                min_freq++;
            }
        }

        freq_list[freq + 1].emplace_front(key, val, freq + 1);
        key_map[key] = freq_list[freq + 1].begin();
    }

public:
    LFUCache(int capacity) : cap(capacity), min_freq(0) {}

    int get(int key) {
        if (cap == 0 || !key_map.count(key)) return -1;
        auto it = key_map[key];
        int val = it->val;
        touch(it);
        return val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (key_map.count(key)) {
            auto it = key_map[key];
            it->val = value;
            touch(it);
            return;
        }

        if (key_map.size() == cap) {
            auto& lru_list = freq_list[min_freq];
            int evict_key = lru_list.back().key;
            lru_list.pop_back();
            if (lru_list.empty()) {
                freq_list.erase(min_freq);
            }
            key_map.erase(evict_key);
        }

        min_freq = 1;
        freq_list[1].emplace_front(key, value, 1);
        key_map[key] = freq_list[1].begin();
    }
};
