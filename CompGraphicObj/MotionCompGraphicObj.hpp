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
	virtual void delete_objects() = 0;

	Texture *menuTexture1, *menuTexture2, *menuTexture3, *menuBackground;
	Sprite *menu1, *menu2, *menu3, *menuBg;
	Text *Resolution, *ResolutionParametr1, *ResolutionParametr2, *ResolutionParametr3;
	Text *ScoreInfo;
	Font *font;
	int *ResolutionOption = new int;

	Texture *gameBackground, *collection_texture;
	Texture *character_texture, *barrier_texture;
	Sprite *character_sprite, *collection_sprite, *gameBg;
	Sprite *barrier_sprite1, *barrier_sprite2, *barrier_sprite3;
	Sprite *barrier_sprite4, *barrier_sprite5, *barrier_sprite6;

	float *CurrentFrame = new float;
	int *PlayerScore = new int;
};


class Objects_Interaction : public GUI_Objects
{
protected:
	void object_set_position(Sprite *sprite);
	void collection_pick();
	int collision_handling();
};


class Animations : public Objects_Interaction
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
		void delete_objects() override;
		void map_border_check();
		void game_draw();
};


class Menu : public GameInit
{
public:
    Menu();
		~Menu() {
			delete_objects();
		}

private:
    void settings();
		void load_objects() override;
		void delete_objects() override;
};
