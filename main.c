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




#include <gtk/gtk.h>
#include <errno.h>
#include <string.h>
#include "resource.h"
#include "mwin.h"
#include "mvbox.h"
#include "view.h"
#include "textview.h"
#include "find.h"
#include "replace.h"
#include "edit.h"
#include "font.h"
#include "about.h"
#include "statusbar.h"
#include "filehandle.h"
#include "menu.h"
#include "toolbar.h"
#include "packer.h"

int main(int argc, char* argv[])
{
    gtk_init(&argc,&argv);
    MakeMainWindow();
    MakeContainers();
    MakeMenu();
    MakeToolbar();
    MakeTextView();
    MakeStatusBar();
    PackAll();
    gtk_widget_show_all(GTK_WIDGET(Mwin));

    if(argc > 1)
	LoadFile(g_strdup(argv[1]));

    gtk_main();
    gtk_main_quit();
    return 0;
}
