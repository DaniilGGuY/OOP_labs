#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include "visitor.h"
#include "drawer/basedrawer.h"
#include "transform/cameraaction.h"

class DrawVisitor : public Visitor
{
public:
    DrawVisitor() = delete;
    DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> view);
    ~DrawVisitor() = default;

    void visit(Camera &camera) const override;
    void visit(CarcasModel &model) const override;

private:
    Point getNewPlace(const Point &point) const;
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _view;
};

#endif // DRAWVISITOR_H
