#include "arrow.hpp"



Arrow::Arrow(SDL_Renderer* renderer)
    : m_renderer(renderer)

{
    m_texture = Utils::loadTexture(ARROW_TEXTURE, m_renderer);
    pointer = 1;
    m_distRect.h = 50;
    m_distRect.w = 58;

    m_distRect.x = 20;
    m_distRect.y = 65;

}

Arrow::~Arrow() {
    SDL_DestroyTexture(m_texture);
}


void Arrow::up() {
    if (pointer > 1) {
        pointer--;
        m_distRect.y -= ARROW_POS_INC;
    }
}

void Arrow::down() {
    if (pointer < 6) {
        pointer++;
        m_distRect.y += ARROW_POS_INC;
    }
}

void Arrow::update() {
    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_distRect);
}

SDL_Texture* Arrow::getTexture() { return m_texture;}
SDL_Rect& Arrow::getRect() { return m_distRect;}
int Arrow::getValue() {return pointer;}

