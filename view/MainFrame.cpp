//
// Created by danial on 7/3/15.
//

#include "MainFrame.h"

const string MainFrame::_view_prefix_path = "/home/danial/ClionProjects/Calculator_ProofOfConcept/view/";

MainFrame::MainFrame() {
    _num_button = new GObject*[10];
    _operator_button = new GObject*[4];
    gtk_init(NULL, NULL);

    load_view();
    init();

    gtk_widget_show_all( GTK_WIDGET(window));
    gtk_main();
}

void MainFrame::init()
{
    window = gtk_builder_get_object( builder, "window1");
    for( int i = 0; i < 10; i++)
    {
        char obj_name[] = { 'b' , 'u', 't', 't', 'o', 'n' , '0'+i } ;
        _num_button[i] = gtk_builder_get_object( builder, obj_name );
    }

    for( int i = 0; i < 4; i++)
    {
        char obj_name[] = { 'b' , 'u', 't', 't', 'o', 'n' , '0'+i } ;
        _operator_button[i] = gtk_builder_get_object( builder, obj_name);
    }
    _memory_save_button = gtk_builder_get_object( builder, "buttonM");
    _memory_callback_button = gtk_builder_get_object( builder, "buttonMR");
    _clear_button = gtk_builder_get_object( builder, "buttonC");
    _executor_button = gtk_builder_get_object( builder, "executor");

    _expression_field = gtk_builder_get_object( builder, "expressionField");
    _history_view = gtk_builder_get_object(builder, "historyView");
}

void MainFrame::load_view()
{
    builder = gtk_builder_new();
    gtk_builder_add_from_file( builder, (_view_prefix_path +"MainPanel.ui").c_str() , NULL);
}


//    gtk_text_buffer_set_text( gtk_text_view_get_buffer(GTK_TEXT_VIEW(_expression_field)) , "salam", -1);
//    GtkTextIter iter ;
//    gtk_text_buffer_get_end_iter (gtk_text_view_get_buffer(GTK_TEXT_VIEW(_expression_field)) ,&iter);
//    gtk_text_buffer_insert( gtk_text_view_get_buffer(GTK_TEXT_VIEW(_expression_field)),&iter, "     0",-1);


//    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(_expression_field));
//    GtkTextMark *mark;
//    GtkTextIter iter;
//    mark = gtk_text_buffer_get_insert (buffer);
//    gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
//    gtk_text_buffer_insert (buffer, &iter, " 0000", -1);