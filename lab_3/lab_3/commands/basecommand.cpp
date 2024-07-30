#include "basecommand.h"

BaseCommand::~BaseCommand() {}

void BaseCommand::setManagers(std::shared_ptr<SceneManager> scene_mg,
                              std::shared_ptr<DrawManager> draw_mg,
                              std::shared_ptr<LoadManager> load_mg,
                              std::shared_ptr<TransformManager> transform_mg)
{
    _scene_mg = scene_mg;
    _draw_mg = draw_mg;
    _load_mg = load_mg;
    _transform_mg = transform_mg;
}
