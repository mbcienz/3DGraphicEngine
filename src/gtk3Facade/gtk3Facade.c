#include "../../headers/gtk3Facade.h"
#include <stdlib.h>
#include <string.h>

window *initInterface(){
    window *mw = (window *)malloc(sizeof(window));
    if(mw == NULL){
        printf("Error during window memory allocation\n");
        exit(1);
    }
    gtk_init(NULL, NULL);
    return mw;
};

//create the window
void createWindow(window *mw, int width, int height, char *title, char *color){ 
    mw->mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //set parameter
    setWindowWidth(&(mw->width), width);
    setWindowHeight(&(mw->height), height);
    setWindowTitle(&(mw->title), title);
    setWindowBackgroundColor(&(mw->backGroundColor), color);

    gtk_window_set_default_size(GTK_WINDOW (mw->mainWindow), mw->width, mw->height);
    gtk_window_set_title(GTK_WINDOW (mw->mainWindow), mw->title);
    gtk_widget_override_background_color(mw->mainWindow,  GTK_STATE_FLAG_NORMAL, &(mw->backGroundColor));
    
    g_signal_connect(G_OBJECT(mw->mainWindow), "destroy", G_CALLBACK(close), mw);

    gtk_widget_show_all(mw->mainWindow);

};

//set the window width
void setWindowWidth(int *width, int value){
    if (value > 0)
        *width = value;
    else
        *width = 300;
};

//set the window height
void setWindowHeight(int *height, int value){
    if (value > 0)
        *height = value;
    else
        *height = 300;
};

void setWindowTitle(char **title, const char *value){
    if(title != NULL){
        free(*title);
        *title = malloc(strlen(value) + 1);
        strcpy(*title, value);
    }
};

void setWindowBackgroundColor(GdkRGBA *backGroundColor, char *color){
    gdk_rgba_parse(backGroundColor, color);
};

void close(GtkWidget *win, gpointer data){
    window *mw = (window *)data;
    freeall(mw);
    
    gtk_main_quit();
};

void freeall(window *mw){
    free(mw->title);
    free(mw);
};

void start(){
    gtk_main();
};