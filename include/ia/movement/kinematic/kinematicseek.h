//----------------------------------------------------------------------------
//                                                        _   ________  __
//  Copyright VIU 2020                                   | | / /  _/ / / /
//  Author: Ivan Fuertes <ivan.fuertes@campusviu.es>     | |/ // // /_/ /
//                                                       |___/___/\____/
//----------------------------------------------------------------------------

#ifndef __KINEMATIC_SEEK_H__
#define __KINEMATIC_SEEK_H__ 1

#include "ia/movement/movement.h"

class KinematicSeek : public Movement {
  public:
    KinematicSeek() {}
    ~KinematicSeek() {}

    void calculate(const KinematicStatus& character, const KinematicStatus* target, Steering* steering) override {
      //going full speed towards the target
      steering->velocity_linear = (target->position - character.position).normalized() * max_speed_;
      steering->rotation_angular = 0.0f;     //no rotation
    }
};
#endif