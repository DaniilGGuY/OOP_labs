#ifndef TRANSFERACTION_H
#define TRANSFERACTION_H

#include "transformaction.h"

class TransferAction : public TransformAction
{
public:
    TransferAction() = default;
    TransferAction(double dx, double dy, double dz);
    virtual ~TransferAction() = default;
};

#endif // TRANSFERACTION_H
