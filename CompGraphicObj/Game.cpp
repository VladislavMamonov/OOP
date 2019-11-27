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
}


void GameInit::map_border_check()
{
  int PlayerCoordX = character_sprite->getPosition().x;
  int PlayerCoordY = character_sprite->getPosition().y;

  int WindowSizeX = GameWindow->getSize().x;
  int WindowSizeY = GameWindow->getSize().y;

  if (PlayerCoordX < 0)
    character_sprite->setPosition(WindowSizeX, PlayerCoordY);  //Граница слева

  if (PlayerCoordX > WindowSizeX)
    character_sprite->setPosition(0, PlayerCoordY);  //Граница справа

  if (PlayerCoordY < 0)
    character_sprite->setPosition(PlayerCoordX, WindowSizeY);  //Граница сверху

  if (PlayerCoordY > WindowSizeY)
    character_sprite->setPosition(PlayerCoordX, 0);  //Граница снизу
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
    character_sprite->setTextureRect(IntRect(157, 165, 115, 160));

    while (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
      hero_left_animation();
      map_border_check();
      game_draw();
    }

    while (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
      hero_right_animation();
      map_border_check();
      game_draw();
    }

    while (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
      hero_up_animation();
      map_border_check();
      game_draw();
    }

    while (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
      hero_down_animation();
      map_border_check();
      game_draw();
    }
    game_draw();
  }
  GameWindow->close();
}
