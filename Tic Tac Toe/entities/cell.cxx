#include "symbol.cxx"

class Cell {
    Symbol symbol;
public:
    Cell() : symbol(Symbol::EMPTY){}
    Symbol getSymbol() const { return symbol; }
    void setSymbol(Symbol s) { symbol = s; }
};