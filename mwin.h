

void MakeMainWindow()
{
    Mwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Mwin),"Quick-Ed Pro");
    gtk_widget_set_size_request(GTK_WIDGET(Mwin),500,450);
    gtk_window_set_position(GTK_WINDOW(Mwin),GTK_WIN_POS_CENTER);
    GTK_WINDOW(Mwin)->allow_shrink=TRUE;

    g_signal_connect(Mwin,"destroy",gtk_main_quit,NULL);
}
