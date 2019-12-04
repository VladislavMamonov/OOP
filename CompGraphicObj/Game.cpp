#include "MotionCompGraphicObj.hpp"
#include <ctime>


void GameInit::load_game()
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
  collection_texture = new Texture();
  character_texture = new Texture;
  barrier_texture = new Texture();

  gameBackground->loadFromFile("images/Background_Game.jpg");
  collection_texture->loadFromFile("images/collection.png");
  character_texture->loadFromFile("images/character.png");
  barrier_texture->loadFromFile("images/barrier.png");

  gameBg = new Sprite(*gameBackground);
  collection_sprite = new Sprite(*collection_texture);
  character_sprite = new Sprite(*character_texture);
  barrier_sprite1 = new Sprite(*barrier_texture);
  barrier_sprite2 = new Sprite(*barrier_texture);
  barrier_sprite3 = new Sprite(*barrier_texture);
  barrier_sprite4 = new Sprite(*barrier_texture);
  barrier_sprite5 = new Sprite(*barrier_texture);
  barrier_sprite6 = new Sprite(*barrier_texture);

  ScoreInfo = new Text(L"Собрано ракушек: 0", *font, 40);
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
  GameWindow->draw(*ScoreInfo);
  GameWindow->draw(*collection_sprite);
  GameWindow->draw(*barrier_sprite1);
  GameWindow->draw(*barrier_sprite2);
  GameWindow->draw(*barrier_sprite3);
  GameWindow->draw(*barrier_sprite4);
  GameWindow->draw(*barrier_sprite5);
  GameWindow->draw(*barrier_sprite6);

  GameWindow->display();
}


void GameInit::game_proccess()
{
  srand(time(NULL));

  GameInit::load_objects();
  object_set_position(barrier_sprite1);
  object_set_position(barrier_sprite2);
  object_set_position(barrier_sprite3);
  object_set_position(barrier_sprite4);
  object_set_position(barrier_sprite5);
  object_set_position(barrier_sprite6);

  *PlayerScore = 0;

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
      collection_pick();
      map_border_check();
      game_draw();
    }

    while (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
      hero_right_animation();
      collection_pick();
      map_border_check();
      game_draw();
    }

    while (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
      hero_up_animation();
      collection_pick();
      map_border_check();
      game_draw();
    }

    while (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
      hero_down_animation();
      collection_pick();
      map_border_check();
      game_draw();
    }
    game_draw();
  }
  GameWindow->close();
  GameInit::delete_objects();
}


void GameInit::delete_objects()
{
  delete gameBackground;
  delete collection_texture;
  delete character_texture;
  delete barrier_texture;

  delete character_sprite;
  delete collection_sprite;
  delete gameBg;

  delete barrier_sprite1;
  delete barrier_sprite2;
  delete barrier_sprite3;
  delete barrier_sprite4;
  delete barrier_sprite5;
  delete barrier_sprite6;
}
