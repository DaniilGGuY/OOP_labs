#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "visitors/drawvisitor.h"
#include "drawer/basedrawercreator.h"
#include "scene/scene.h"

class DrawManager
{
public:
    DrawManager() = default;
    ~DrawManager() = default;

    template <typename DrawerCreator, typename... Args>
    void drawScene(std::shared_ptr<SceneManager> scene_mg, Args... args);
};

#include "drawmanager.hpp"

#endif // DRAWMANAGER_H
