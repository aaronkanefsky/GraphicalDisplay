#include "Player/Player.h"
#include "GameObject/GameObject.h"
#include "InputController/InputController.h"
#include "Renderer/Renderer.h"

#define FRAMERATE       60
#define HEIGHT          1080
#define WIDTH           1920

typedef struct Application{
    Player player;
    InputController controller;
} Application;

void setup(Player* player);
void applicationLoop();