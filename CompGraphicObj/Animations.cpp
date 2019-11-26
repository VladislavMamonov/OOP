#include "MotionCompGraphicObj.hpp"


void Animations::hero_right_animation()
{
  *CurrentFrame += 1;

  if (*CurrentFrame > 384)
    *CurrentFrame -= 385;

  if (*CurrentFrame == 128)
    character_sprite->setTextureRect(IntRect(128, 3, 180, 163));

  if (*CurrentFrame == 256)
    character_sprite->setTextureRect(IntRect(300, 3, 90, 155));

  if (*CurrentFrame == 384)
    character_sprite->setTextureRect(IntRect(10, 3, 120, 160));


  character_sprite->move(0.2, 0);
}


void Animations::hero_up_animation()
{
  *CurrentFrame += 1;

  if (*CurrentFrame > 384)
    *CurrentFrame -= 385;

  if (*CurrentFrame == 128)
    character_sprite->setTextureRect(IntRect(157, 330, 115, 160));

  if (*CurrentFrame == 256)
    character_sprite->setTextureRect(IntRect(290, 330, 120, 160));

  if (*CurrentFrame == 384)
    character_sprite->setTextureRect(IntRect(10, 330, 120, 155));


  character_sprite->move(0, -0.2);
}
