#include "mainMinu.hpp"



MainMinu::MainMinu(SDL_Renderer* renderer)
    : m_renderer(renderer)
    , arrow(renderer)
{

    m_texture = Utils::loadTexture(MAIN_MINU, m_renderer);

    m_ScreenDistRect.h = SCREEN_HEIGHT;
    m_ScreenDistRect.w = SCREEN_WIDTH;
    m_ScreenDistRect.x = 0;
    m_ScreenDistRect.y = 0;

    update();
     
	mergeSortVisualizer = new MergeSortVisualizer(m_renderer);
	bubbleSortVisualizer = new BubbleSortVisualizer(m_renderer);
	quickSortSortVisualizer = new QuickSortSortVisualizer(m_renderer);
	selectionSortVisulaizer = new SelectionSortVisulaizer(m_renderer);
	insertionSortVisualizer = new InsertionSortVisualizer(m_renderer);
	heapSortVisualizer = new HeapSortVisualizer(m_renderer);
    
}


MainMinu::~MainMinu() {
    delete mergeSortVisualizer;
    delete bubbleSortVisualizer;
    delete quickSortSortVisualizer;
    delete selectionSortVisulaizer;
    delete insertionSortVisualizer;
    delete heapSortVisualizer;
    SDL_DestroyTexture(m_texture);
}


void MainMinu::update() {

    SDL_RenderClear(m_renderer);

    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_ScreenDistRect);
    SDL_RenderCopy(m_renderer, arrow.getTexture(), NULL, &arrow.getRect());

    SDL_RenderPresent(m_renderer);
}



SortVisualizer* MainMinu::chosenVisualizer() {

    switch (arrow.getValue())
    {
    case 1:
        return mergeSortVisualizer;
    case 2:
        return bubbleSortVisualizer;
    case 3:
        return quickSortSortVisualizer;
    case 4:
        return selectionSortVisulaizer;
    case 5:
        return insertionSortVisualizer;
    case 6:
        return heapSortVisualizer;
    default:
        return nullptr;
    }
}





SortVisualizer* MainMinu::choose() {

    while (SortVisualizer::running) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {

            switch (ev.type) {

            case SDL_QUIT:
                SortVisualizer::running = 0;
                break;

            case SDL_KEYDOWN:
                switch (ev.key.keysym.sym) {
                case SDLK_UP:
                    arrow.up();
                    break;

                case SDLK_DOWN:
                    arrow.down();
                    break;

                case SDLK_SPACE:
                    return chosenVisualizer();
                default:
                    break;
                }
            default:
                break;
            }
        }
        update();
        SDL_Delay(50);
    }
    return nullptr;
}

