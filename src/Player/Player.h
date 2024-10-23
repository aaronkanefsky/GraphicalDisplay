#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

typedef enum{
    NONE,
    NORMAL,
    BURN,
    FREEZE,
    STUN
} LaserEffect;

class Player{

public:

    // Copy swap
    Player();
    Player(const sf::Vector2f Playerpos);
    Player(const float x, const float y);
    ~Player();
    Player operator= (const Player& player);

    // Member Get functions
    sf::Vector2f getPosition() const;
    float getX() const;
    float getY() const;
    int getLives() const;

    // Member Set functions

    // Other



private:
    sf::Vector2f playerPos;     // Center of the player sprite
    sf::Vector2f playerVelo;    // Player's velocity
    sf::Vector2f playerAccel;   // Player's acceleration
    int lives;                  // Number of lives for the player
    long int score;
    LaserEffect laserType;      // Type of powerup for the player's laser


};

#endif // !PLAYER_H
