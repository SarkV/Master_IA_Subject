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
#define ACTIVE_COLOR { 255, 0, 0, 0 }
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
    Found,
    Not_Found
};

enum NODE_COST {
    Normal = 10,
    Diagonal = 14
};

struct Steering {
  MathLib::Vec2 velocity{ 0.0f, 0.0f };    //velocity / linear acceleration
  float rotation{ 0.0f };                //rotation / angular acceleration
};

struct KinematicStatus {
  MathLib::Vec2 position{ 0.0f, 0.0f };
  float orientation {0.0f};
  bool needsToOrientate = true;
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
    int index = 0;
    std::vector<MathLib::Vec2> path;
    float timeLast = 0.0f;
    bool draw = false;
};

struct PathNode{
    uint32_t isOpenClosed; // 0 - non; 1 - Opn; 2 - Closed
    t_coord parent;
    t_coord position;
    uint16_t G = 0;
    uint32_t F = 0;
    uint16_t H = 0;

    bool operator()(PathNode*& lhs, PathNode*& rhs)
    {
        return lhs->F > rhs->F;
    }
};

#endif