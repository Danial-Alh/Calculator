//
// Created by danial on 7/3/15.
//

#include "Calculator.h"

const int Calculator::NUMBER_OF_STATES = 4;
const STATE_MODES Calculator::automata[][NUMBER_OF_INPUT_TYPES] =  {
                        {FIRST_OPERAND,     OPERATOR_SELECT,    FIRST_OPERAND,      FIRST_OPERAND      ,FIRST_OPERAND},
                        {SECOND_OPERAND,    OPERATOR_SELECT,    OPERATOR_SELECT,    SECOND_OPERAND     ,FIRST_OPERAND},
                        {SECOND_OPERAND,    RESULT,             SECOND_OPERAND,     SECOND_OPERAND     ,FIRST_OPERAND},
                        {FIRST_OPERAND,     SECOND_OPERAND,     RESULT,             FIRST_OPERAND      ,FIRST_OPERAND}              };

//  ###############     OPERAND_CHARACTER       OPERATOR        MEMORY_SAVE         MEMORY_READ         CLEAR_HISTORY
//  FIRST_OPERAND   #                       #               #                   #                   #
//  OPERATOR_SELECT #                       #               #                   #                   #
//  SECOND_OPERAND  #                       #               #                   #                   #
//  RESULT     #                       #               #                   #                   #

Calculator::Calculator()
{
    current_state = STATE_MODES::FIRST_OPERAND ;
    current_operation = new Operation();
    memory = 0;
}

ViewReaction * Calculator::proceed_to_next_state(INPUT_TYPES input_type, OPERATION_MODE operation_mode, int number)
{
    switch (input_type)
    {
        case INPUT_TYPES::OPERAND_CHARACTER:
            on_character_insertion(input_type);
            break;
        case INPUT_TYPES::OPERATOR:
            execute_operation(operation_mode, number, input_type);
            break;
        case INPUT_TYPES::MEMORY_SAVE:
            save_in_memory(number, input_type);
            break;
        case INPUT_TYPES::MEMORY_READ:
            read_from_memory(input_type);
            break;
        case INPUT_TYPES::CLEAR_HISTORY:
            clear_history(input_type);
            break;
    }
}

ViewReaction *Calculator::on_character_insertion(INPUT_TYPES input_type)
{
    ViewReaction *viewReaction = new ViewReaction();
    switch ( current_state )
    {
        case STATE_MODES::FIRST_OPERAND:
            viewReaction->reaction = ViewReaction::REACTION::NOTHING;
            break;
        case STATE_MODES::OPERATOR_SELECT:
            viewReaction->reaction = ViewReaction::REACTION::CLEAR_EXPRESSION_FIELD;
            break;
        case STATE_MODES::SECOND_OPERAND:
            viewReaction->reaction = ViewReaction::REACTION::NOTHING;
            break;
        case STATE_MODES::RESULT:
            viewReaction->reaction = ViewReaction::REACTION::CLEAR_EXPRESSION_FIELD;
            break;
    }
    current_state = automata[current_state][input_type];
    return viewReaction;
}

ViewReaction * Calculator::execute_operation(OPERATION_MODE mode, int number, INPUT_TYPES input_type)
{
    bool state_change_permission = true;
    ViewReaction *viewReaction = new ViewReaction();
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
            viewReaction->reaction = ViewReaction::REACTION::NOTHING;
            break;
        case STATE_MODES::OPERATOR_SELECT:
            if( mode != OPERATION_MODE::EXECUTE )
                current_operation->setOperation_mode(mode);
            else
                state_change_permission = false;
            viewReaction->reaction = ViewReaction::REACTION::NOTHING;
            break;
        case STATE_MODES::SECOND_OPERAND:
            current_operation->setFirstOperand(number);
            current_operation->calculate_result();
            operation_history.push_back(current_operation);
            current_operation = new Operation();
            if( mode != OPERATION_MODE::EXECUTE )
                current_operation->setOperation_mode(mode);
            viewReaction->reaction = ViewReaction::REACTION::SHOW_NUMBER;
            viewReaction->number = operation_history.back()->getResult();
            viewReaction->update_history = true;
            viewReaction->history_text = to_string_history();
            break;
        case STATE_MODES::RESULT:
            if( mode != OPERATION_MODE::EXECUTE )
                current_operation->setOperation_mode(mode);
            else
                state_change_permission = false;
            viewReaction->reaction = ViewReaction::REACTION::NOTHING;
            break;
    }
    if( state_change_permission )
        current_state = automata[current_state][input_type];
    return viewReaction;
}

ViewReaction * Calculator::clear_history(INPUT_TYPES input_type)
{
    ViewReaction *viewReaction = new ViewReaction();

    operation_history.clear();
    delete(current_operation);
    current_operation = new Operation();
    current_state = automata[current_state][input_type];
    viewReaction->reaction = ViewReaction::REACTION::CLEAR_ALL;
    return viewReaction;
}

ViewReaction * Calculator::save_in_memory(int number, INPUT_TYPES input_type)
{
    ViewReaction *viewReaction = new ViewReaction();
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
        case STATE_MODES::RESULT:
            memory = operation_history.back()->getResult();
            break;
    }
    current_state = automata[current_state][input_type];
    viewReaction->reaction = ViewReaction::REACTION::CLEAR_ALL;
    return viewReaction;
}

ViewReaction * Calculator::read_from_memory(INPUT_TYPES input_type)
{
    ViewReaction *viewReaction = new ViewReaction();
    switch ( current_state )
    {
        case STATE_MODES::FIRST_OPERAND:
            break;
        case STATE_MODES::OPERATOR_SELECT:
            break;
        case STATE_MODES::SECOND_OPERAND:
            break;
        case STATE_MODES::RESULT:
            break;
    }
    current_state = automata[current_state][input_type];
    viewReaction->reaction = ViewReaction::REACTION::SHOW_NUMBER;
    viewReaction->number = memory;
    return viewReaction;
}


std::string Calculator::to_string_history()
{
    std::string result = "";
    for( int i = 0; i < operation_history.size(); i++)
        result += ( operation_history.at(i)->to_string() + "\n" );
    return result;
}
