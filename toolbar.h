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



const char* stockset[]={GTK_STOCK_NEW,GTK_STOCK_OPEN,
                        GTK_STOCK_SAVE,GTK_STOCK_SAVE_AS,
                        ID_SEP,GTK_STOCK_CUT,GTK_STOCK_COPY,
                        GTK_STOCK_PASTE,GTK_STOCK_DELETE,ID_SEP,
                        GTK_STOCK_FIND,GTK_STOCK_FIND_AND_REPLACE,
                        ID_SEP,GTK_STOCK_SELECT_FONT};

const char* tipset[]={"New","Open",
                        "Save","Save As..",
                        ID_SEP,"Cut","Copy",
                        "Paste","Delete",ID_SEP,
                        "Find","Replace"};

void MakeToolbar()
{
    toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar),GTK_TOOLBAR_ICONS);

    int i;

    for(i=0;i<15;i++)
    {
        if (stockset[i]==ID_SEP)  toolitems[i]=gtk_separator_tool_item_new();
        else
        {
            toolitems[i]=gtk_tool_button_new_from_stock(stockset[i]);
            gtk_widget_set_tooltip_text(GTK_WIDGET(toolitems[i]),tipset[i]);
        }
        gtk_toolbar_insert(GTK_TOOLBAR(toolbar),toolitems[i],-1);
    }

    g_signal_connect(toolitems[0],"clicked",G_CALLBACK(NewFile),NULL);
    g_signal_connect(toolitems[1],"clicked",G_CALLBACK(LoadFile),NULL);
    g_signal_connect(toolitems[2],"clicked",G_CALLBACK(SaveFile),NULL);
    g_signal_connect(toolitems[3],"clicked",G_CALLBACK(SaveFileAs),NULL);
    g_signal_connect(toolitems[5],"clicked",G_CALLBACK(EditText),ID_CUT);
    g_signal_connect(toolitems[6],"clicked",G_CALLBACK(EditText),ID_COPY);
    g_signal_connect(toolitems[7],"clicked",G_CALLBACK(EditText),ID_PASTE);
    g_signal_connect(toolitems[8],"clicked",G_CALLBACK(EditText),ID_DEL);
    g_signal_connect(toolitems[10],"clicked",G_CALLBACK(FindText),NULL);
    g_signal_connect(toolitems[11],"clicked",G_CALLBACK(ReplaceText),NULL);
    g_signal_connect(toolitems[13],"clicked",G_CALLBACK(ShowFontDiag),NULL);


}
