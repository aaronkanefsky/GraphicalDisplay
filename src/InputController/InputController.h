#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H
#include <SFML/Graphics.hpp>
#include "../Player/Player.h"

class InputController{

public:
    InputController();
    ~InputController();

private:
    sf::Event playerEvent;
    Player player;
    
};
#endif // !INPUTCONTROLLER_H
