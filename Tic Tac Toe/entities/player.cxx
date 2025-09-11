#include <string>
#include "symbol.cxx"
using namespace std;

class Player {
    string name;
    Symbol symbol;
public:
    Player(string n, Symbol s) : name(n), symbol(s) {}
    string getName() const { return name; }
    Symbol getSymbol() const { return symbol; }
};