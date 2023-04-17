#include "Window.hpp"
#include "WalkableTile.hpp"

int main() {
    
    Window* win = new Window;

    WalkableTile* wt = new WalkableTile();
    win->tile(5,5,*wt);

    win->renderWindow();

    return 0;
}