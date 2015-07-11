//
// Created by danial on 7/3/15.
//

#include "Handlers.h"

Handlers::Handlers()
{
    view = new MainFrame(this);
    calculator = new Calculator();
}

void Handlers::on_operator_clicked(OPERATION_MODE operation_mode, string number)
{
    ViewReaction *viewReaction = calculator->proceed_to_next_state( INPUT_TYPES::OPERATOR, operation_mode, atoi(number.c_str()) );
    do_reaction_on_view( viewReaction );
}

void Handlers::on_charachter_insertion()
{
    ViewReaction *viewReaction = calculator->proceed_to_next_state( INPUT_TYPES::OPERAND_CHARACTER, (OPERATION_MODE)0 , 0);
    do_reaction_on_view( viewReaction );
}

void Handlers::on_memory_save(string number)
{
    ViewReaction *viewReaction = calculator->proceed_to_next_state( INPUT_TYPES::MEMORY_SAVE, (OPERATION_MODE)0 , atoi(number.c_str()));
    do_reaction_on_view( viewReaction );
}

void Handlers::on_memory_load()
{
    ViewReaction *viewReaction = calculator->proceed_to_next_state( INPUT_TYPES::MEMORY_READ, (OPERATION_MODE)0 , 0);
    do_reaction_on_view( viewReaction );
}

void Handlers::on_clean()
{
    ViewReaction *viewReaction = calculator->proceed_to_next_state( INPUT_TYPES::CLEAR_HISTORY, (OPERATION_MODE)0 , 0);
    do_reaction_on_view( viewReaction );
}

void Handlers::do_reaction_on_view(ViewReaction *viewReaction)
{
    switch (viewReaction->reaction)
    {
        case ViewReaction::REACTION::CLEAR_EXPRESSION_FIELD:
            view->clear_expression_field();
            break;
        case ViewReaction::REACTION::CLEAR_ALL:
            view->clear_all();
            break;
        case ViewReaction::REACTION::SHOW_NUMBER:
            view->show_number( std::to_string(viewReaction->number) );
            break;
        case ViewReaction::REACTION::NOTHING:
            break;
    }

    if( viewReaction->update_history )
        view->set_history( viewReaction->history_text );
}

