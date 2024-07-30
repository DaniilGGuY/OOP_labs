#ifndef MATRIXLOADCOMMAND_H
#define MATRIXLOADCOMMAND_H

#include "baseloadcommand.h"

class MatrixLoadCommand : public BaseLoadCommand
{
public:
    MatrixLoadCommand();
    virtual ~MatrixLoadCommand() = default;
    void execute() override;
};

#endif // MATRIXLOADCOMMAND_H
