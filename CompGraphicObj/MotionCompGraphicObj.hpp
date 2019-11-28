#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class WindowInit
{
protected:
	WindowInit() : MenuWindow{new RenderWindow}, GameWindow{new RenderWindow}
	{
		MenuWindow->create(VideoMode::getDesktopMode(),
		"Motion of a composite graphic object");
	}

	RenderWindow* MenuWindow;
	RenderWindow* GameWindow;
};


class GUI_Objects : public WindowInit
{
protected:
	virtual void load_objects() = 0;

	Texture *menuTexture1, *menuTexture2, *menuTexture3, *aboutTexture, *menuBackground;
	Sprite *menu1, *menu2, *menu3, *about, *menuBg;
	Text *Resolution, *ResolutionParametr1, *ResolutionParametr2, *ResolutionParametr3;
	Font *font;
	int *ResolutionOption = new int();

	Texture *gameBackground;
	Texture *character_texture;
	Sprite *character_sprite;
	Sprite *gameBg;
	float *CurrentFrame = new float;
};


class Animations : public GUI_Objects
{
protected:
	void hero_left_animation();
	void hero_right_animation();
	void hero_up_animation();
	void hero_down_animation();

private:
	void frame_update();
};


class GameInit : public Animations
{
protected:
  void load_game();

private:
		void game_proccess();
		void load_objects() override;
		void map_border_check();
		void game_draw();
};


class Menu : public GameInit
{
protected:
    Menu();

private:
    void settings();
		void load_objects() override;
};


class GUI : public Menu
{
public:
	GUI()
	{
		while (MenuWindow->isOpen()) {
			Event event;
			while (MenuWindow->pollEvent(event))
			{
				if (event.type == Event::Closed)
					MenuWindow->close();
			}
			MenuWindow->display();
		}

		while (GameWindow->isOpen()) {
			Event event;
			while (GameWindow->pollEvent(event))
			{
				if (event.type == Event::Closed)
					GameWindow->close();
			}
			GameWindow->display();
		}
	}
};
