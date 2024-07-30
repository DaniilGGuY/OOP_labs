#include "scenemanager.h"
#include "scene/scene.h"

SceneManager::SceneManager() : _scene(std::make_shared<Scene>()), _camera(std::make_shared<Camera>()) {}

void SceneManager::setScene(std::shared_ptr<Scene> scene) { _scene = scene; }

void SceneManager::setCamera(std::shared_ptr<Camera> camera) { _camera = camera; }

void SceneManager::setCamera(size_t id) { _camera = getCamera(id); }

std::shared_ptr<Scene> SceneManager::getScene() const { return _scene; }

std::vector<std::shared_ptr<Object>> SceneManager::getCameras() const
{
    std::vector<std::shared_ptr<Object>> cameras;
    for (auto it = _scene->cameraBegin(); it != _scene->cameraEnd(); ++it)
        cameras.push_back(**it);

    return cameras;
}

std::shared_ptr<Camera> SceneManager::getCamera(size_t id) const
{
    for (auto it = _scene->cameraBegin(); it != _scene->cameraEnd(); ++it)
    {
       if ((**it)->getId() == id)
       {
           auto camera = std::dynamic_pointer_cast<Camera>(**it);
           if (camera)
               return camera;
       }
    }

    return nullptr;
}

std::shared_ptr<Camera> SceneManager::getMainCamera() const { return _camera; }

std::vector<size_t> SceneManager::getCameraIds() const
{
    std::vector<size_t> ids;
    for (auto it = _scene->cameraBegin(); it != _scene->cameraEnd(); ++it)
        ids.push_back((**it)->getId());

    return ids;
}

std::vector<std::shared_ptr<Object>> SceneManager::getObjects() const
{
    std::vector<std::shared_ptr<Object>> objects;
    for (auto it = _scene->begin(); it != _scene->end(); ++it)
        objects.push_back(*it);

    return objects;
}

std::shared_ptr<Object> SceneManager::getObject(size_t id) const
{
    for (auto it = _scene->begin(); it != _scene->end(); ++it)
    {
        if ((*it)->getId() == id)
            return *it;
    }

    return nullptr;
}

std::vector<size_t> SceneManager::getObjectIds() const
{
    std::vector<size_t> ids;
    for (auto it = _scene->begin(); it != _scene->end(); ++it)
        ids.push_back((*it)->getId());

    return ids;
}

void SceneManager::addObject(std::shared_ptr<Object> object) { _scene->add(object); }

void SceneManager::addCamera(const Point &pos)
{
    auto cam = std::make_shared<Camera>(pos);
    _scene->add(cam);
}

void SceneManager::removeObject(size_t id)
{
    for (auto it = _scene->cbegin(); it != _scene->end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            _scene->removeObject(it);
            return;
        }
    }
}

void SceneManager::removeCamera(size_t id)
{
    for (auto it = _scene->cameraBegin(); it != _scene->cameraEnd(); ++it)
    {
        if ((**it)->getId() == id)
        {
            _scene->removeCamera(it);
            return;
        }
    }
}

void SceneManager::makeComposite(std::vector<size_t> ids)
{
    std::vector<std::shared_ptr<Object>> objects;
    for (auto it = ids.begin(); it != ids.end(); ++it)
        objects.push_back(getObject(*it));

    _scene->add(objects);
}

void SceneManager::clearScene()
{
    _scene->_cameras.clear();
    _scene->_objects.clear();
}
