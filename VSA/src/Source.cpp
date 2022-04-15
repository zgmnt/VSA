#include "Window.h"


int main()
{
    Window window(1250,750);
    window.prepareMenuContents();
    

    while (Window::getWindow()->isOpen())
    {
        sf::Event event;
        while (Window::getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window::getWindow()->close();
        }

        window.clearSelf();
        window.drawMenu();
        window.drawSelf();


    }

    return 0;
}
