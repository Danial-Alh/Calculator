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

    enum STATE_MODES
    {
        FIRST_OPERAND,
        OPERATOR_SELECT,
        SECOND_OPERAND,
        SHOW_RESULT
    };

    enum INPUT_TYPES
    {
        OPERAND_CHARACTER,
        OPERATOR,
        MEMORY_SAVE,
        MEMORY_READ,
        CLEAR_HISTORY
    };

    static const int NUMBER_OF_STATES,
    NUMBER_OF_INPUT_TYPES ;

    static const STATE_MODES automata[][NUMBER_OF_INPUT_TYPES];
    int memory;
    std::vector<Operation> operation_history;

    void automata_init();
    void go_to_next_state();
    void execute_operation();
    void clear_history();
    void save_in_memory();
    void read_from_memory();
protected:
};


#endif //CACULATOR_CALCULATOR_H
