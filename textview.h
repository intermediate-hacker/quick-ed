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


void MakeTextView()
{
    Tswin = gtk_scrolled_window_new(NULL,NULL);
    Tview = gtk_text_view_new();

    Tbuffer = gtk_text_buffer_new(gtk_text_buffer_get_tag_table(GTK_TEXT_BUFFER(Tbuffer)));
    gtk_text_view_set_buffer(GTK_TEXT_VIEW(Tview), GTK_TEXT_BUFFER(Tbuffer));

    gtk_widget_grab_focus(GTK_WIDGET(Tview));
    gtk_container_add(GTK_CONTAINER(Tswin),Tview);
    gtk_text_view_set_left_margin(GTK_TEXT_VIEW(Tview),2);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(Tview),GTK_WRAP_WORD);
}

void DisableWrap()
{

    if (gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(chwrap)))
    {
        gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(Tview),GTK_WRAP_WORD);
    }

    else
    {
        gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(Tview),GTK_WRAP_NONE);
    }
}


