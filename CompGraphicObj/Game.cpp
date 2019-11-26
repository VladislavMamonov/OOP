#include "MotionCompGraphicObj.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;

void GameInit::load_game(int *ResolutionOption)
{
  if (*ResolutionOption == 1) {
    GameWindow->create(VideoMode(1920, 1080),
  	"Motion of a composite graphic object");
  }

  if (*ResolutionOption == 2) {
    GameWindow->create(VideoMode(1600, 900),
    "Motion of a composite graphic object");
  }

  if (*ResolutionOption == 3) {
    GameWindow->create(VideoMode(1280, 720),
    "Motion of a composite graphic object");
  }

  if (*ResolutionOption < 1 || *ResolutionOption > 3) {
    GameWindow->create(VideoMode::getDesktopMode(),
		"Motion of a composite graphic object");
  }
  game_proccess();
}


void GameInit::load_objects()
{
  gameBackground = new Texture;
  character_texture = new Texture;

  gameBackground->loadFromFile("images/Background_Game.jpg");
  character_texture->loadFromFile("images/character.png");

  gameBg = new Sprite(*gameBackground);
  character_sprite = new Sprite(*character_texture);

  clock = new Clock;
}


void GameInit::game_draw()
{
  GameWindow->draw(*gameBg);
  GameWindow->draw(*character_sprite);
  GameWindow->display();
}


void GameInit::game_proccess()
{
  GameInit::load_objects();

  character_sprite->setPosition(GameWindow->getSize().x/2.25, GameWindow->getSize().y/2.7);

  while (!Keyboard::isKeyPressed(Keyboard::Escape))
  {
    Event event;

    while (GameWindow->pollEvent(event)) {
      if (event.type == Event::Closed) {
        GameWindow->close();
      }
    }

    *CurrentFrame = 0;

    character_sprite->setTextureRect(IntRect(155, 165, 115, 160));

    if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
      character_sprite->move(-0.2, 0);
    }

    while (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
      hero_right_animation();
      game_draw();
    }

    while (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
      hero_up_animation();
      game_draw();
    }

    if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
      character_sprite->move(0, 0.2);
    }
    game_draw();
  }
  GameWindow->close();
}
