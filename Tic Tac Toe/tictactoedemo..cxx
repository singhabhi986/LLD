#include "tictactoesystem.cxx"
using namespace std;


int main() {
    Player player1("Alice", Symbol::X);
    Player player2("Bob", Symbol::O);
    TicTacToeSystem* system = TicTacToeSystem::getInstance();
    system->startNewGame(player1, player2);
    Game* game = system->getGame();
    game->display();
    TicTacToeSystem::destroyInstance();
    return 0;
}