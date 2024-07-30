#include "scene.h"
#include "objects/composite.h"

Scene::Scene() : _objects(std::list<std::shared_ptr<Object>>()), _cameras(std::list<iterator>()) {}

Scene::iterator Scene::begin() { return _objects.begin(); }

Scene::iterator Scene::end() { return _objects.end(); }

Scene::const_iterator Scene::begin() const { return _objects.begin(); }

Scene::const_iterator Scene::end() const { return _objects.end(); }

Scene::const_iterator Scene::cbegin() const { return _objects.cbegin(); }

Scene::const_iterator Scene::cend() const { return _objects.cend(); }

Scene::reverse_iterator Scene::rbegin() { return _objects.rbegin(); }

Scene::reverse_iterator Scene::rend() { return _objects.rend(); }

Scene::const_reverse_iterator Scene::rbegin() const { return _objects.rbegin(); }

Scene::const_reverse_iterator Scene::rend() const { return _objects.rend(); }

Scene::const_reverse_iterator Scene::crbegin() const { return _objects.crbegin(); }

Scene::const_reverse_iterator Scene::crend() const { return _objects.crend(); }

Scene::camera_iterator Scene::cameraBegin() { return _cameras.cbegin(); }

Scene::camera_iterator Scene::cameraEnd() { return _cameras.cend(); }

Scene::size_type Scene::size() const { return _objects.size(); }

void Scene::add(const std::shared_ptr<Object> object)
{
    _objects.push_back(object);

    if (!object->isVisible())
    {
        auto it = _objects.begin();
        auto next = ++_objects.begin();
        for (; next != _objects.end(); ++it, ++next);
        _cameras.push_back(it);
    }
}

void Scene::add(const std::vector<std::shared_ptr<Object>> objects)
{
    std::shared_ptr<Composite> comp = std::make_shared<Composite>();
    for (const auto &it : objects)
        comp->add(it);

    add(comp);
}

void Scene::removeObject(const const_iterator &it) { _objects.erase(it); }

void Scene::removeCamera(const camera_iterator &it)
{
    _objects.erase(*it);
    _cameras.erase(it);
}

std::shared_ptr<Object> Scene::getCamera(const camera_iterator &it) { return **it; }

void Scene::accept(std::shared_ptr<Visitor> visitor)
{
    for (const auto &it : _objects)
        it->accept(visitor);
}

std::shared_ptr<Scene> Scene::clone()
{
    std::shared_ptr<Scene> clone_scene = std::make_shared<Scene>();
    auto c_it = cameraBegin();
    for (const auto &it : _objects)
    {
        if (c_it != cameraEnd() && it == **c_it)
        {
            clone_scene->add(it->clone());
            ++c_it;
        }
        else
            clone_scene->add(it->clone());
    }

    return clone_scene;
}
