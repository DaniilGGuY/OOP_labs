#ifndef VISITOR_H
#define VISITOR_H

#include <memory>

class Camera;
class CarcasModel;

class Visitor
{
public:
    Visitor();
    virtual ~Visitor() = 0;
    virtual void visit(Camera &camera) const = 0;
    virtual void visit(CarcasModel &model) const = 0;
};

#endif // VISITOR_H
