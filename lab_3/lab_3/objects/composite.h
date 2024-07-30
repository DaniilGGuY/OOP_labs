#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"

class Composite : public Object
{
public:
    Composite() = default;
    Composite(std::vector<std::shared_ptr<Object>> objects);

    ~Composite() = default;

    iterator begin() override;
    iterator end() override;

    void add(const std::shared_ptr<Object> obj) override;
    void remove(const iterator &it) override;

    std::shared_ptr<Object> clone() const override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    Point getCenter() const override;
    bool isComposite() const override;
    bool isVisible() const override;

private:
    std::vector<std::shared_ptr<Object>> _objects;
};

#endif // COMPOSITE_H
