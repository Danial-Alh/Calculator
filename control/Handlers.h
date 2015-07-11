//
// Created by danial on 7/3/15.
//

#ifndef CACULATOR_HANDLERS_H
#define CACULATOR_HANDLERS_H

#include "../view/MainFrame.h"
#include "../model/Calculator.h"

static class Handlers {

public:

    void on_operator_clicked( OPERATION_MODE operation_mode, std::string number );
    void on_charachter_insertion();
    void on_memory_save(std::string number);
    void on_memory_load();
    void on_clean();

private:
//    MainFrame *view;
//    Calculator *calculator;
    void do_reaction_on_view(ViewReaction *viewReaction);
    Handlers();
};


#endif //CACULATOR_HANDLERS_H
