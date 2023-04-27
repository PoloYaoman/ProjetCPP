#include "GameWindow.h"

int main(void) {
    __cplusplus;
    GameWindow Window;

    /*Window.limitFramerate(60);
    std::cout << "Window \e[33mOpen" << std::endl;*/

    while (Window.isRunning()) {
        Window.controlWindow();
       // Window.verificationWindow();
       // Window.updateWindow();
    }

    std::cout << "\033[0mWindow \x1B[33mClose" << std::endl;
    return EXIT_SUCCESS;
}