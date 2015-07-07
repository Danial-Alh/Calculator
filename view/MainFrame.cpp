//
// Created by danial on 7/3/15.
//

#include "MainFrame.h"

const string MainFrame::_view_prefix_path = "/home/danial/ClionProjects/Calculator_ProofOfConcept/view/";
GtkBuilder *MainFrame::builder;
GObject *MainFrame::window;
GObject **MainFrame::_num_button;
GObject *MainFrame::_executor_button;
GObject **MainFrame::_operator_button;
GObject *MainFrame::_memory_save_button;
GObject *MainFrame::_memory_callback_button;
GObject *MainFrame::_clear_button;
GObject *MainFrame::_expression_field;
GObject *MainFrame::_history_view;



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
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    for( int i = 0; i < 10; i++)
    {
        char obj_name[] = { 'b' , 'u', 't', 't', 'o', 'n' , '0'+i, 0 } ;
        _num_button[i] = gtk_builder_get_object( builder, obj_name );
        g_signal_connect (_num_button[i], "clicked", G_CALLBACK(MainFrame::on_numpad_clicked), NULL);
    }

    for( int i = 0; i < 4; i++)
    {
        char obj_name[] = { 'o', 'p', 'e', 'r', 'a', 't', 'o', 'r', '0'+i, 0 } ;
        _operator_button[i] = gtk_builder_get_object( builder, obj_name);
        g_signal_connect (_operator_button[i], "clicked", G_CALLBACK(MainFrame::on_executor_clicked), NULL);
    }
    _memory_save_button = gtk_builder_get_object( builder, "buttonM");
    g_signal_connect (_memory_save_button, "clicked", G_CALLBACK(MainFrame::on_memory_save_clicked), NULL);
    _memory_callback_button = gtk_builder_get_object( builder, "buttonMR");
    g_signal_connect (_memory_callback_button, "clicked", G_CALLBACK(MainFrame::on_memory_callback_clicked), NULL);
    _clear_button = gtk_builder_get_object( builder, "buttonC");
    g_signal_connect (_clear_button, "clicked", G_CALLBACK(MainFrame::on_clear_clicked), NULL);
    _executor_button = gtk_builder_get_object( builder, "executor");
    g_signal_connect (_executor_button, "clicked", G_CALLBACK(MainFrame::on_executor_clicked), NULL);

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
//    gtk_text_buffer_insert (buffer, &iter, " 0000", -1);void MainFrame::on_numpad_clicked(GtkWidget* widget, gpointer data){

void MainFrame::on_executor_clicked(GtkWidget *widget, gpointer data)
{
    string expression( gtk_entry_get_text( GTK_ENTRY(_expression_field) ) );
    g_print( (expression +" CLICKED\n").c_str() );
}

void MainFrame::on_numpad_clicked(GtkWidget *widget, gpointer data)
{
    g_print( (string(gtk_button_get_label(GTK_BUTTON(widget))) +" CLICKED\n").c_str() );
}

void MainFrame::on_memory_save_clicked(GtkWidget *widget, gpointer data)
{
    g_print( (string(gtk_button_get_label(GTK_BUTTON(widget))) +" CLICKED\n").c_str() );
}

void MainFrame::on_memory_callback_clicked(GtkWidget *widget, gpointer data)
{
    g_print( (string(gtk_button_get_label(GTK_BUTTON(widget))) +" CLICKED\n").c_str() );
}

void MainFrame::on_clear_clicked(GtkWidget *widget, gpointer data)
{
    g_print( (string(gtk_button_get_label(GTK_BUTTON(widget))) +" CLICKED\n").c_str() );
}
