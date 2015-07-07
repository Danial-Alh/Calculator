//
// Created by danial on 7/3/15.
//

#include "Calculator.h"

const int Calculator::NUMBER_OF_STATES = 4;
const STATE_MODES Calculator::automata[][NUMBER_OF_INPUT_TYPES] =  {
                            {FIRST_OPERAND  ,OPERATOR_SELECT    ,FIRST_OPERAND      ,FIRST_OPERAND      ,FIRST_OPERAND},
                            {SECOND_OPERAND ,OPERATOR_SELECT    ,OPERATOR_SELECT    ,SECOND_OPERAND     ,FIRST_OPERAND},
                            {SECOND_OPERAND ,SHOW_RESULT        ,SECOND_OPERAND     ,SECOND_OPERAND     ,FIRST_OPERAND},
                            {FIRST_OPERAND  ,SECOND_OPERAND     ,SHOW_RESULT        ,FIRST_OPERAND      ,FIRST_OPERAND}              };

//  ###############     OPERAND_CHARACTER       OPERATOR        MEMORY_SAVE         MEMORY_READ         CLEAR_HISTORY
//  FIRST_OPERAND   #                       #               #                   #                   #
//  OPERATOR_SELECT #                       #               #                   #                   #
//  SECOND_OPERAND  #                       #               #                   #                   #
//  SHOW_RESULT     #                       #               #                   #                   #

Calculator::Calculator()
{
    current_state = STATE_MODES::FIRST_OPERAND ;
    current_operation = new Operation();
    memory = 0;
}

void Calculator::proceed_to_next_state(INPUT_TYPES input_type, OPERATION_MODE operation_mode, int number)
{
    bool change_state_permission = true;
    switch (input_type)
    {
        case INPUT_TYPES::OPERAND_CHARACTER:
            break;
        case INPUT_TYPES::OPERATOR:
            change_state_permission = execute_operation(operation_mode, number);
            break;
        case INPUT_TYPES::MEMORY_SAVE:
            save_in_memory(number);
            break;
        case INPUT_TYPES::MEMORY_READ:
            read_from_memory();
            break;
        case INPUT_TYPES::CLEAR_HISTORY:
            clear_history();
            break;
    }

    if( change_state_permission )
        current_state = automata[current_state][input_type];

}

bool Calculator::execute_operation(OPERATION_MODE mode, int number)
{
    bool state_change_permission = true;
    switch ( current_state )
    {
        case STATE_MODES::FIRST_OPERAND:
            if( mode != OPERATION_MODE::EXECUTE )
            {
                current_operation->setFirstOperand(number);
                current_operation->setOperation_mode(mode);
            }
            else
                state_change_permission = false;
            break;
        case STATE_MODES::OPERATOR_SELECT:
            if( mode != OPERATION_MODE::EXECUTE )
                current_operation->setOperation_mode(mode);
            else
                state_change_permission = false;
            break;
        case STATE_MODES::SECOND_OPERAND:
            current_operation->setFirstOperand(number);
            current_operation->calculate_result();
            operation_history.push_back(current_operation);
            current_operation = new Operation();
            if( mode != OPERATION_MODE::EXECUTE )
                current_operation->setOperation_mode(mode);
            break;
        case STATE_MODES::SHOW_RESULT:
            if( mode != OPERATION_MODE::EXECUTE )
                current_operation->setOperation_mode(mode);
            else
                state_change_permission = false;
            break;
    }
    return state_change_permission;

}

void Calculator::clear_history()
{
    operation_history.clear();
    delete(current_operation);
    current_operation = new Operation();
}

void Calculator::save_in_memory(int number)
{
    switch ( current_state )
    {
        case STATE_MODES::FIRST_OPERAND:
            memory = number;
            break;
        case STATE_MODES::OPERATOR_SELECT:
            break;
        case STATE_MODES::SECOND_OPERAND:
            memory = number;
            break;
        case STATE_MODES::SHOW_RESULT:
            memory = operation_history.back()->getResult();
            break;
    }
}

void Calculator::read_from_memory()
{
    switch ( current_state )
    {
        case STATE_MODES::FIRST_OPERAND:
            break;
        case STATE_MODES::OPERATOR_SELECT:
            break;
        case STATE_MODES::SECOND_OPERAND:
            break;
        case STATE_MODES::SHOW_RESULT:
            break;
    }
}
