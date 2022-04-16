#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <utility>
#include <Windows.h>

enum class Algorithms
{
	bubble_sort, selection_sort, insertion_sort, quick_sort, merge_sort, counting_sort
};

class Window
{
	//

	sf::RectangleShape strap;
	static Algorithms active_algorithm;

	//

	static sf::RenderWindow* _window;
	static int _width;
	static int _height;

	static int _frame_width;
	static int _frame_height;

	static sf::Font menu_font;
	static sf::Text _algorithm_name;
	static std::vector<sf::Text> _algorithm_names;
	static std::vector<std::pair<int, int>> framesPos;
	static std::vector<std::pair<int, int>> strapsPos;
	static std::vector<std::pair<int, int>> strapsSizes;
	static int background_change_direction;
	static unsigned int straps_amount;
	static unsigned int straps_width;

	sf::RectangleShape _square_frame;

	sf::Sprite menu_background_sprite;
	sf::Texture menu_background_texture;

	static bool menu_active;

	sf::Font algorithms_font;
	sf::Text algorithm_name_text;

	// private functions

	//


	void drawStrap()
	{
		_window->draw(strap);
	}

	//

	void prepareTexts()
	{
		menu_font.loadFromFile("fonts\\mrsmonster.ttf");
		algorithms_font.loadFromFile("fonts\\mrsmonster.ttf");
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

		algorithm_name_text.setFont(algorithms_font);
		algorithm_name_text.setCharacterSize(30);
		algorithm_name_text.setFillColor(sf::Color::Yellow);

	}
	void prepareBackground()
	{
		menu_background_texture.loadFromFile("img\\menu_background.png");
		menu_background_sprite = sf::Sprite(menu_background_texture);
	}
	void fillFramesPos()
	{
		std::pair<int, int > pos1 = std::make_pair(50, 83);
		std::pair<int, int > pos2 = std::make_pair(450, 83);
		std::pair<int, int > pos3 = std::make_pair(850, 83);
		std::pair<int, int > pos4 = std::make_pair(50, 416);
		std::pair<int, int > pos5 = std::make_pair(450, 416);
		std::pair<int, int > pos6 = std::make_pair(850, 416);

		framesPos.push_back(pos1);
		framesPos.push_back(pos2);
		framesPos.push_back(pos3);
		framesPos.push_back(pos4);
		framesPos.push_back(pos5);
		framesPos.push_back(pos6);
	}
	void prepareFrame()
	{
		_square_frame.setFillColor(sf::Color::Red);
		_square_frame.setSize(sf::Vector2f(_frame_width, _frame_height));
	}
	void drawMenuBackground()
	{
		_window->draw(menu_background_sprite);
	}
	void drawMenuTexts()
	{
		for (int i = 0; i < _algorithm_names.size(); i++)
		{
			_algorithm_names[i].setPosition(framesPos[i].first + 40, framesPos[i].second + 100);
			_window->draw(_algorithm_names[i]);
		}
	}
	void drawHoverFrames()
	{
		for (int i = 0; i < _algorithm_names.size(); i++)
		{
			_square_frame.setPosition(framesPos[i].first, framesPos[i].second);
			frameChanger(Algorithms(i));
			drawFrames();
		}
	}
	void menuTransition()
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
	void drawFrames() {_window->draw(_square_frame);}
	void selectorAlgorithm()
	{
		switch (active_algorithm)
		{
		case Algorithms::bubble_sort:
			bubbleSort();
			break;
		case Algorithms::selection_sort:
			selectionSort();
			break;
		case Algorithms::insertion_sort:
			insertionSort();
			break;
		case Algorithms::quick_sort:
			quickSort();
			break;
		case Algorithms::merge_sort:
			mergeSort();
			break;
		case Algorithms::counting_sort:
			countingSort();
			break;
		}
	}
	void frameChanger(Algorithms algorithm_name)
	{
		if (_square_frame.getGlobalBounds().contains((*_window).mapPixelToCoords(sf::Mouse::getPosition(*_window))))
		{

			_square_frame.setOrigin(10, 8);
			_square_frame.setScale(1.1, 1.1);


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Sleep(150);
				active_algorithm = algorithm_name;
				menu_active = false;
			}
		}
		else
		{
			_square_frame.setOrigin(0, 0);
			_square_frame.setScale(1, 1);
		}
	}
	void generateStrapsValues()
	{
		// should be called once

		strap.setFillColor(sf::Color::Yellow);
		srand(time(NULL));
		unsigned int sizeY; 

		for (int i = 0; i < straps_amount; i++)
		{
			sizeY = rand() % (500 - 100 + 1) + 100;
			strapsSizes.push_back(std::make_pair(straps_width, sizeY));
		}

	}
	void drawStraps()
	{
		for (int i = 0; i < straps_amount; i++)
		{
			strap.setSize(sf::Vector2f(strapsSizes[i].first, strapsSizes[i].second));
			strap.setPosition(sf::Vector2f(i * 15, _height - strapsSizes[i].second));
			_window->draw(strap);
		}
	}
	void bubbleSort()
	{
		algorithm_name_text.setString("Bubble Sort");
		_window->draw(algorithm_name_text);
		drawStraps();
		
	}
	void selectionSort()
	{
		algorithm_name_text.setString("Selection Sort");
		_window->draw(algorithm_name_text);
	}
	void insertionSort()
	{
		algorithm_name_text.setString("Insertion Sort");
		_window->draw(algorithm_name_text);
	}
	void quickSort()
	{
		algorithm_name_text.setString("Quick Sort");
		_window->draw(algorithm_name_text);
	}
	void mergeSort()
	{
		algorithm_name_text.setString("Merge Sort");
		_window->draw(algorithm_name_text);
	}
	void countingSort()
	{
		algorithm_name_text.setString("Counting Sort");
		_window->draw(algorithm_name_text);
	}

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
	void prepareAlgorithmsContents()
	{
		generateStrapsValues();
	}
	void prepareContents()
	{
		fillFramesPos();
		prepareTexts();
		prepareBackground();
		prepareFrame();
	}
	void updateMenu()
	{

		menuTransition();
	}
	void drawMenu()
	{
		drawMenuBackground();
		drawHoverFrames();
		drawMenuTexts();
	}
	void draw()
	{
		if (menu_active)
		{
			drawMenu();
		}
		else
		{
			selectorAlgorithm();
			drawStraps();
		}
	}
	void clearSelf() { _window->clear(sf::Color::Black); }
	void drawSelf() { _window->display(); }
};
