class LRUCache {
public:

    class Node {
    public:
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;

    // key -> node
    unordered_map<int, Node*> mp;

    // Dummy nodes
    Node* head;
    Node* tail;


    LRUCache(int capacity) {

        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }


    // Remove a node from the linked list
    void remove(Node* node) {

        Node* previous = node->prev;
        Node* nextNode = node->next;

        previous->next = nextNode;
        nextNode->prev = previous;
    }


    // Insert node at the end
    // End = Most Recently Used
    void insert(Node* node) {

        Node* previous = tail->prev;

        previous->next = node;
        node->prev = previous;

        node->next = tail;
        tail->prev = node;
    }


    int get(int key) {

        // Key does not exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // This key was just used,
        // so make it most recently used
        remove(node);
        insert(node);

        return node->value;
    }


    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // Update value
            node->value = value;

            // Make it most recently used
            remove(node);
            insert(node);

            return;
        }


        // Create new node
        Node* newNode = new Node(key, value);

        // Add to map
        mp[key] = newNode;

        // Add to linked list
        insert(newNode);


        // Capacity exceeded
        if (mp.size() > capacity) {

            // Least recently used node
            Node* lru = head->next;

            // Remove from list
            remove(lru);

            // Remove from map
            mp.erase(lru->key);

            // Delete node
            delete lru;
        }
    }
};