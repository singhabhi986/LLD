#include "Node.hpp"

template <typename K, typename V>

class DLL {
    Node<K,V>* head;
    Node<K,V>* tail;


    public:
        DLL(){
            head = new Node<K,V>(K(), V());
            tail = new Node<K,V>(K(), V());
            head->next = tail;
            tail->prev = head;
        };
        
        ~DLL() {
            Node<K,V>* current = head;
            while (current) {
                Node<K,V>* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }

        void removeNode(Node<K,V>* node, bool deleteNode = false);
        void addToFront(Node<K,V>* node);
        void update(Node<K,V>* node);
        void removeLast();
};