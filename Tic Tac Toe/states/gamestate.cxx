#include <string>
using namespace std;

class Game;

class GameState {
public:
    virtual ~GameState() = default;
    virtual void handleMove(Game* game, Player* player, int row, int col) = 0;
};

class InProgressState : public GameState {
public:
    void handleMove(Game* game, Player* player, int row, int col) override;
};

class DrawState : public GameState {
public:
    void handleMove(Game* game, Player* player, int row, int col){
        cout << "Game ended in a draw. No more moves allowed." << endl;
    }
};

class WinnerState : public GameState {
public:
    void handleMove(Game* game, Player* player, int row, int col) override;
};