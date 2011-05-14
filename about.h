

void SplashInfo()
{
    adiag = gtk_about_dialog_new();
    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(adiag),"Quick-Ed");
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(adiag),"1.0");
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(adiag),"http://burningprodigy.webs.com");
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(adiag),"Programmed by Muhammad Ahmad Tirmazi");
    gtk_dialog_run(GTK_DIALOG(adiag));
    gtk_widget_destroy(GTK_WIDGET(adiag));
}

void SplashHelp()
{
    system("start /max hh.exe Quick-Ed_Help.chm");
}
