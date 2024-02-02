#include "../headers/gtk3Facade.h"

int main(int argc, char *argv[]) {
    window *ww = initInterface();
    createWindow(ww, 900, 450, "devEnvironment", "rgba(0,0,0,1)"); 
    start();
}
