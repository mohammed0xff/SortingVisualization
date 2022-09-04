#pragma once
#include "mainMinu.hpp"


class Program {

public:
    Program();
    ~Program();

    bool init();
    void run();
    void close();

private:
    MainMinu *minu;
    SDL_Window* window;
    SDL_Renderer* m_renderer ;

};