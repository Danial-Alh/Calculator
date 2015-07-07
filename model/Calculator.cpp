//
// Created by danial on 7/3/15.
//

#include "Calculator.h"

const int Calculator::NUMBER_OF_STATES = 4;
const int Calculator::NUMBER_OF_INPUT_TYPES = 5;


//  ###############     OPERAND_CHARACTER       OPERATOR        MEMORY_SAVE         MEMORY_READ         CLEAR_HISTORY
//  FIRST_OPERAND   #                       #               #                   #                   #
//  OPERATOR_SELECT #                       #               #                   #                   #
//  SECOND_OPERAND  #                       #               #                   #                   #
//  SHOW_RESULT     #                       #               #                   #                   #

Calculator::Calculator()
: Calculator::automata{
        {FIRST_OPERAND  ,OPERATOR_SELECT    ,FIRST_OPERAND      ,FIRST_OPERAND      ,FIRST_OPERAND},
        {SECOND_OPERAND ,OPERATOR_SELECT    ,OPERATOR_SELECT    ,SECOND_OPERAND     ,FIRST_OPERAND},
        {SECOND_OPERAND ,SHOW_RESULT        ,SECOND_OPERAND     ,SECOND_OPERAND     ,FIRST_OPERAND},
        {FIRST_OPERAND  ,SECOND_OPERAND     ,SHOW_RESULT        ,FIRST_OPERAND      ,FIRST_OPERAND}              }
{
}

void Calculator::automata_init()
{
}

void Calculator::go_to_next_state()
{

}

void Calculator::execute_operation()
{

}

void Calculator::clear_history()
{

}

void Calculator::save_in_memory()
{

}

void Calculator::read_from_memory()
{

}
