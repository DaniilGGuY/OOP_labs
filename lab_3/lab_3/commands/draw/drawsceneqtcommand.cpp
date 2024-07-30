#include "drawsceneqtcommand.h"
#include "drawer/qtdrawercreator.h"

DrawSceneQtCommand::DrawSceneQtCommand(QGraphicsScene *scene_visual) : _scene_visual(scene_visual) {}

void DrawSceneQtCommand::execute() { _draw_mg->drawScene<QtDrawerCreator, QGraphicsScene *>(_scene_mg, _scene_visual); }
