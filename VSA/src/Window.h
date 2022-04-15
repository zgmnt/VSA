#pragma once
#include <SFML/Graphics.hpp>


class Window
{
	static sf::RenderWindow* _window;
	static int _width;
	static int _height;

	static int _frame_width;
	static int _frame_height;

	sf::RectangleShape _square_frame;

	// private functions


public:
	Window(int width, int height) 
	{ 
		_width = width, _height = height; 
	}

	void drawSelf() { _window->display(); }
	void clearSelf() { _window->clear(sf::Color::Blue); }
	void prepareMenuContents()
	{
		_square_frame.setFillColor(sf::Color::Red);
		_square_frame.setSize(sf::Vector2f(_frame_width, _frame_height));
	}
	void drawMenu()
	{
		// upper line
		_square_frame.setPosition(50, 83);
		_window->draw(_square_frame);

		_square_frame.setPosition(450, 83);
		_window->draw(_square_frame);

		_square_frame.setPosition(850, 83);
		_window->draw(_square_frame);

		// lower line
		_square_frame.setPosition(50, 416);
		_window->draw(_square_frame);

		_square_frame.setPosition(450, 416);
		_window->draw(_square_frame);

		_square_frame.setPosition(850, 416);
		_window->draw(_square_frame);
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
