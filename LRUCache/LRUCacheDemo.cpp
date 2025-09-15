#include <iostream>
#include <string>
#include "LRUCache.hpp"

int main() {
    LRUCache<int, std::string> lruCache(3);

    lruCache.put(1, "One");
    lruCache.put(2, "Two");
    lruCache.put(3, "Three");

    try {
        std::cout << "Get key 2: " << lruCache.get(2) << std::endl; // Should print "Two"
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    lruCache.put(4, "Four"); // This should evict key 1

    try {
        std::cout << "Get key 1: " << lruCache.get(1) << std::endl; // Should throw an error
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl; // Expected output
    }

    try {
        std::cout << "Get key 3: " << lruCache.get(3) << std::endl; // Should print "Three"
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
