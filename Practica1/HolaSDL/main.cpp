#include "SDL.h"
#include "checkML.h"
#include "Game.h"
#include <iostream>

using namespace std;

void exampleLeak() {
    int* a = new int(5);
}

int main(int argc, char* argv[]) {

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks

    try {
        Game game;
       // game.Menu();
        game.run();
    }
    catch (const std::string& e) {
        std::cout << e << '\n';
    }

    return 0;
}