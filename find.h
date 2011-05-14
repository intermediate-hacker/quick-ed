

void Find(GtkTextIter *iter)
{
    GtkTextIter Fstart,Fend;
    gboolean found;
    const gchar* text = gtk_entry_get_text(GTK_ENTRY(Fentry));

    found = gtk_text_iter_forward_search(iter,text,0,
                                         &Fstart,&Fend,NULL);

    if (found)
    {
        gtk_text_buffer_select_range(Tbuffer,&Fstart,&Fend);
        gtk_text_buffer_create_mark(Tbuffer,"last_pos",&Fend,FALSE);
    }

}

void FnextClick()
{
    const gchar* text = gtk_entry_get_text(GTK_ENTRY(Fentry));
    GtkTextMark *last_pos;
    GtkTextIter iter;

    last_pos = gtk_text_buffer_get_mark(GTK_TEXT_BUFFER(Tbuffer),"last_pos");

    if (last_pos==NULL)
    {
        GtkWidget *diag;
        diag = gtk_message_dialog_new(GTK_WINDOW(Mwin),GTK_DIALOG_MODAL,
                                      GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Search Ended");
        gtk_window_set_position (GTK_WINDOW (diag), GTK_WIN_POS_CENTER_ON_PARENT);
        gtk_dialog_run(GTK_DIALOG(diag));
        gtk_widget_destroy(GTK_WIDGET(diag));
        return;
    }

    gtk_text_buffer_get_iter_at_mark(GTK_TEXT_BUFFER(Tbuffer),&iter,last_pos);
    Find(&iter);
}

void FsearchClick()
{
    GtkTextIter iter;
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(Tbuffer),&iter);

    Find(&iter);
}

void FindText(void)
{
    GtkWidget *Fwin,*Fhbox,*Fvbox;
    GtkWidget *Fsearch,*Fnext;

    Fwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Fwin),"Find...");
    gtk_window_set_resizable(GTK_WINDOW(Fwin),FALSE);

    Fvbox = gtk_vbox_new(FALSE,5);
    Fhbox = gtk_hbox_new(FALSE,5);

    gtk_container_add(GTK_CONTAINER(Fwin),Fvbox);
    gtk_container_set_border_width(GTK_CONTAINER(Fwin),20);
    gtk_box_pack_start(GTK_BOX(Fvbox),Fhbox,FALSE,FALSE,0);

    Fentry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(Fhbox),Fentry,TRUE,TRUE,0);

    Fsearch = gtk_button_new_from_stock(GTK_STOCK_FIND);
    gtk_box_pack_start(GTK_BOX(Fhbox),Fsearch,FALSE,FALSE,0);
    g_signal_connect(Fsearch,"clicked",G_CALLBACK(FsearchClick),NULL);

    Fnext = gtk_button_new_with_label("Next");
    gtk_box_pack_start(GTK_BOX(Fhbox),Fnext,FALSE,FALSE,0);
    g_signal_connect(Fnext,"clicked",G_CALLBACK(FnextClick),NULL);

    gtk_widget_show_all(GTK_WIDGET(Fwin));
}
