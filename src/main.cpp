#include <iostream>
#include "GameController.h"
#include <cstdlib> // for std::system()
#include "io.h"

const int KB_ESCAPE = 27;

int main()
{
    GameController g;

    g.ReadBoard();

    g.run();

    return EXIT_SUCCESS;
}