// https://practice.geeksforgeeks.org/problems/lru-cache/1
//
// DOES NOT RUN
struct CompareSecond {
    bool operator()(pair<int, int> left, pair<int, int> right) {
        return left.second < right.second;
    }    
};

class LRUCache
{
private:
  unordered_map<int, int> cache;
  unordered_map<int, int> usage;
  int max;
public:
    LRUCache(int cap)
    {
        // constructor for cache
        max = cap;
    }
    
    void iteration(unordered_map<int, int> &m) {
        for (auto i : m) {
            if (i.second == INT_MAX) {
                continue;
            }
            i.second++;
        }
    }
    
    int get(int key)
    {
        // this function should return value corresponding to key
        if(cache.find(key) != cache.end()) {
            if (cache[key] == INT_MAX){
                return -1;
            }
            usage[key] += 1; // used
            return cache[key];
        }
        return -1;
    }
    
    void set(int key, int value)
    {
        // storing key, value pair
        if(cache.find(key) != cache.end()) {
            cache[key] = value;
            //iteration(usage);
            usage[key] = 0;
            return;
        }
        if (cache.size() < max) {
            cache[key] = value;
            iteration(usage);
            usage[key] = 0;
        } else {
            auto min = *min_element(usage.begin(), usage.end(), CompareSecond());
            usage[min.first] = INT_MAX;
            iteration(usage);
            usage[key] = 0;
            cache[min.first] = INT_MAX;
            cache[key] = value;
        }
    }
};
