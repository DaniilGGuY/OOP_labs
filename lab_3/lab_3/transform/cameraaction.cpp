#include "cameraaction.h"
#include "objects/camera.h"
#include "transferaction.h"

CameraAction::CameraAction(std::shared_ptr<Camera> camera) : TransformAction(), _camera(camera)
{
    TransferAction center(-_camera->_self.getX(), -_camera->_self.getY(), -_camera->_self.getZ());

    _transform_matrix *= center.getTransformMatrix();

    SquareMatrix<double> basis(4, 0);
    basis[0][0] = _camera->_normalRight.getX() - _camera->_self.getX();
    basis[1][0] = _camera->_normalRight.getY() - _camera->_self.getY();
    basis[2][0] = _camera->_normalRight.getZ() - _camera->_self.getZ();

    basis[0][1] = _camera->_normalUp.getX() - _camera->_self.getX();
    basis[1][1] = _camera->_normalUp.getY() - _camera->_self.getY();
    basis[2][1] = _camera->_normalUp.getZ() - _camera->_self.getZ();

    basis[0][2] = _camera->_normalForward.getX() - _camera->_self.getX();
    basis[1][2] = _camera->_normalForward.getY() - _camera->_self.getY();
    basis[2][2] = _camera->_normalForward.getZ() - _camera->_self.getZ();

    _transform_matrix *= center.getTransformMatrix();
}
