#include "MotionCompGraphicObj.hpp"
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

void Objects_Interaction::object_set_position(Sprite *sprite)
{
  character_sprite->setPosition(GameWindow->getSize().x/2.25,   //Позиция игрока
   GameWindow->getSize().y/2.7);

  collection_sprite->setPosition(GameWindow->getSize().x/6,     //Позиция ракушки
   GameWindow->getSize().y/5);

  sprite->setPosition(rand() % (GameWindow->getSize().x - 150),   //Позиция препятствия
   rand() % (GameWindow->getSize().y - 150));

  sprite->setTextureRect(IntRect(75, 5, 48, 170));
  ScoreInfo->setPosition(GameWindow->getSize().x/2.5, 0);     //Позиция счётчика очков

  barrier_sprite4->setRotation(90);
  barrier_sprite5->setRotation(90);
  barrier_sprite6->setRotation(90);
}


void Objects_Interaction::collection_pick()
{
  if (character_sprite->getGlobalBounds().intersects(collection_sprite->getGlobalBounds())) {
    *PlayerScore += 1;
    collection_sprite->setPosition(rand() % (GameWindow->getSize().x - 150),
     rand() % (GameWindow->getSize().y - 150));
  }
  ostringstream PlayerScoreStr;
  PlayerScoreStr << *PlayerScore;
  ScoreInfo->setString(L"Собрано ракушек: " + PlayerScoreStr.str());
}


int Objects_Interaction::collision_handling()
{
  if (character_sprite->getGlobalBounds().intersects(barrier_sprite1->getGlobalBounds())
   || character_sprite->getGlobalBounds().intersects(barrier_sprite2->getGlobalBounds())
   || character_sprite->getGlobalBounds().intersects(barrier_sprite3->getGlobalBounds())
   || character_sprite->getGlobalBounds().intersects(barrier_sprite4->getGlobalBounds())
   || character_sprite->getGlobalBounds().intersects(barrier_sprite5->getGlobalBounds())
   || character_sprite->getGlobalBounds().intersects(barrier_sprite6->getGlobalBounds())) {
     return 1;
  }
  return 0;
}
