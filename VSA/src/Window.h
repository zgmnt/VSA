#pragma once
#include <SFML/Graphics.hpp>


class Window
{
	static sf::RenderWindow* _window;
	static int _width;
	static int _height;
public:
	Window(int width, int height) 
	{ 
		_width = width, _height = height; 
	}
	
	static sf::RenderWindow* getWindow()
	{
		if (_window == NULL)
		{
			_window = new sf::RenderWindow(sf::VideoMode(_width, _height), "SFML works!");
		}

		return _window;
	}

};
