#include "transformvisitor.h"
#include "objects/carcasmodel.h"
#include "objects/camera.h"

TransformVisitor::TransformVisitor(std::shared_ptr<TransformAction> action) : _action(action) {}

void TransformVisitor::visit(Camera &camera) const
{
    camera._self = _action->transform(camera._self);
    camera._normalForward = _action->transform(camera._normalForward);
    camera._normalRight = _action->transform(camera._normalRight);
    camera._normalUp = _action->transform(camera._normalUp);
}

void TransformVisitor::visit(CarcasModel &model) const
{
    model._model->transform(_action);
}
