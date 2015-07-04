//
// Created by danial on 7/3/15.
//

#include "MainFrame.h"

void MainFrame::init()
{
    window = gtk_builder_get_object( builder, "window1");
    for( int i = 0; i < 10; i++)
    {
        char obj_name[] = { 'b' , 'u', 't', 't', 'o', 'n' , '0'+i } ;
        _numpad[i] = gtk_builder_get_object( builder, obj_name );
    }

    _expression_field = gtk_builder_get_object( builder, "expression_view");
    gtk_text_buffer_set_text( gtk_text_view_get_buffer(GTK_TEXT_VIEW(_expression_field)) , "salam", -1);
}

void MainFrame::load_view()
{
    builder = gtk_builder_new();
    gtk_builder_add_from_file( builder, (view_prefix_path+"MainPanel.ui").c_str() , NULL);
}
