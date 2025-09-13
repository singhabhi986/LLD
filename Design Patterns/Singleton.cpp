#include <mutex>
#include <unordered_set>
#include <iostream>

using namespace std;

class Observer{
    public:
    virtual ~Observer() = default;  // Better practice
    virtual void notify() = 0;
};

class logger : public Observer {
    public:
    void notify() override {
        cout << "Logger notified of configuration change." << endl;
    }
};

class CManagerSubject {
    unordered_set<Observer*> observers;
    std::mutex mtx; // Mutex for thread safety
    public:
        virtual ~CManagerSubject() {}
        bool regObserver(Observer* obj){
            if(!obj) return false;
            lock_guard<mutex> lock(mtx);
            return observers.insert(obj).second;
        }
        void notifyAll(){
            lock_guard<mutex> lock(mtx);
            for(const auto& obj : observers){
                try {
                    obj->notify();
                } catch (...) {
                    // Handle or log the exception as needed
                    continue;
                }
            }
        }
        bool deregisterObserver(Observer* obj){
            if(!obj) return false;
            lock_guard<mutex> lock(mtx);
            return observers.erase(obj) > 0;
        }
};

class ConfigurationManager : public CManagerSubject {
    static ConfigurationManager* instance;
    static std::mutex mtx; // Mutex for thread safety


    ConfigurationManager() {} // Private constructor
    ~ConfigurationManager() {} // Private destructor

    ConfigurationManager(const ConfigurationManager&) = delete; // Delete copy constructor
    ConfigurationManager& operator=(const ConfigurationManager&) = delete; // Delete assignment operator
    ConfigurationManager(ConfigurationManager&&) = delete; // Delete move constructor
    ConfigurationManager& operator=(ConfigurationManager&&) = delete; // Delete move assignment operator

public:
    static ConfigurationManager* getInstance() {
        if(instance == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            if(instance == nullptr) {
                instance = new ConfigurationManager();
            }
        }
        return instance;
    }

    static void deleteInstance() {
        std::lock_guard<std::mutex> lock(mtx);
        if(instance)
            delete instance;
        instance = nullptr;
    }
};

ConfigurationManager* ConfigurationManager::instance = nullptr;
std::mutex ConfigurationManager::mtx;

int main() {
    ConfigurationManager* configMgr = ConfigurationManager::getInstance();
    logger logObserver;

    configMgr->regObserver(&logObserver);
    configMgr->notifyAll(); // Should notify the logger

    configMgr->deregisterObserver(&logObserver);
    configMgr->notifyAll(); // No notification should occur

    ConfigurationManager::deleteInstance();
    return 0;
}