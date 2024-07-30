#ifndef CARCASMODEL_H
#define CARCASMODEL_H

#include "basemodel.h"
#include "structures/carcasstructure.h"
#include "visitors/drawvisitor.h"
#include "visitors/transformvisitor.h"

class CarcasModel : public BaseModel
{
    friend class TransformVisitor;
    friend class DrawVisitor;
public:
    CarcasModel();
    explicit CarcasModel(const CarcasModel &carcas);
    explicit CarcasModel(std::shared_ptr<CarcasStructure> model);
    ~CarcasModel() = default;

    void accept(std::shared_ptr<Visitor> visitor) override;
    Point getCenter() const override;

private:
    std::shared_ptr<CarcasStructure> _model;
};

#endif // CARCASMODEL_H
