#include <mutex>
#include "game.cxx"
#include "scoreboard.cxx"
using namespace std;

enum Symbol { X, O };

class TicTacToeSystem {
    Game* game;
    Scoreboard* scoreBoard;
    static TicTacToeSystem* instance;
    static mutex mtx;

    TicTacToeSystem() : game(nullptr), scoreBoard(new Scoreboard()) {}
public:
    static TicTacToeSystem* getInstance() {
        if(instance == nullptr) {
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr)
                instance = new TicTacToeSystem();
        }
        return instance;
    }

    static void destroyInstance() {
        lock_guard<mutex> lock(mtx);
        if(instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }

    void startNewGame(Player p1, Player p2, int boardSize=3) {
        if(game != nullptr) {
            delete game;
        }
        game = new Game(boardSize, p1, p2);
        game->addObserver(scoreBoard);
    }

    Game* getGame() { return game; }

};

TicTacToeSystem* TicTacToeSystem::instance = nullptr;
mutex TicTacToeSystem::mtx;

void Scoreboard::update(Game* game) {
    if(game->getStatus() != GameStatus::IN_PROGRESS && game->getWinner() != nullptr) {
        string winnerName = game->getWinner()->getName();
        if(scores.find(winnerName) == scores.end()) {
            scores[winnerName] = 0;
        }
        scores[winnerName]++;
    }
}