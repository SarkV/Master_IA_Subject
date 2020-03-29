//----------------------------------------------------------------------------
//                                                        _   ________  __
//  Copyright VIU 2020                                   | | / /  _/ / / /
//  Author: Ivan Fuertes <ivan.fuertes@campusviu.es>     | |/ // // /_/ /
//                                                       |___/___/\____/
//----------------------------------------------------------------------------

#include "ia/agent.h"
#include "ia/world.h"
#include <engine\ui_manager.h>

void Agent::init(World* world, const Body::Color color, const Body::Type type) {
  world_ = world;
  body_.init(color, type);
  mind_.init(world, &body_);
}

void Agent::shutdown() {
  world_ = nullptr;
}

void Agent::setPath(Path pathFound)
{
    mind_.setPath(pathFound);
}

void Agent::update(const uint32_t dt) {
  mind_.update(dt);
  body_.update(dt);
}

void Agent::render() const {
  mind_.render();
  body_.render();
}

