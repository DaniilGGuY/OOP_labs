#ifndef DRAWSCENEQTCOMMAND_H
#define DRAWSCENEQTCOMMAND_H

#include <QGraphicsScene>

#include "basedrawcommand.h"

class DrawSceneQtCommand : public BaseDrawCommand
{
public:
    DrawSceneQtCommand() = delete;
    DrawSceneQtCommand(QGraphicsScene *scene_visual);
    ~DrawSceneQtCommand() = default;

    void execute() override;

private:
    QGraphicsScene *_scene_visual;
};

#endif // DRAWSCENEQTCOMMAND_H
