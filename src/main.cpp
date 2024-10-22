#include <SFML/Graphics.hpp>
#include "GameObject/GameObject.h"
#include "InputController/InputController.h"
#include "Player/Player.h"
#include "Renderer/Renderer.h"

int main()
{
    sf::RenderWindow window({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(200);

    // create an array of 4 vertices that define a quad
    sf::VertexArray square(sf::TriangleStrip, 4);
    sf::Mouse mouse;
    sf::Vector2 mouseLocation = mouse.getPosition(window);

    // define the position of the triangle's points
    square[0].position = sf::Vector2f(mouseLocation.x, mouseLocation.y);
    square[1].position = sf::Vector2f(100.f, 200.f);
    square[2].position = sf::Vector2f(200.f, 100.f);
    square[3].position = sf::Vector2f(200.f, 200.f);

    // define the color of the square's points
    square[0].color = sf::Color::Red;
    square[1].color = sf::Color::Blue;
    square[2].color = sf::Color::Green;
    square[3].color = sf::Color::Yellow;
    // no texture coordinates here, we'll see that later

    
    

    // Handle the window
    while (window.isOpen())
    {
        for (sf::Event event; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Get the mouse position relative to the window
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

        // Adjust the vertices' positions based on the relative mouse position to create the POV effect
        square[0].position = sf::Vector2f(mousePosF.x - 100, mousePosF.y - 100); // top-left
        square[1].position = sf::Vector2f(mousePosF.x + 100, mousePosF.y - 100); // top-right
        square[2].position = sf::Vector2f(mousePosF.x - 100, mousePosF.y + 100); // bottom-left
        square[3].position = sf::Vector2f(mousePosF.x + 100, mousePosF.y + 100); // bottom-right

        window.clear();
        
        window.draw(square);
        window.display();
    }
}
