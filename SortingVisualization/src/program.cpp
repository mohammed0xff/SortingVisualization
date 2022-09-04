#include "program.hpp"



Program::Program()
    : window(nullptr)
    , m_renderer(nullptr)
{
}


Program::~Program() {
	close();
}


void Program::run() {

    minu = new MainMinu(m_renderer);
    SortVisualizer* sortVisualizer = nullptr;

    while (SortVisualizer::running) {
        sortVisualizer = minu->choose();
        if (sortVisualizer != nullptr) {
            sortVisualizer->init();
            sortVisualizer->adjustSize();
            sortVisualizer->sort();
            sortVisualizer = nullptr;
        }
    }
}


bool Program::init() {

    // Initializing SDL 
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not be initialized.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "SDL_image could not be initialized.\n";
        std::cerr << "SDL_image Error : % s\n", IMG_GetError(), "\n";;
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf could not be initializeed.\n";
        std::cerr << "SDL_ttf Error : % s\n", TTF_GetError(), "\n";;
        return false;
    }

    // Creating Window
    window = SDL_CreateWindow(
        "Sort Visualizer", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == nullptr) {
        std::cerr << "Error creating window..\n";
        std::cerr << SDL_GetError() << "\n";
        return false;
    }

    // Creating renderer
    m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        std::cerr << "Error creating renderer..\n";
        std::cerr << SDL_GetError() << "\n";
        return false;

    }

    return true;

}



void Program::close() {

    SDL_RenderClear(m_renderer);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

