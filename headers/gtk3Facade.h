#include <gtk/gtk.h>

typedef struct{
    GtkWidget *mainWindow;
    int height;
    int width;
    char *title;
    GdkRGBA backGroundColor;
}window;

//initialize the interface, allocates the struct
window *initInterface();

//create the window
void createWindow(window *mw, int width, int height, char *title, char *color);

//set the window width
void setWindowWidth(int *width, int value);

//set the window height
void setWindowHeight(int *height, int value);

//set the window title
void setWindowTitle(char **title, const char *value);

//set window background color
void setWindowBackgroundColor(GdkRGBA *backGroundColor, char *color);

//callback for closing the program
void close(GtkWidget *window, gpointer data);

//deallocate resource
void freeall(window *mw);

//execut the gtkmain() loop
void start();
