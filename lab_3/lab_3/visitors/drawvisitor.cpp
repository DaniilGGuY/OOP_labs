#include "drawvisitor.h"
#include "objects/camera.h"
#include "objects/carcasmodel.h"

#define FOCUS  500.0
#define R (1 / FOCUS)

DrawVisitor::DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> view) : _drawer(drawer), _view(view) {}

Point DrawVisitor::getNewPlace(const Point &point) const
{
    CameraAction action(_view);
    Point new_place(point);
    action.transform(new_place);
    return new_place;
}

void DrawVisitor::visit(Camera &camera) const
{
    (void)camera;
}

void DrawVisitor::visit(CarcasModel &model) const
{
    auto points = model._model->getPoints();
    auto edges = model._model->getEdges();

    for (auto &it : edges)
    {
        Point &p1 = points[it.getFirstVertex()];
        Point &p2 = points[it.getSecondVertex()];
        Point new_p1(getNewPlace(p1));
        Point new_p2(getNewPlace(p2));

        new_p1.setX(new_p1.getX() * (1 / (R * new_p1.getZ())));
        new_p1.setY(new_p1.getY() * (1 / (R * new_p1.getZ())));

        new_p2.setX(new_p2.getX() * (1 / (R * new_p2.getZ())));
        new_p2.setY(new_p2.getY() * (1 / (R * new_p2.getZ())));

        if (new_p1.getZ() > 0 && new_p2.getZ() > 0)
            _drawer->drawLine(new_p1, new_p2);
    }
}
