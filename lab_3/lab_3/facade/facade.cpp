#include "facade.h"

Facade::Facade()
{
    _load_mg = std::make_shared<LoadManager>();
    _draw_mg = std::make_shared<DrawManager>();
    _transform_mg = std::shared_ptr<TransformManager>();
    _scene_mg = std::make_shared<SceneManager>();
}

void Facade::execute(BaseCommand &command)
{
    command.setManagers(_scene_mg, _draw_mg, _load_mg, _transform_mg);
    command.execute();
}
