//----------------------------------------------------------------------------
//                                                        _   ________  __
//  Copyright VIU 2020                                   | | / /  _/ / / /
//  Author: Ivan Fuertes <ivan.fuertes@campusviu.es>     | |/ // // /_/ /
//                                                       |___/___/\____/
//----------------------------------------------------------------------------

#ifndef __SCENE_H__
#define __SCENE_H__ 1

#include <cstdint>
#include <SDL/SDL.h>

class Scene {
  public:
    virtual ~Scene() {};

    virtual void init() = 0;
    virtual void shutdown() = 0;

    virtual void update(uint32_t dt) = 0;
    virtual void handleMouseEvent(SDL_Event e, int x, int y) = 0;
    virtual void handleKeyEvent(SDL_Keycode key) = 0;
    virtual void render() = 0;
  protected:
    Scene() {};
};

#endif