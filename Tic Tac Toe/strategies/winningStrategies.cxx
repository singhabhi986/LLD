#include "board.cxx"
#include "player.cxx"
using namespace std;

class WinningStrategy {
public:
    virtual ~WinningStrategy() = default;
    virtual bool checkWin(Board* board, Player* player) = 0;
};

class RowWinningStrategy : public WinningStrategy {
public:
    bool checkWin(Board* board, Player* player) override {
        int size = board->getSize();
        Symbol sym = player->getSymbol();
        for(int i = 0; i < size; ++i) {
            bool win = true;
            for(int j = 0; j < size; ++j) {
                if(board->getCellSymbol(i, j) != sym) {
                    win = false;
                    break;
                }
            }
            if(win) return true;
        }
        return false;
    }
};

class ColumnWinningStrategy : public WinningStrategy {
public:
    bool checkWin(Board* board, Player* player) override {
        int size = board->getSize();
        Symbol sym = player->getSymbol();
        for(int j = 0; j < size; ++j) {
            bool win = true;
            for(int i = 0; i < size; ++i) {
                if(board->getCellSymbol(i, j) != sym) {
                    win = false;
                    break;
                }
            }
            if(win) return true;
        }
        return false;
    }
};

class DiagonalWinningStrategy : public WinningStrategy {
public:
    bool checkWin(Board* board, Player* player) override {
        int size = board->getSize();
        Symbol sym = player->getSymbol();
        bool win = true;
        for(int i = 0; i < size; ++i) {
            if(board->getCellSymbol(i, i) != sym) {
                win = false;
                break;
            }
        }
        if(win) return true;

        win = true;
        for(int i = 0; i < size; ++i) {
            if(board->getCellSymbol(i, size - 1 - i) != sym) {
                win = false;
                break;
            }
        }
        return win;
    }
};