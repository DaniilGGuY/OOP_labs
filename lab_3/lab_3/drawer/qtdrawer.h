#ifndef QTDRAWER_H
#define QTDRAWER_H

#include <QGraphicsScene>

#include "basedrawer.h"

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = delete;
    QtDrawer(QGraphicsScene *scene);
    ~QtDrawer() = default;
    void drawLine(const Point &p1, const Point &p2) override;
    void clear() override;

private:
    QGraphicsScene *_scene;
};

#endif // QTDRAWER_H
