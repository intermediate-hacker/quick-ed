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


void Replace(GtkTextIter *iter,gboolean rep)
{
    GtkTextIter Fstart,Fend;
    gboolean found;
    const gchar* text = gtk_entry_get_text(GTK_ENTRY(Sentry));
    const gchar* rtext = gtk_entry_get_text(GTK_ENTRY(Rentry));


    found = gtk_text_iter_forward_search(iter,text,0,
                                         &Fstart,&Fend,NULL);

    if (found)
    {
        gtk_text_buffer_select_range(Tbuffer,&Fstart,&Fend);
        gtk_text_buffer_create_mark(Tbuffer,"last_pos",&Fend,FALSE);

        if (rep)
        {
            int len = strlen(rtext);
            gtk_text_buffer_delete(Tbuffer,&Fstart,&Fend);
            gtk_text_buffer_insert(Tbuffer,&Fstart,rtext,len);
        }
    }

}

void FrepClick()
{
    GtkTextIter iter;
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(Tbuffer),&iter);
    Replace(&iter,TRUE);
}

void RsearchClick()
{
    GtkTextIter iter;
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(Tbuffer),&iter);
    Replace(&iter,FALSE);
}
void ReplaceText(void)
{
    GtkWidget *Fwin,*Fhbox,*Fvbox,*Rhbox;
    GtkWidget *Fsearch,*Frep;

    Fwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Fwin),"Replace...");
    gtk_window_set_resizable(GTK_WINDOW(Fwin),FALSE);

    Fvbox = gtk_vbox_new(FALSE,5);
    Fhbox = gtk_hbox_new(FALSE,5);
    Rhbox = gtk_hbox_new(FALSE,5);

    gtk_container_add(GTK_CONTAINER(Fwin),Fvbox);
    gtk_container_set_border_width(GTK_CONTAINER(Fwin),20);
    gtk_box_pack_start(GTK_BOX(Fvbox),Fhbox,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(Fvbox),Rhbox,FALSE,FALSE,0);

    Sentry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(Fhbox),Sentry,TRUE,TRUE,0);

    Rentry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(Rhbox),Rentry,TRUE,TRUE,0);

    Fsearch = gtk_button_new_with_label("   Find   ");
    gtk_box_pack_start(GTK_BOX(Fhbox),Fsearch,FALSE,FALSE,0);
    g_signal_connect(Fsearch,"clicked",G_CALLBACK(RsearchClick),NULL);

    Frep = gtk_button_new_with_label("Replace");
    gtk_box_pack_start(GTK_BOX(Rhbox),Frep,FALSE,FALSE,0);
    g_signal_connect(Frep,"clicked",G_CALLBACK(FrepClick),NULL);

    gtk_widget_show_all(GTK_WIDGET(Fwin));
}

