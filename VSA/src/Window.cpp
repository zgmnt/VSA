#include "Window.h"


sf::RenderWindow* Window::_window;
int Window::_width;
int Window::_height;
int Window::_frame_width{ 350 };
int Window::_frame_height{ 250 };
sf::Font Window::menu_font;
std::vector<sf::Text> Window::_algorithm_names;
sf::Text Window::_algorithm_name;
int Window::background_change_direction{ false };
std::vector<std::pair<int, int>> Window::framesPos;