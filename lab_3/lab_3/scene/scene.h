#ifndef SCENE_H
#define SCENE_H

#include <list>

#include "objects/object.h"
#include "visitors/visitor.h"
#include "managers/scenemanager.h"

class Scene
{
    friend class SceneManager;
public:
    using iterator = std::list<std::shared_ptr<Object>>::iterator;
    using const_iterator = std::list<std::shared_ptr<Object>>::const_iterator;
    using reverse_iterator = std::list<std::shared_ptr<Object>>::reverse_iterator;
    using const_reverse_iterator = std::list<std::shared_ptr<Object>>::const_reverse_iterator;
    using difference_type = std::list<std::shared_ptr<Object>>::difference_type;
    using size_type = std::list<std::shared_ptr<Object>>::size_type;
    using camera_iterator = std::list<iterator>::const_iterator;

public:
    Scene();
    ~Scene() = default;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
    camera_iterator cameraBegin();
    camera_iterator cameraEnd();
    size_type size() const;

    void add(const std::shared_ptr<Object> object);
    void add(const std::vector<std::shared_ptr<Object>> objects);

    void removeObject(const const_iterator &it);
    void removeCamera(const camera_iterator &it);

    std::shared_ptr<Object> getCamera(const camera_iterator &it);

    void accept(std::shared_ptr<Visitor> visitor);
    std::shared_ptr<Scene> clone();

private:
    std::list<std::shared_ptr<Object>> _objects;
    std::list<iterator> _cameras;
};

#endif // SCENE_H
