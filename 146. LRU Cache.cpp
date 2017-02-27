class LRUCache {
private:
int m_capacity;
unordered_map<int, list<pair<int,int>>::iterator> map;    // key and iterator
list<pair<int,int>> m_list;   // key and value
public:
    LRUCache(int capacity) {
      m_capacity = capacity;  
    }
    
    int get(int key) {
        auto found_iter = map.find(key);
        if(found_iter == map.end()){
            return -1;
        }
        m_list.splice(m_list.begin(), m_list, found_iter->second);
        return found_iter->second->second;
        
    }
    
    void put(int key, int value) {
        
        auto found_iter = map.find(key);
        if(found_iter != map.end()){
            m_list.splice(m_list.begin(), m_list, found_iter->second);
            found_iter->second->second = value;
            return;
        }
        
        if(map.size() == m_capacity){
            int key_to_del = m_list.back().first;
            m_list.pop_back();
            map.erase(key_to_del);
        }
        m_list.emplace_front(key,value);
        map[key] = m_list.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */