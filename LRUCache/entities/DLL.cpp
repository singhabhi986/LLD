#include "DLL.hpp"

template <typename K, typename V>
void DLL<K,V>::removeNode(Node<K,V>* node, bool deleteNode)
{
    if (node == head || node == tail) {
        return; // Do not remove sentinel nodes
    }
    Node<K,V>* prevNode = node->prev;
    Node<K,V>* nextNode = node->next;
    if (prevNode) {
        prevNode->next = nextNode;
    }
    if (nextNode) {
        nextNode->prev = prevNode;
    }
    if (deleteNode) {
        delete node;
        node = nullptr;
    }
    std::cout << "Removing key: " << node->getKey() << std::endl;
}

template <typename K, typename V>
void DLL<K,V>::addToFront(Node<K,V>* node)
{
    Node<K,V>* firstRealNode = head->next;
    head->next = node;
    node->prev = head;
    node->next = firstRealNode;
    //firstRealNode would always be non-null as tail is always there
    firstRealNode->prev = node;
    std::cout << "Adding key to front: " << node->getKey() << std::endl;
}

template <typename K, typename V>
void DLL<K,V>::update(Node<K,V>* node)
{
    removeNode(node, false/*deleteNode*/);
    addToFront(node);
    std::cout << "Updating key: " << node->getKey() << std::endl;
}

template <typename K, typename V>
void DLL<K,V>::removeLast()
{
    if (tail->prev == head) {
        return; // List is empty
    }
    Node<K,V>* nodeToDelete = tail->prev;
    Node<K,V>* newLastNode = nodeToDelete->prev;
    tail->prev = newLastNode;
    newLastNode->next = tail;
    std::cout << "Removing key: " << nodeToDelete->getKey() << std::endl;
    removeNode(nodeToDelete, true/*deleteNode*/);// We can delete the last node as we are removing it from the list
    return;
}