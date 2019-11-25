#include "MotionCompGraphicObj.hpp"
#include <iostream>

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
}


void GameInit::game_proccess()
{
  GameInit::load_objects();

  character_sprite->setTextureRect(IntRect(55, 56, 36, 55));
  character_sprite->setPosition(GameWindow->getSize().x/2.25, GameWindow->getSize().y/2.7);

  while (!Keyboard::isKeyPressed(Keyboard::Escape))
  {
    Event event;

    while (GameWindow->pollEvent(event)) {
      if (event.type == Event::Closed) {
        GameWindow->close();
      }
    }

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
      character_sprite->move(-0.3, 0);
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
       character_sprite->move(0.3, 0);
     }

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
       character_sprite->move(0, -0.3);
     }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
       character_sprite->move(0, 0.3);
     }

    GameWindow->draw(*gameBg);
    GameWindow->draw(*character_sprite);
    GameWindow->display();
  }

  GameWindow->close();
}
