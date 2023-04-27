#ifndef _CONTROLINTERFACE_H_
#define _CONTROLINTERFACE_H_

/// Special library
#include <SFML/Graphics.hpp>

/// STL
#include <iostream>
#include <vector>
#include <string>

class ControlInterface {

public:

    /// Start the game
    void executionGame(void);

    //Key event
    void key(const char* keyType);
};
#endif

