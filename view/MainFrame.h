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

    static GtkBuilder *builder;

    static GObject *window;

    static GObject **_num_button;
    static GObject *_executor_button;
    static GObject **_operator_button;

    static GObject *_memory_save_button;
    static GObject *_memory_callback_button;
    static GObject *_clear_button;

    static GObject *_expression_field;
    static GObject *_history_view;

    void init();
    void load_view();

    static void on_numpad_clicked(GtkWidget *widget, gpointer   data);
    static void on_executor_clicked(GtkWidget *widget, gpointer   data);
    static void on_memory_save_clicked(GtkWidget *widget, gpointer   data);
    static void on_memory_callback_clicked(GtkWidget *widget, gpointer   data);
    static void on_clear_clicked(GtkWidget *widget, gpointer   data);

public:
    MainFrame();

protected:
};

#endif //CACULATOR_MAINFRAME_H
