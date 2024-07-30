#include "carcasmodel.h"

CarcasModel::CarcasModel() : _model(nullptr) {}

CarcasModel::CarcasModel(const CarcasModel &carcas) : _model(carcas._model) {}

CarcasModel::CarcasModel(std::shared_ptr<CarcasStructure> model) : _model(model) {}

void CarcasModel::accept(std::shared_ptr<Visitor> visitor) { visitor->visit(*this); }

Point CarcasModel::getCenter() const { return _model->getCenter(); }
