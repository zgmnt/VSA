#include "Window.h"


int main()
{
    Window window(1250,750);
    Window::getWindow()->setFramerateLimit(5);

    window.prepareContents();
    window.prepareAlgorithmsContents();

    while (Window::getWindow()->isOpen())
    {
        sf::Event event;
        while (Window::getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window::getWindow()->close();
        }

        window.clearSelf();
        window.draw();
        window.updateMenu();
        window.drawSelf();
    }

    return 0;
}
