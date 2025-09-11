enum Symbol {
    EMPTY, 
    X, 
    O
};

char getSymbolChar(Symbol s) {
    switch(s) {
        case EMPTY: return ' ';
        case X: return 'X';
        case O: return 'O';
        default: return ' ';
    }
}