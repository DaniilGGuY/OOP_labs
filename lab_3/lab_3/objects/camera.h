#ifndef CAMERA_H
#define CAMERA_H

#include "invisibleobject.h"
#include "transform/cameraaction.h"
#include "visitors/drawvisitor.h"
#include "visitors/transformvisitor.h"

class Camera : public InvisibleObject
{
    friend class CameraAction;
    friend class TransformVisitor;
    friend class DrawVisitor;
public:
    Camera();
    Camera(double x, double y, double z);
    explicit Camera(const Point &point);
    explicit Camera(const Camera &camera);
    virtual ~Camera() = default;

    virtual void accept(std::shared_ptr<Visitor> visitor) override;
    virtual Point getCenter() const override;
    virtual bool isComposite() const override;

protected:
    Point _self;
    Point _normalForward;
    Point _normalUp;
    Point _normalRight;
};

#endif // CAMERA_H
