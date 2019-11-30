#include "MotionCompGraphicObj.hpp"
#include <iostream>

using namespace std;


void Menu::load_objects()
{
	menuTexture1 = new Texture;
	menuTexture2 = new Texture;
	menuTexture3 = new Texture;
	menuBackground = new Texture;

	menuTexture1->loadFromFile("images/1.png");
	menuTexture2->loadFromFile("images/options.png");
	menuTexture3->loadFromFile("images/2.png");
	menuBackground->loadFromFile("images/Background.jpg");

	menu1 = new Sprite(*menuTexture1);
	menu2 = new Sprite(*menuTexture2);
	menu3 = new Sprite(*menuTexture3);
	menuBg = new Sprite(*menuBackground);

	font = new Font();
	font->loadFromFile("arial.ttf");

	Resolution = new Text(L"Разрешение экрана: ", *font, 40);
	ResolutionParametr1 = new Text("1920x1080", *font, 30);
	ResolutionParametr2 = new Text("1600x900", *font, 30);
	ResolutionParametr3 = new Text("1280x720", *font, 30);
}


void Menu::settings()
{
	Color color(128,128,128);
	Resolution->setFillColor(color);
	Resolution->setStyle(Text::Bold);

	while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
		Resolution->setPosition(MenuWindow->getSize().x/2.4, MenuWindow->getSize().y/10.8);
		ResolutionParametr1->setPosition(MenuWindow->getSize().x/2.4, MenuWindow->getSize().y/6.35);
		ResolutionParametr2->setPosition(MenuWindow->getSize().x/2.4, MenuWindow->getSize().y/4.5);
		ResolutionParametr3->setPosition(MenuWindow->getSize().x/2.4, MenuWindow->getSize().y/3.48);

		Resolution->setFillColor(Color::White);
		ResolutionParametr1->setFillColor(Color::White);
		ResolutionParametr2->setFillColor(Color::White);
		ResolutionParametr3->setFillColor(Color::White);

		int menuNum;

		if (IntRect(MenuWindow->getSize().x/2.4,
		 MenuWindow->getSize().y/6.35, 300, 50).contains(Mouse::getPosition(*MenuWindow))) {
			ResolutionParametr1->setFillColor(Color::Cyan);
			menuNum = 1;
		}

		if (IntRect(MenuWindow->getSize().x/2.4,
		 MenuWindow->getSize().y/4.5, 300, 50).contains(Mouse::getPosition(*MenuWindow))) {
			ResolutionParametr2->setFillColor(Color::Cyan);
			menuNum = 2;
		}

		if (IntRect(MenuWindow->getSize().x/2.4,
		 MenuWindow->getSize().y/3.48, 300, 50).contains(Mouse::getPosition(*MenuWindow))) {
			ResolutionParametr3->setFillColor(Color::Cyan);
			menuNum = 3;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				MenuWindow->create(VideoMode(1920, 1080),
				"Motion of a composite graphic object");
				*ResolutionOption = 1;
			}

			if (menuNum == 2) {
				MenuWindow->create(VideoMode(1600, 900),
				"Motion of a composite graphic object");
				*ResolutionOption = 2;
			}

			if (menuNum == 3) {
				MenuWindow->create(VideoMode(1280, 720),
				"Motion of a composite graphic object");
				*ResolutionOption = 3;
			}
		}

		MenuWindow->draw(*menuBg);
		MenuWindow->draw(*Resolution);
		MenuWindow->draw(*ResolutionParametr1);
		MenuWindow->draw(*ResolutionParametr2);
		MenuWindow->draw(*ResolutionParametr3);
		MenuWindow->display();
	}
}


Menu::Menu()
{
	load_objects();

	bool isMenu = 1;
	int menuNum = 0;

	while (isMenu)
	{
		Event event;

		while (MenuWindow->pollEvent(event))
		{
			if (event.type == Event::Closed) {
				MenuWindow->close();
			}
		}

		menu1->setColor(Color::White);
		menu2->setColor(Color::White);
		menu3->setColor(Color::White);

		menuNum = 0;

		menu1->setPosition(MenuWindow->getSize().x/2.25, MenuWindow->getSize().y/2.7);
		menu2->setPosition(MenuWindow->getSize().x/1.09, MenuWindow->getSize().y/54);
		menu3->setPosition(MenuWindow->getSize().x/2.25, MenuWindow->getSize().y/2.4);

		if (IntRect(MenuWindow->getSize().x/2.25,
		 MenuWindow->getSize().y/2.7, 300, 50).contains(Mouse::getPosition(*MenuWindow))) {
			menu1->setColor(Color::Cyan);
			menuNum = 1;
		}

		if (IntRect(MenuWindow->getSize().x/1.09,
		 MenuWindow->getSize().y/54, 300, 50).contains(Mouse::getPosition(*MenuWindow))) {
			menu2->setColor(Color::Cyan);
			menuNum = 2;
		}

		if (IntRect(MenuWindow->getSize().x/2.25,
		 MenuWindow->getSize().y/2.4, 300, 50).contains(Mouse::getPosition(*MenuWindow))) {
			menu3->setColor(Color::Cyan);
			menuNum = 3;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				load_game();
				while (!Keyboard::isKeyPressed(Keyboard::Escape));
			}

			if (menuNum == 2) {
				settings();
				while(!Keyboard::isKeyPressed(Keyboard::Escape));
			}

			if (menuNum == 3) {
				MenuWindow->close();
				isMenu = false;
			}
		}

		MenuWindow->draw(*menuBg);
		MenuWindow->draw(*menu1);
		MenuWindow->draw(*menu2);
		MenuWindow->draw(*menu3);

		MenuWindow->display();
	}
}


void Menu::delete_objects()
{
	delete menuTexture1;
	delete menuTexture2;
	delete menuTexture3;
	delete menuBackground;

	delete menu1;
	delete menu2;
	delete menu3;
	delete menuBg;

	delete font;

	delete Resolution;
	delete ResolutionParametr1;
	delete ResolutionParametr2;
	delete ResolutionParametr3;
}
