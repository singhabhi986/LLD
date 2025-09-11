#include "cell.cxx"
#include <vector>
#include <iostream>
using namespace std;

class Board {
    int size;
    vector<vector<Cell*>> cells;
    int movesCount=0;

public:
    Board(int s) : size(s), cells(s, vector<Cell*>(s)) {
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                cells[i][j] = new Cell();
            }
        }
    }

    ~Board() {
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                delete cells[i][j];
            }
        }
    }

    Symbol getCellSymbol(int row, int col) {
        return cells[row][col]->getSymbol();
    }

    bool setCellSymbol(int row, int col, Symbol s) {
        if(cells[row][col]->getSymbol() == EMPTY) {
            cells[row][col]->setSymbol(s);
            return true;
        }
        return false;
    }

    bool isFull() {
        if(movesCount == size * size) {
            return true;
        }
        return false;
    }

    void display() {
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                cout << getSymbolChar(cells[i][j]->getSymbol());
                if(j < size - 1) cout << " | ";
            }
            cout << endl;
            if(i < size - 1) {
                for(int k = 0; k < size; ++k) {
                    cout << "---";
                    if(k < size - 1) cout << "+";
                }
                cout << endl;
            }
        }
    }
    int getSize() const { return size; }
    void incrementMoves() { movesCount++; }
};