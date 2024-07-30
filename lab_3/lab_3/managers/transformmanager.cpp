#include "transformmanager.h"
#include "visitors/transformvisitor.h"
#include "transform/rotateaction.h"
#include "transform/scaleaction.h"
#include "transform/transferaction.h"

void TransformManager::transferObject(std::shared_ptr<Object> object, double dx, double dy, double dz)
{
    TransformVisitor visitor(std::make_shared<TransferAction>(dx, dy, dz));
    object->accept(std::make_shared<TransformVisitor>(visitor));
}

void TransformManager::scaleObject(std::shared_ptr<Object> object, double kx, double ky, double kz)
{
    TransformVisitor visitor(std::make_shared<ScaleAction>(object->getCenter(), kx, ky, kz));
    object->accept(std::make_shared<TransformVisitor>(visitor));
}

void TransformManager::rotateObject(std::shared_ptr<Object> object, double x_angle, double y_angle, double z_angle)
{
    TransformVisitor visitor(std::make_shared<RotateAction>(object->getCenter(), x_angle, y_angle, z_angle));
    object->accept(std::make_shared<TransformVisitor>(visitor));
}

void TransformManager::transformObject(std::shared_ptr<Object> object, std::shared_ptr<TransformAction> action)
{
    TransformVisitor visitor(action);
    object->accept(std::make_shared<TransformVisitor>(visitor));
}
