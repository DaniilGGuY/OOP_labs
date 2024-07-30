#include "qtdrawer.h"
#include <QDebug>

QtDrawer::QtDrawer(QGraphicsScene *scene) : _scene(scene) {}

void QtDrawer::drawLine(const Point &p1, const Point &p2) { _scene->addLine(p1.getX(), p1.getY(), p2.getX(), p2.getY(), QPen(Qt::red)); }

void QtDrawer::clear() { _scene->clear(); }
