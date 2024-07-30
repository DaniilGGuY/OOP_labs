#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include "managers/loadmanager.h"
#include "managers/drawmanager.h"
#include "managers/scenemanager.h"
#include "managers/transformmanager.h"

class BaseCommand
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = 0;

    void setManagers(std::shared_ptr<SceneManager> scene_mg,
                     std::shared_ptr<DrawManager> draw_mg,
                     std::shared_ptr<LoadManager> load_mg,
                     std::shared_ptr<TransformManager> transform_mg);

    virtual void execute() = 0;

protected:
    std::shared_ptr<SceneManager> _scene_mg;
    std::shared_ptr<DrawManager> _draw_mg;
    std::shared_ptr<LoadManager> _load_mg;
    std::shared_ptr<TransformManager> _transform_mg;
};

#endif // BASECOMMAND_H
