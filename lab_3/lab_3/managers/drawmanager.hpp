#ifndef DRAWMANAGER_HPP
#define DRAWMANAGER_HPP

#include "drawmanager.h"

template <typename DrawerCreator, typename... Args>
void DrawManager::drawScene(std::shared_ptr<SceneManager> scene_mg, Args... args)
{
    auto camera = scene_mg->getMainCamera();
    auto scene = scene_mg->getScene();
    DrawerCreator drawer_cr(args...);
    std::shared_ptr<BaseDrawer> drawer = drawer_cr.create();
    DrawVisitor visitor(drawer, camera);
    for (auto it = scene->begin(); it != scene->end(); ++it)
        (*it)->accept(std::make_shared<DrawVisitor>(visitor));
}

#endif // DRAWMANAGER_HPP
