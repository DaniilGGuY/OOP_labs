#ifndef CAMERAACTION_H
#define CAMERAACTION_H

#include "transformaction.h"

class Camera;

class CameraAction : public TransformAction
{
public:
    CameraAction() = delete;
    CameraAction(std::shared_ptr<Camera> camera);
    ~CameraAction() = default;

private:
    std::shared_ptr<Camera> _camera;
};

#endif // CAMERAACTION_H
