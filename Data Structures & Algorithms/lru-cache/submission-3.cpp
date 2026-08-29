class Node{
public:
    pair<int,int> keyVal;
    Node* prev;
    Node* next;
 

    Node(int key, int val){
        this->keyVal.first = key;
        this->keyVal.second = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};


class LRUCache {
    int capacity;
    unordered_map<int, Node*> cache;

    // left = Least recently used, right = Most recently used
    Node* left, *right;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
         this->right = new Node(0,0);
        this->left = new Node(0,0);
        left->next = right;
        right->prev = left;
    
    }
    
    int get(int key) {
         
        if(this->cache.contains(key)){
            remove(cache[key]);
            insert(cache[key]);
            return this->cache[key]->keyVal.second;
        }
       
        return -1;
    }
    
    // helper function to facilitate get
    void remove(Node* node){
        
        node->prev->next = node->next;
        node->next->prev = node->prev;

    }
    void insert(Node* node){
        node->prev = this->right->prev;
        node->prev->next = node;

        node->next = this->right;
        this->right->prev = node;        
        
    }

    void put(int key, int value) {
        if(cache.contains(key)){
            cache[key]->keyVal.second = value;
            remove(cache[key]);
            insert(cache[key]);
            return;
        }

        if(cache.size() == this->capacity){
            Node* lru = left->next;
            remove(left->next);
            cache.erase(lru->keyVal.first);
        }
        Node* node = new Node(key,value);
        insert(node);
        cache[key] = node;
    }
};
