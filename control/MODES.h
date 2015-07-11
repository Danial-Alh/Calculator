//
// Created by danial on 7/6/15.
//

#ifndef CALCULATOR_PROOFOFCONCEPT_HEADER_FILE_H
#define CALCULATOR_PROOFOFCONCEPT_HEADER_FILE_H

#include <bits/stringfwd.h>
#include <string>

enum OPERATION_MODE
{
    ADD = 0,
    SUB = 1,
    MULTIPLY = 2,
    DIVIDE = 3,
    EXECUTE = 4
};
static const int NUMBER_OF_OPERATIONS = 5;


enum INPUT_TYPES
{
    OPERAND_CHARACTER,
    OPERATOR,
    MEMORY_SAVE,
    MEMORY_READ,
    CLEAR_HISTORY
};
static const int NUMBER_OF_INPUT_TYPES = 5;

enum STATE_MODES
{
    FIRST_OPERAND,
    OPERATOR_SELECT,
    SECOND_OPERAND,
    RESULT
};

class ViewReaction
{
public:
    enum REACTION
    {
        CLEAR_EXPRESSION_FIELD,
        SHOW_NUMBER,
        CLEAR_ALL,
        NOTHING
    } reaction;
int number;
bool update_history;
std::string history_text;

    ViewReaction()
    {
        number = 0;
        update_history = false;
    }
};



#endif //CALCULATOR_PROOFOFCONCEPT_HEADER_FILE_H

