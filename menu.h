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


static GtkItemFactoryEntry menu_items[] =
{
    {"/_File",NULL,NULL,0,"<Branch>"},
    {"/File/_New","<control>N",NewFile,0,"<StockItem>",GTK_STOCK_NEW},
    {"/File/_Open","<control>O",LoadFile,0,"<StockItem>",GTK_STOCK_OPEN},
    {"/File/sep1",NULL,NULL,0,"<Separator>"},
    {"/File/_Save","<control>S",SaveFile,0,"<StockItem>",GTK_STOCK_SAVE},
    {"/File/Save _As",NULL,SaveFileAs,0,"<StockItem>",GTK_STOCK_SAVE_AS},
    {"/File/sep2",NULL,NULL,0,"<Separator>"},
    {"/File/_Exit","<control>Q",gtk_main_quit,0,"<StockItem>",GTK_STOCK_QUIT},
    {"/_Edit",NULL,NULL,0,"<Branch>"},
    {"/Edit/C_ut","<control>X",EditText,ID_CUT,"<StockItem>",GTK_STOCK_CUT},
    {"/Edit/_Copy","<control>C",EditText,ID_COPY,"<StockItem>",GTK_STOCK_COPY},
    {"/Edit/_Paste","<control>V",EditText,ID_PASTE,"<StockItem>",GTK_STOCK_PASTE},
    {"/Edit/_Delete","Delete",EditText,ID_DEL,"<StockItem>",GTK_STOCK_DELETE},
    {"/Edit/sep1",NULL,NULL,0,"<Separator>"},
    {"/Edit/_Find..","<control>F",FindText,0,"<StockItem>",GTK_STOCK_FIND},
    {"/Edit/_Replace..","<control>R",ReplaceText,0,"<StockItem>",GTK_STOCK_FIND_AND_REPLACE},
    {"/Edit/sep2",NULL,NULL,0,"<Separator>"},
    {"/Edit/Select _All","<control>A",EditText,ID_SELECT_ALL,"<StockItem>",GTK_STOCK_SELECT_ALL},
    {"/_Format",NULL,NULL,0,"<Branch>"},
    {"/Format/_Word Wrap",NULL,DisableWrap,0,"<CheckItem>"},
    {"/Format/_Font...","F3",ShowFontDiag,0,"<StockItem>",GTK_STOCK_SELECT_FONT},
    {"_View",NULL,NULL,0,"<Branch>"},
    {"/View/_Toolbar","F2",ToggleToolbarView,0,"<CheckItem>"},
    {"/View/_Statusbar","<shift>F2",ToggleStatusbarView,0,"<CheckItem>"},
    {"/_Help",NULL,NULL,0,"<Branch>"},
    {"/Help/_Help Topics","F1",SplashHelp,0,"<StockItem>",GTK_STOCK_HELP},
    {"/_Help/_About",NULL,SplashInfo,0,"<StockItem>",GTK_STOCK_INFO}
};

static gint nmenu_items = sizeof (menu_items) / sizeof (menu_items[0]);

static GtkWidget *get_menubar_menu( GtkWidget  *window )
{
  GtkAccelGroup *accel_group;

  accel_group = gtk_accel_group_new ();
  item_factory = gtk_item_factory_new (GTK_TYPE_MENU_BAR, "<main>",
                                       accel_group);
  gtk_item_factory_create_items (item_factory, nmenu_items, menu_items, NULL);
  gtk_window_add_accel_group (GTK_WINDOW (window), accel_group);
  return gtk_item_factory_get_widget (item_factory, "<main>");
}

void MakeMenu()
{
    menubar = get_menubar_menu(Mwin);

    chwrap = gtk_item_factory_get_item(GTK_ITEM_FACTORY(item_factory),
                                                  "/Format/Word Wrap");
    gtk_check_menu_item_set_state(chwrap,TRUE);

    chtbar = gtk_item_factory_get_item(GTK_ITEM_FACTORY(item_factory),
                                                  "/View/Toolbar");
    gtk_check_menu_item_set_state(chtbar,TRUE);

    chsbar = gtk_item_factory_get_item(GTK_ITEM_FACTORY(item_factory),
                                                  "/View/Statusbar");
    gtk_check_menu_item_set_state(chsbar,TRUE);
}
