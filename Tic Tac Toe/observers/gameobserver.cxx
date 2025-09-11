class Game; // Forward declaration

class GameObserver {
public:
    virtual ~GameObserver() = default;
    virtual void update(Game* game) = 0;
};