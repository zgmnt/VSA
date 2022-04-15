#include "Window.h"


int main()
{
    Window window(1250,750);

    while (Window::getWindow()->isOpen())
    {
        sf::Event event;
        while (Window::getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window::getWindow()->close();
        }

        Window::getWindow()->clear();
        Window::getWindow()->display();
    }

    return 0;
}
