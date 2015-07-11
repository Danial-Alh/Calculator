//
// Created by danial on 7/3/15.
//

#include "MainFrame.h"

const string MainFrame::_view_prefix_path = "/home/danial/ClionProjects/Calculator_ProofOfConcept/view/";
GtkBuilder *MainFrame::builder;
GObject *MainFrame::_window;
GObject **MainFrame::_num_button;
GObject **MainFrame::_operator_button;
GObject *MainFrame::_memory_save_button;
GObject *MainFrame::_memory_callback_button;
GObject *MainFrame::_clear_button;
GObject *MainFrame::_expression_field;
GObject *MainFrame::_history_view;



MainFrame::MainFrame(Handlers *handler) {
    this->handler = handler;

    _num_button = new GObject*[10];
    _operator_button = new GObject*[NUMBER_OF_OPERATIONS];
    gtk_init(NULL, NULL);

    load_view();
    init();

    gtk_widget_show_all(GTK_WIDGET(_window));
    gtk_main();
}

void MainFrame::init()
{
    _window = gtk_builder_get_object( builder, "window1");
    for( int i = 0; i < 10; i++)
    {
        char obj_name[] = { 'b' , 'u', 't', 't', 'o', 'n' , '0'+i, 0 } ;
        _num_button[i] = gtk_builder_get_object( builder, obj_name );
        g_signal_connect (_num_button[i], "clicked", G_CALLBACK(MainFrame::on_numpad_clicked), NULL);
    }

    for( int i = 0; i < NUMBER_OF_OPERATIONS; i++)
    {
        char obj_name[] = { 'o', 'p', 'e', 'r', 'a', 't', 'o', 'r', '0'+i, 0 } ;
        _operator_button[i] = gtk_builder_get_object( builder, obj_name);
        g_signal_connect (_operator_button[i], "clicked", G_CALLBACK(MainFrame::on_executor_clicked), NULL);
    }
    _memory_save_button = gtk_builder_get_object( builder, "buttonM");
    _memory_callback_button = gtk_builder_get_object( builder, "buttonMR");
    _clear_button = gtk_builder_get_object( builder, "buttonC");
    _expression_field = gtk_builder_get_object( builder, "expressionField");
    _history_view = gtk_builder_get_object(builder, "historyView");

    g_signal_connect (_window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect (_memory_save_button, "clicked", G_CALLBACK(MainFrame::on_memory_save_clicked), NULL);
    g_signal_connect (_memory_callback_button, "clicked", G_CALLBACK(MainFrame::on_memory_callback_clicked), NULL);
    g_signal_connect (_clear_button, "clicked", G_CALLBACK(MainFrame::on_clear_clicked), NULL);
    g_signal_connect(_expression_field,"key_press_event",G_CALLBACK(on_key_press),NULL);

}

void MainFrame::load_view()
{
    builder = gtk_builder_new();
    gtk_builder_add_from_file( builder, (_view_prefix_path +"MainPanel.ui").c_str() , NULL);
}

void MainFrame::on_executor_clicked(GtkWidget *widget, gpointer data)
{
    string expression( gtk_entry_get_text( GTK_ENTRY(_expression_field) ) );
    string label(gtk_button_get_label(GTK_BUTTON(widget))) ;


}

void MainFrame::on_numpad_clicked(GtkWidget *widget, gpointer data)
{
    string number(gtk_button_get_label(GTK_BUTTON(widget)) );
    int number_parsed;
    number_parsed = atoi(number.c_str());

    g_print( (number + " CLICKED\n").c_str() );

    GdkEvent *event = gdk_event_new(GdkEventType::GDK_KEY_PRESS);
    GdkEventKey eventKey = event->key;
    eventKey.window = GDK_WINDOW(gtk_widget_get_window(GTK_WIDGET(_expression_field)));
    eventKey.keyval = ((int)GDK_KEY_0)+number_parsed ;
    g_signal_emit_by_name(GTK_WIDGET(_expression_field), "key_press_event", &eventKey);
    gdk_event_free(event);
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

gboolean MainFrame::on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
    OPERATION_MODE mode;
    if( event->keyval >= GDK_KEY_0 && event->keyval <= GDK_KEY_9 )
    {
        handler->on_charachter_insertion();
        return false;
    }
    else
    {
        switch (event->keyval)
        {
            case GDK_KEY_Tab:
                return false;
            case GDK_KEY_BackSpace:
                return false;
            case GDK_KEY_plus:
                mode = OPERATION_MODE::ADD;
                break;
            case GDK_KEY_minus:
                mode = OPERATION_MODE::SUB;
                break;
            case GDK_KEY_asterisk:
                mode = OPERATION_MODE::MULTIPLY;
                break;
            case GDK_KEY_slash:
                mode = OPERATION_MODE::DIVIDE;
                break;
            case GDK_KEY_Return:
                mode = OPERATION_MODE::EXECUTE;
                break;
        }
        handler->on_operator_clicked(mode, get_expression_field_text());
    }
    return true;
}

void MainFrame::clear_expression_field()
{
    gtk_entry_set_text(GTK_ENTRY(_expression_field), "");
}

string MainFrame::get_expression_field_text()
{
    return string( gtk_entry_get_text(GTK_ENTRY(_expression_field)) );
}

void MainFrame::clear_all()
{
    gtk_entry_set_text(GTK_ENTRY(_expression_field), "");
    gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(_history_view)), "", -1 );
}

void MainFrame::show_number(string number)
{
    gtk_entry_set_text(GTK_ENTRY(_expression_field), number);
}

void MainFrame::set_history(string history_text)
{
    gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(_history_view)), history_text.c_str(), -1 );
}
