#include <vector>
#include <algorithm>
#include "gameobserver.cxx"
using namespace std;

class GameSubject {
private:
    vector<GameObserver*> observers;
    
public:
    void addObserver(GameObserver* observer) {
        observers.push_back(observer);
    }
    
    void removeObserver(GameObserver* observer) {
        for(auto it = observers.begin(); it != observers.end(); ++it) {
            if(*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }
    
   void GameSubject::notifyObservers() {
        for (GameObserver* observer : observers) {
            observer->update(static_cast<Game*>(this));
        }
    }
};