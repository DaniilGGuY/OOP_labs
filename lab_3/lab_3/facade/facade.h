#ifndef FACADE_H
#define FACADE_H

#include "commands/basecommand.h"

class Facade
{
public:
    Facade();
    ~Facade() = default;

    void execute(BaseCommand &command);

private:
    std::shared_ptr<SceneManager> _scene_mg;
    std::shared_ptr<DrawManager> _draw_mg;
    std::shared_ptr<LoadManager> _load_mg;
    std::shared_ptr<TransformManager> _transform_mg;
};

#endif // FACADE_H
