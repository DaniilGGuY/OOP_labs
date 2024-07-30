#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "objects/object.h"
#include "objects/camera.h"

class Scene;

class SceneManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    void setScene(std::shared_ptr<Scene> scene);
    void setCamera(std::shared_ptr<Camera> camera);
    void setCamera(size_t id);

    std::shared_ptr<Scene> getScene() const;
    std::vector<std::shared_ptr<Object>> getCameras() const;
    std::shared_ptr<Camera> getCamera(size_t id) const;
    std::shared_ptr<Camera> getMainCamera() const;
    std::vector<size_t> getCameraIds() const;
    std::vector<std::shared_ptr<Object>> getObjects() const;
    std::shared_ptr<Object> getObject(size_t id) const;
    std::vector<size_t> getObjectIds() const;

    void addObject(std::shared_ptr<Object> object);
    void addCamera(const Point &pos);

    void removeObject(size_t id);
    void removeCamera(size_t id);

    void makeComposite(std::vector<size_t> ids);

    void clearScene();

private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<Camera> _camera;
};

#endif // SCENEMANAGER_H
