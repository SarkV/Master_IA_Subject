//----------------------------------------------------------------------------
//                                                        _   ________  __
//  Copyright VIU 2020                                   | | / /  _/ / / /
//  Author: Ivan Fuertes <ivan.fuertes@campusviu.es>     | |/ // // /_/ /
//                                                       |___/___/\____/
//----------------------------------------------------------------------------

#ifndef __DEFINES_H__
#define __DEFINES_H__ 1

#include "mathlib/vec2.h"
#include <vector>

#define GAME_NAME "05MVID"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 1024

#define TICKS_PER_SECOND 30
#define MAX_FRAME_SKIP 10

#define FOREGROUND_COLOR { 0, 0, 0, 255 }
#define SHADOW_COLOR {160, 160, 160, 255}

#define FONT_FILE "../assets/fonts/8bit2.ttf"
#define AGENT_BLUE_PATH "../assets/images/agent_blue.png"
#define AGENT_RED_PATH "../assets/images/agent_red.png"
#define AGENT_GREEN_PATH "../assets/images/agent_green.png"
#define AGENT_PURPLE_PATH "../assets/images/agent_purple.png"

#define MAP_PATH "../assets/images/mapa.bmp"

#define FPS_FONT_SIZE 30 //12

#define SCENE_NUMBER 1

enum PATH_STATUS{
    FOUND,
    NOT_FOUND
};

struct KinematicSteering {
  MathLib::Vec2 velocity{ 0.0f, 0.0f };
  float rotation{ 0.0f };
};

struct Steering {
  MathLib::Vec2 linear{ 0.0f, 0.0f };    //linear acceleration
  float angular{ 0.0f };                //angular acceleration
};

struct KinematicStatus {
  MathLib::Vec2 position{ 0.0f, 0.0f };
  float orientation {0.0f};
  MathLib::Vec2 velocity{ 0.0f, 0.0f };  //linear velocity
  float rotation{0.0f};               //angular velocity

  float speed{ 0.0f };
};

struct t_coord{
    int x;
    int y;

    bool operator==(t_coord& other)
    {
        return x == other.x && y == other.y;
    }
    bool operator!=(const t_coord& other)
    {
        return x != other.x || y != other.y;
    }
};

struct Path {
    uint8_t uid = 0;
    unsigned int pathFound = false;
    std::vector<t_coord> path;
    float timeLast = 0.0f;
};

struct PathNode{
    unsigned int isOpenClosed;
    t_coord parent;
    t_coord position;
    unsigned short G;

    bool operator()(PathNode*& lhs, PathNode*& rhs)
    {
        return lhs->G > rhs->G;
    }
};

#endif