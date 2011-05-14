//Quick-Ed Pro is licensed under the BSD 4-Clause License.
//This File is part of Quick-Ed Pro
//
//
//
//Copyright (c) 2011, Muhammad Ahmad Tirmazi
//All rights reserved.
//
//
//                            BSD 4-CLAUSE LICENSE
//
//
//Redistribution and use in source and binary forms, with or without
//modification, are permitted provided that the following conditions are met:
//1. Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//2. Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//3. All advertising materials mentioning features or use of this software
//   must display the following acknowledgement:
//   This product includes software developed by Muhammad Ahmad Tirmazi.
//4.The name of Muhammad Ahmad Tirmazi  may not be used to
//   endorse or promote products derived from this software without
//   specific prior written permission.
//
//
//THIS SOFTWARE IS PROVIDED BY Muhammad Ahmad Tirmazi ''AS IS'' AND ANY
//EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//DISCLAIMED. IN NO EVENT SHALL Muhammad Ahmad Tirmazi BE LIABLE FOR ANY
//DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
//(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
//ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



void LoadFile(char *fname)
{
    FILE *f;

    /* Iterator is an object that represents positions between two characters in a buffer */
    GtkTextIter p;

    char fbuf[CHAR_BUF];
    size_t l; /* read the contents of file in size_t l */

    if (!fname)
    {
        /* create file selection dialog */
        GtkWidget *dialog = gtk_file_selection_new("Open File...");
        int resp = gtk_dialog_run(GTK_DIALOG(dialog));
        if(resp == GTK_RESPONSE_OK)
        {
        /* fname contains the file selected by the user */

                /* show the file selection dialog */
            fname = g_strdup(gtk_file_selection_get_filename(GTK_FILE_SELECTION(dialog)));
            gtk_widget_destroy(dialog);
        }

        else
        {
            gtk_widget_destroy(dialog);
        }
    }

    if(!(f = fopen(fname, "r"))) /* if file cannot be opened */
    {
	g_printerr("%s: %s\n", fname, g_strerror(errno));
	return;
    }


    if(fname != filename)
    {
	gchar *wt = g_strdup_printf("Quick-Ed Pro (%s)", fname);
	g_free(filename);
	filename = fname;
        /* set titlebar as the file name */
	gtk_statusbar_push(GTK_STATUSBAR(statusbar), 0, fname);
	gtk_text_buffer_set_text(GTK_TEXT_BUFFER(Tbuffer),"",0);
	g_free(wt);
    }

    /* put the ending iterator in p of buffer */
    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(Tbuffer), &p);

    while((l = fread(fbuf, 1, sizeof(fbuf), f)) > 0)
    {
        /* only text files in Utf-8 format can be opened */

	GError *err = NULL;
	gsize br, bw;
	gchar *text;
	if(!(text = g_locale_to_utf8(fbuf, l, &br, &bw, &err)))
	{
	    g_printerr("File is not in UTF-8 format : %s\n", err->message);
	    g_clear_error(&err);
            filename = NULL; /* If an invalid file is opened enter the file name as NULL */
	    gtk_window_set_title(GTK_WINDOW(Mwin), "Text Editor (Insert file name)");
	    fclose(f);

	    return;
	}
	gtk_text_buffer_insert(GTK_TEXT_BUFFER(Tbuffer), &p, text, bw);
	g_free(text);
    }


    gtk_text_buffer_set_modified(GTK_TEXT_BUFFER(Tbuffer), FALSE);

    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(Tbuffer), &p);
    gtk_text_buffer_place_cursor(GTK_TEXT_BUFFER(Tbuffer), &p);
    if(ferror(f))
    {
	g_printerr("%s: %s\n", fname, g_strerror(errno));
	fclose(f);
	return;
    }
    if(fclose(f) == EOF)
	g_printerr("%s: %s\n", fname, g_strerror(errno));

}

void NewFile()
{
    filename = NULL;
    Tbuffer = gtk_text_buffer_new(gtk_text_buffer_get_tag_table(GTK_TEXT_BUFFER(Tbuffer)));
    gtk_text_view_set_buffer(GTK_TEXT_VIEW(Tview), GTK_TEXT_BUFFER(Tbuffer));
	g_object_unref(G_OBJECT(Tbuffer));
}

void SaveFile()
{
    FILE *f;
    int ok = TRUE;

    char* fname = filename;

    if(!fname)
    {
	GtkWidget *dialog = gtk_file_selection_new("Save File As...");
	int resp = gtk_dialog_run(GTK_DIALOG(dialog));
	if(resp == GTK_RESPONSE_OK) {
	    fname = g_strdup(
		gtk_file_selection_get_filename(GTK_FILE_SELECTION(dialog)));
	    gtk_widget_destroy(dialog);
	} else {
	    gtk_widget_destroy(dialog);
	    return;
	}
    }

    if(!(f = fopen(fname, "w")))  /* Error opening file */
    {
	g_printerr("%s: %s\n", fname, g_strerror(errno));
	ok = FALSE;
    } else {
	GtkTextIter start, end, p;

        /* get the starting and ending position */

	gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(Tbuffer), &start, &end);
	p = start;
	while(!gtk_text_iter_equal(&start, &end)) {
	    gchar *buf, *fbuf;
	    gsize br, bw;
	    GError *err = NULL;
	    gtk_text_iter_forward_chars(&p, CHAR_BUF);
	    buf = gtk_text_iter_get_slice(&start, &p);
	    fbuf = g_locale_from_utf8(buf, -1, &br, &bw, &err);
	    g_free(buf);

	    if(!fbuf)
            {
		g_printerr("Failed UTF-8 to locale conversion: %s\n",
			   err->message);
		g_clear_error(&err);
		ok = FALSE;
		break;
	    }
	    fwrite(fbuf, bw, 1, f);
	    g_free(fbuf);
	    if(ferror(f)) {
		g_printerr("%s: %s\n", fname, g_strerror(errno));
		ok = FALSE;
		break;
	    }
	    start = p;
	}
	if(fclose(f) == EOF)
        {
	    g_printerr("%s: %s\n", fname, g_strerror(errno));
	    ok = FALSE;
	}
    }

    if(ok)
    {
	gtk_text_buffer_set_modified(GTK_TEXT_BUFFER(Tbuffer), FALSE);
	if(fname != filename) {
	    gchar *wt = g_strdup_printf("Quick-Ed Pro (%s)", fname);
	    g_free(filename);
	    filename = fname;
	    gtk_statusbar_push(GTK_STATUSBAR(statusbar), 0, fname);
	    g_free(wt);
	}
    }
    return;
}

void SaveFileAs()
{
    GtkWidget *dialog = gtk_file_selection_new("Save File As...");
	int resp = gtk_dialog_run(GTK_DIALOG(dialog));
	if(resp == GTK_RESPONSE_OK)
	{
	    filename = g_strdup(
		gtk_file_selection_get_filename(GTK_FILE_SELECTION(dialog)));
	    gtk_widget_destroy(dialog);
	}
	else
	{
	    gtk_widget_destroy(dialog);
	}
    SaveFile();
}

