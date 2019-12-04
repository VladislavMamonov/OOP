#include "MotionCompGraphicObj.hpp"


void Animations::frame_update()
{
  if (*ResolutionOption == 1)
    *CurrentFrame += 1;

  if (*ResolutionOption == 2)
    *CurrentFrame += 1;

  if (*ResolutionOption == 3)
    *CurrentFrame += 0.5;

  if (*ResolutionOption < 1 || *ResolutionOption > 3)
    *CurrentFrame += 1;
}


void Animations::hero_left_animation()
{
  frame_update();

  if (*CurrentFrame > 384)
    *CurrentFrame -= 384;

  if (*CurrentFrame == 128)
    character_sprite->setTextureRect(IntRect(128 + 115, 0, -115, 160));

  if (*CurrentFrame == 256)
    character_sprite->setTextureRect(IntRect(275+115, 0, -115, 160));

  if (*CurrentFrame == 384)
    character_sprite->setTextureRect(IntRect(10+115, 0, -115, 160));


  if (collision_handling() == 0)
    character_sprite->move(-0.1, 0);
  else
    character_sprite->move(2, 0);
}


void Animations::hero_right_animation()
{
  frame_update();

  if (*CurrentFrame > 384)
    *CurrentFrame -= 385;

  if (*CurrentFrame == 128)
    character_sprite->setTextureRect(IntRect(128, 0, 115, 160));

  if (*CurrentFrame == 256)
    character_sprite->setTextureRect(IntRect(275, 0, 115, 160));

  if (*CurrentFrame == 384)
    character_sprite->setTextureRect(IntRect(10, 0, 115, 160));

  if (collision_handling() == 0)
    character_sprite->move(0.1, 0);
  else
    character_sprite->move(-2, 0);
}


void Animations::hero_up_animation()
{
  frame_update();

  if (*CurrentFrame > 384)
    *CurrentFrame -= 385;

  if (*CurrentFrame == 128)
    character_sprite->setTextureRect(IntRect(157, 330, 115, 160));

  if (*CurrentFrame == 256)
    character_sprite->setTextureRect(IntRect(290, 330, 115, 160));

  if (*CurrentFrame == 384)
    character_sprite->setTextureRect(IntRect(10, 330, 115, 160));

  if (collision_handling() == 0)
    character_sprite->move(0, -0.1);
  else
    character_sprite->move(0, 2);
}


void Animations::hero_down_animation()
{
  frame_update();

  if (*CurrentFrame > 384)
    *CurrentFrame -= 385;

  if (*CurrentFrame == 128)
    character_sprite->setTextureRect(IntRect(157, 165, 115, 160));

  if (*CurrentFrame == 256)
    character_sprite->setTextureRect(IntRect(290, 165, 115, 160));

  if (*CurrentFrame == 384)
    character_sprite->setTextureRect(IntRect(10, 165, 115, 160));

  if (collision_handling() == 0)
    character_sprite->move(0, 0.1);
  else
    character_sprite->move(0, -2);
}
