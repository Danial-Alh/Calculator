//
// Created by danial on 7/6/15.
//

#ifndef CALCULATOR_PROOFOFCONCEPT_OPERATION_H
#define CALCULATOR_PROOFOFCONCEPT_OPERATION_H

#include "../control/MODES.h"

class Operation
{
public:
private:
public:
    Operation();

    int getFirstOperand();
    int getSecondOperand();
    OPERATION_MODE & getOperation_mode();
    int getResult();

    void setOperation_mode(const OPERATION_MODE &operation_mode);
    void setResult(int result);
    void setFirstOperand(int number);
    void setSecondOperand(int number);

    void calculate_result();
private:
    int operand[2];
    OPERATION_MODE operation_mode;
    int result;
protected:
};


#endif //CALCULATOR_PROOFOFCONCEPT_OPERATION_H
