#include "Window.h"


sf::RenderWindow* Window::_window;
int Window::_width;
int Window::_height;
int Window::_frame_width{ 350 };
int Window::_frame_height{ 250 };
sf::Font Window::menu_font;
std::vector<sf::Text> Window::_algorithm_names;
sf::Text Window::_algorithm_name;
sf::Text Window::sorted_text;
int Window::background_change_direction{ false };
std::vector<std::pair<int, int>> Window::framesPos;
std::vector<std::pair<int, int>> Window::strapsPos;
std::vector<std::pair<int, int>> Window::strapsSizes;
bool Window::menu_active{ true };
bool Window::sorted{ false };
bool Window::sort_on_wish{ false };
Algorithms Window::active_algorithm{Algorithms::bubble_sort};
unsigned int Window::straps_amount{ 83 };
unsigned int Window::straps_width{ 12 };