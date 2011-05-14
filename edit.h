

GdkAtom Tatom = GDK_SELECTION_CLIPBOARD;

void EditText(gpointer data, guint action, GtkWidget *widget)
{
    GtkTextIter tmp;

    switch(action)
    {
        case ID_CUT:
            gtk_text_buffer_cut_clipboard(GTK_TEXT_BUFFER(Tbuffer),
                                          gtk_clipboard_get(Tatom),TRUE);
            break;
        case ID_COPY:
            gtk_text_buffer_copy_clipboard(GTK_TEXT_BUFFER(Tbuffer),
                                           gtk_clipboard_get(Tatom));
            break;
        case ID_PASTE:
            gtk_text_buffer_paste_clipboard(GTK_TEXT_BUFFER(Tbuffer),
                                            gtk_clipboard_get(Tatom),NULL,TRUE);
            break;
        case ID_DEL:
            gtk_text_buffer_delete_selection(GTK_TEXT_BUFFER(Tbuffer),
                                             TRUE,TRUE);
            break;
        case ID_SELECT_ALL:
            gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(Tbuffer), &tmp);
            gtk_text_buffer_place_cursor(GTK_TEXT_BUFFER(Tbuffer), &tmp);
            gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(Tbuffer), &tmp);
            gtk_text_buffer_move_mark_by_name(GTK_TEXT_BUFFER(Tbuffer), "selection_bound", &tmp);
            break;
    }
}
