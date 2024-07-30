#include "qtdrawercreator.h"
#include "qtdrawer.h"

QtDrawerCreator::QtDrawerCreator(QGraphicsScene *scene) : _scene(scene) {}

std::shared_ptr<BaseDrawer> QtDrawerCreator::create() { return std::make_shared<QtDrawer>(_scene); }
