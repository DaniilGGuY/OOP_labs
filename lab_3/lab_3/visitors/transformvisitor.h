#ifndef TRANSFORMVISITOR_H
#define TRANSFORMVISITOR_H

#include "visitor.h"
#include "transform/transformaction.h"

class TransformVisitor : public Visitor
{
public:
    TransformVisitor() = delete;
    TransformVisitor(std::shared_ptr<TransformAction> action);
    ~TransformVisitor() = default;

    void visit(Camera &camera) const override;
    void visit(CarcasModel &model) const override;

private:
    std::shared_ptr<TransformAction> _action;
};

#endif // TRANSFORMVISITOR_H
