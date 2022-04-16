#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <utility>
#include <Windows.h>


class Window
{
	static sf::RenderWindow* _window;
	static int _width;
	static int _height;

	static int _frame_width;
	static int _frame_height;

	static sf::Font menu_font;
	static sf::Text _algorithm_name;
	static std::vector<sf::Text> _algorithm_names;
	static int framesPositionsX[6];
	static int framesPositionsY[6];
	static int background_change_direction;

	sf::RectangleShape _square_frame;

	sf::Sprite menu_background_sprite;
	sf::Texture menu_background_texture;

	// private functions


public:
	Window(int width, int height) 
	{ 
		_width = width, _height = height; 
	}

	void drawSelf() { _window->display(); }
	void clearSelf() { _window->clear(sf::Color::Blue); }
	void prepareTexts()
	{
		menu_font.loadFromFile("fonts\\mrsmonster.ttf");
		_algorithm_name.setFont(menu_font);
		_algorithm_name.setCharacterSize(50);
		_algorithm_name.setPosition(100, 100);
		_algorithm_name.setFillColor(sf::Color::Yellow);
		// filling container with names
		_algorithm_name.setString("bubble sort");
		_algorithm_names.push_back(_algorithm_name);
		_algorithm_name.setString("selection sort");
		_algorithm_names.push_back(_algorithm_name);
		_algorithm_name.setString("insertion sort");
		_algorithm_names.push_back(_algorithm_name);
		_algorithm_name.setString("quick sort");
		_algorithm_names.push_back(_algorithm_name);
		_algorithm_name.setString("merge sort");
		_algorithm_names.push_back(_algorithm_name);
		_algorithm_name.setString("counting sort");
		_algorithm_names.push_back(_algorithm_name);


	}
	void prepareBackground()
	{
		menu_background_texture.loadFromFile("img\\menu_background.png");
		menu_background_sprite = sf::Sprite(menu_background_texture);
	}
	void prepareMenuContents()
	{
		fillFramesPos();
		prepareTexts();
		prepareBackground();
		_square_frame.setFillColor(sf::Color::Red);
		_square_frame.setSize(sf::Vector2f(_frame_width, _frame_height));
	}
	void drawMenuBackground()
	{
		_window->draw(menu_background_sprite);
	}
	void fillFramesPos()
	{
		// X
		framesPositionsX[0] = 50;
		framesPositionsX[1] = 450;
		framesPositionsX[2] = 850;
		framesPositionsX[3] = 50;
		framesPositionsX[4] = 450;
		framesPositionsX[5] = 850;

		// Y
		framesPositionsY[0] = 83;
		framesPositionsY[1] = 83;
		framesPositionsY[2] = 83;
		framesPositionsY[3] = 416;
		framesPositionsY[4] = 416;
		framesPositionsY[5] = 416;
	}
	void drawMenuTexts()
	{

		for (int i = 0; i<_algorithm_names.size(); i++)
		{
			_algorithm_names[i].setPosition(framesPositionsX[i] + 40, framesPositionsY[i]+ 100);
			_window->draw(_algorithm_names[i]);
		}
	}
	void prepareFramesForEachAlgorithms()
	{
		for (int i = 0; i<_algorithm_names.size(); i++)
		{
			_square_frame.setPosition(framesPositionsX[i], framesPositionsY[i]);
			frameScaleChanger();
			_window->draw(_square_frame);
		}
	}
	void drawMenu()
	{

		drawMenuBackground();
		prepareFramesForEachAlgorithms();
		drawMenuTexts();
		frameScaleChanger();
		transition();

	}
	void transition()
	{
		// background movement //
		if (menu_background_sprite.getPosition().x > -730 && !background_change_direction)
			menu_background_sprite.setPosition(menu_background_sprite.getPosition().x - 2, -340);
		else
			background_change_direction = true;

		if (background_change_direction)
		{
			if (menu_background_sprite.getPosition().x > -230)
				background_change_direction = 0;

			menu_background_sprite.setPosition(menu_background_sprite.getPosition().x + 2, -340);
		}
	}
	void frameScaleChanger()
	{
		if (_square_frame.getGlobalBounds().contains((*_window).mapPixelToCoords(sf::Mouse::getPosition(*_window))))
		{

			_square_frame.setOrigin(10, 8);
			_square_frame.setScale(1.1, 1.1);
		}
		else
		{
			_square_frame.setOrigin(0, 0);
			_square_frame.setScale(1, 1);
		}
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
