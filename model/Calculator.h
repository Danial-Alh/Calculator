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
    void proceed_to_next_state(INPUT_TYPES input_type, OPERATION_MODE operation_mode, int number);

private:



    static const int NUMBER_OF_STATES;

    static const STATE_MODES automata[][NUMBER_OF_INPUT_TYPES];
    STATE_MODES current_state;
    std::vector<Operation*> operation_history;
    Operation *current_operation;
    int memory;

    bool execute_operation(OPERATION_MODE mode, int i);
    void clear_history();
    void save_in_memory(int i);
    void read_from_memory();
protected:
};


#endif //CACULATOR_CALCULATOR_H
