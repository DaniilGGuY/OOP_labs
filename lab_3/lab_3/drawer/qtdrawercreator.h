#ifndef QTDRAWERCREATOR_H
#define QTDRAWERCREATOR_H

#include <QGraphicsScene>

#include "basedrawercreator.h"

class QtDrawerCreator : public BaseDrawerCreator
{
public:
    QtDrawerCreator() = delete;
    QtDrawerCreator(QGraphicsScene *scene);
    ~QtDrawerCreator() = default;

    std::shared_ptr<BaseDrawer> create() override;

private:
    QGraphicsScene *_scene;
};

#endif // QTDRAWERCREATOR_H
