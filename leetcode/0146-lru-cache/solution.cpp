class DLL {
    public:
        int key;
        int value;
        DLL* next;
        DLL* prev;
        DLL() {
            next = NULL;
            prev = NULL;
        }

        void deletenode(DLL* node) {
            DLL* p = node->prev;
            p->next = node->next;
            node->next->prev = p;
            delete node;
        }

        void addnode(int key, int value, unordered_map<int, DLL*>& mp) {
            DLL* newnode = new DLL;
            newnode->key = key;
            newnode->value = value;
            
            DLL* second = this->next; 
            this->next = newnode;
            second->prev = newnode;
            newnode->next = second;
            newnode->prev = this;
            
            mp[key] = newnode;
        }

        void callnode(DLL* head, DLL* node, int value) {
            node->value = value;
            if (head->next == node) return;

            node->prev->next = node->next;
            node->next->prev = node->prev;
    
            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node; 
    }
};

class LRUCache {
public:
    DLL* head;
    DLL* tail;
    unordered_map<int, DLL*> mp;
    int cnt;

    LRUCache(int capacity) {
        head = new DLL;
        head->key = -1;
        head->value = -1;
        head->prev = NULL;
        tail = new DLL;
        head->next = tail;
        tail->key = -1;
        tail->value = -1;
        tail->next = NULL;
        tail->prev = head;
        cnt = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            DLL* node = mp[key];
            head->callnode(head, node, node->value);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            head->callnode(head, mp[key], value);
        }
        else if (cnt == 0) {
            DLL* lru = tail->prev;
            mp.erase(lru->key);
            head->deletenode(lru);
            head->addnode(key, value, mp);
        }
        else {
            head->addnode(key, value, mp);    
            cnt--;
        }
    }
};
