#include "board.cxx"
#include "player.cxx"
#include "gamestatus.cxx"
#include "winningStrategies.cxx"
#include "gamestate.cxx"
#include "gamesubject.cxx"
#include <string>
using namespace std;

class Game : public GameSubject {
    Board board;
    Player player1;
    Player player2;
    Player* currentPlayer;
    GameStatus status;
    Player* winner;
    GameState* state;
    vector<WinningStrategy*> strategies;
/*just git testing*/
public:
    Game(int boardSize, Player p1, Player p2) 
        : board(boardSize), player1(p1), player2(p2), status(GameStatus::IN_PROGRESS), winner(nullptr) {
        currentPlayer = &player1;
        state = new InProgressState();
        strategies.push_back(new RowWinningStrategy());
        strategies.push_back(new ColumnWinningStrategy());
        strategies.push_back(new DiagonalWinningStrategy());
    }
    Board* getBoard() { return &board; }
    
    GameStatus getStatus() const { return status; }
    
    Player* getWinner() const { return winner; }
    
    void setWinner(Player* p) { winner = p; }
    
    Player* getCurrentPlayer() const { return currentPlayer; }
    
    bool makeMove(int row, int col) {
        if(status != IN_PROGRESS) {
            cout << "Game has already ended." << endl;
            return false;
        }
        if(row < 0 || row >= board.getSize() || col < 0 || col >= board.getSize()) {
            cout << "Invalid move. Try again." << endl;
            return false;
        }
        if(board.getCellSymbol(row, col) != EMPTY) {
            cout << "Cell already occupied. Try again." << endl;
            return false;
        }
        state->handleMove(this, currentPlayer, row, col);
        notifyObservers();
        return true;
    };
    
    void display() {board.display();}
    
    bool checkWinner(Player* player) {
        for(auto strategy : strategies) {
            if(strategy->checkWin(&board, player)) {
                return true;
            }
        }
        return false;
    };
    
    void setStatus(GameStatus s) {
        status = s;
        notifyObservers(); 
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
    }
    
    void setState(GameState* s) {
        delete state;
        state = s;
    }
};


// Implementation of methods that depend on Game class

void InProgressState::handleMove(Game* game, Player* player, int row, int col) {
    if(game->getBoard()->setCellSymbol(row, col, player->getSymbol())) {
        game->getBoard()->incrementMoves();
        if(game->checkWinner(player)) {
            game->setWinner(player);
            game->setStatus((player->getSymbol() == Symbol::X) ? GameStatus::X_WON : GameStatus::O_WON);
            game->setState(new WinnerState());
        } else if(game->getBoard()->isFull()) {
            game->setStatus(GameStatus::DRAW);
            game->setState(new DrawState());
        } else {
            game->switchPlayer();
        }
    } else {
        cout << "Cell already occupied. Try again." << endl;
    }
}

void WinnerState::handleMove(Game* game, Player* player, int row, int col) {
    cout << "Game has already been won by " << game->getWinner()->getName() << ". No more moves allowed." << endl;
}