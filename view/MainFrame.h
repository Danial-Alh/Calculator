//
// Created by danial on 7/3/15.
//

#ifndef CACULATOR_MAINFRAME_H
#define CACULATOR_MAINFRAME_H

#include <gtk/gtk.h>
#include <string>
#include "MainFrame.h"
using namespace std;

class MainFrame {

private:
    static const string _view_prefix_path;

    GtkBuilder *builder;

    GObject *window;

    GObject **_num_button;
    GObject *_executor_button;
    GObject **_operator_button;

    GObject *_memory_save_button;
    GObject *_memory_callback_button;
    GObject *_clear_button;

    GObject *_expression_field;
    GObject *_history_view;

    void init();
    void load_view();

public:
    MainFrame();

protected:
};

#endif //CACULATOR_MAINFRAME_H
