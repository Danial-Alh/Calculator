//
// Created by danial on 7/3/15.
//

#ifndef CACULATOR_CALCULATOR_H
#define CACULATOR_CALCULATOR_H

#include <vector>

#include "Operation.h"

class Calculator
{
public:
    Calculator();

private:
    static const int NUMBER_OF_STATES,
    NUMBER_OF_INPUT_TYPES ;

    int **automata;
    int memory;
    std::vector<Operation> operation_history;
protected:
};


#endif //CACULATOR_CALCULATOR_H
