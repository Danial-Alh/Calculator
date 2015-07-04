//
// Created by danial on 7/3/15.
//

#ifndef CACULATOR_MAINFRAME_H
#define CACULATOR_MAINFRAME_H

#include <gtk/gtk.h>
#include <string>
#include "MainFrame.h"

class MainFrame {

private:

    std::string view_prefix_path = "/home/danial/ClionProjects/Calculator_ProofOfConcept/view/";

    GtkBuilder *builder;

    GObject *window;

    GObject **_numpad;
    GObject *_equal;
    GObject **_operator;

    GObject *_expression_field;

    void init();
    void load_view();

public:


    MainFrame() {

        _numpad = new GObject*[10];
        _operator = new GObject*[4];
        gtk_init(NULL, NULL);

        load_view();
        init();

        gtk_widget_show_all( GTK_WIDGET(window));
        gtk_main();
    }

protected:
};


#endif //CACULATOR_MAINFRAME_H
