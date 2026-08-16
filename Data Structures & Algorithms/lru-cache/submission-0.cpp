class Node { 
    public:
    int key;
    int value;
    Node*next;
    Node*prev;
    
    Node(int k ,int v){
        key=k;
        value=v;
        next=prev=nullptr;
    }
};



class LRUCache {
public:
    int capacity;
    Node*tail;
    Node*head;
    unordered_map<int,Node*>mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node*node){
        
        node->next = head->next;
        head->next->prev = node;

        node->prev = head;
        head->next=node;

    }

    void deleteNode(Node*node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end()) return -1;
        
        Node* node = mp[key];

        deleteNode(node);
        addNode(node);

        return node->value;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            
            Node* node = mp[key];
            node->value=value;
            deleteNode(node);
            addNode(node);
            
        } else{
            if(mp.size()==capacity){

                Node * lru = tail->prev;
                
                mp.erase(lru->key);
                deleteNode(lru);
                delete lru;
                
                Node* node = new Node(key,value);
                mp[key]=node;
                addNode(node);

            } else{
                Node* node = new Node(key,value);
                addNode(node);
                mp[key] = node;

            }
        }
    }
};
