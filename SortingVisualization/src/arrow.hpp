#pragma once 

#include "SDL.h"
#include "utils.hpp"
#include "universals.hpp"


class Arrow {

public:
    Arrow(SDL_Renderer* renderer);
    ~Arrow();
    
    void up();
    void down();

    void update();

    int getValue();
    SDL_Texture* getTexture();
    SDL_Rect& getRect();

private:
    int pointer;
    SDL_Rect m_distRect;
    SDL_Texture* m_texture;
    SDL_Renderer* m_renderer;
};

