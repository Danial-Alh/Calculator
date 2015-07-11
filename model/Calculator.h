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
    ViewReaction* proceed_to_next_state(INPUT_TYPES input_type, OPERATION_MODE operation_mode, int number);
private:



    static const int NUMBER_OF_STATES;

    static const STATE_MODES automata[][NUMBER_OF_INPUT_TYPES];
    STATE_MODES current_state;
    std::vector<Operation*> operation_history;
    Operation *current_operation;
    int memory;

    ViewReaction* on_character_insertion(INPUT_TYPES types);
    ViewReaction* execute_operation(OPERATION_MODE mode, int i, INPUT_TYPES types);
    ViewReaction* clear_history(INPUT_TYPES types);
    ViewReaction* save_in_memory(int i, INPUT_TYPES types);
    ViewReaction* read_from_memory(INPUT_TYPES types);
    std::string to_string_history();
protected:
};


#endif //CACULATOR_CALCULATOR_H
