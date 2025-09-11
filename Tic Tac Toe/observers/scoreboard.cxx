#include "gameobserver.cxx"
#include "gamestatus.cxx"
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Scoreboard : public GameObserver {
    
    map<string, int> scores;

public:
    void update(Game* game) override;

    void display() {
        cout << "Scoreboard:" << endl;
        for(const auto& entry : scores) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }
};