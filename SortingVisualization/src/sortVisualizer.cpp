#include "sortVisualizer.hpp"

using namespace Visualizer;


bool SortVisualizer::running = true;



SortVisualizer::SortVisualizer(SDL_Renderer* renderer)
    : m_renderer(renderer)
{
    initText();
}


SortVisualizer::~SortVisualizer()
{
    TTF_CloseFont(font);
    SDL_DestroyTexture(messageTexture);
}


void SortVisualizer::init()
{
    numberOfElements = NUMBER_OF_ELEMENTS;
    startElement = 0;
    endElement = NUMBER_OF_ELEMENTS -1;
    arrayAccesses = 0;
    comparisons = 0;
    delay = DELAY;
    skip = false;
    perfectIncreasingElements();
    fitElementsToScreen();
}



void SortVisualizer::fitElementsToScreen() {
    int size = endElement - startElement;
    // space between each element.
    space = ((float)SCREEN_WIDTH / (float)size) * 0.2;
    // elements' rectangle width.
    rectWidth = DrawingRect.w = (float)(SCREEN_WIDTH - (space * size)) / (float)size;
}



void  SortVisualizer::render(bool renderPtrs) {
    if (!running || skip) return;

    handleInput();
    
    // Clear screen
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    // update text 
    updateStats();

    // display text 
    SDL_RenderCopy(m_renderer, messageTexture, NULL, &stats_rect);

    // set elements draw color
    SDL_SetRenderDrawColor(m_renderer, 220, 0, 0, 255);

    // render array 
    float startPosX = 0;
    for (size_t i = startElement; i <= endElement; i++)
    {
        DrawingRect.h = m_arr[i];
        DrawingRect.x = startPosX;
        DrawingRect.y = SCREEN_HEIGHT - m_arr[i];
        SDL_RenderFillRectF(m_renderer, &DrawingRect);
        startPosX += rectWidth + space;
    }

    if(renderPtrs) renderPointers();
    SDL_RenderPresent(m_renderer);
    SDL_Delay(delay);

}



// Rendering colored pointers used by the sort algorithm.
void SortVisualizer::renderPointers() {

    std::vector<std::pair<int&, Color>>::iterator itr;

    for (itr = m_pointers.begin(); itr != m_pointers.end(); ++itr) {

        int element_idx = itr->first;
        Color& clr = itr->second;

        if (element_idx >= startElement && element_idx <= endElement) {
            SDL_SetRenderDrawColor(m_renderer, clr.r, clr.g, clr.b, clr.a);

            DrawingRect.h = m_arr[element_idx];
            DrawingRect.x = (rectWidth + space) * (element_idx - startElement);
            DrawingRect.y = SCREEN_HEIGHT - m_arr[element_idx];

            SDL_RenderFillRectF(m_renderer, &DrawingRect);
        }
    }
}



void SortVisualizer::adjustSize()
{
    bool done = false;

    while (!done) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            switch (ev.type) {
            case SDL_QUIT:
                quit();
                done = true;
            case SDL_KEYDOWN:
                switch (ev.key.keysym.sym) {
                case SDLK_UP:
                    increaeArraySize();
                    break;
                case SDLK_DOWN:
                    decreaseArraySize();
                    break;
                case SDLK_SPACE:
                    done = true;
                }
            default:
                break;
            }
        }
        render(0);
    }

    perfectIncreasingElements();
    shuffleArray(true);

}




void SortVisualizer::perfectIncreasingElements() {

    int size = endElement - startElement;
    int startVal = 5;
    // Incrementing value
    int inc = (SCREEN_HEIGHT / size) * 0.75;

    // making array of a gradually increasing by {inc} value.
    m_arr.clear();
    for (size_t i = 0; i < size; i++)
    {
        m_arr.push_back(startVal);
        startVal += inc;
    }

    // updating start,end pointers.
    startElement = 0;
    endElement = size - 1;
}


void SortVisualizer::shuffleArray(bool rendering) {
    // Using Fisher-Yates Shuffle Algorithm.
    int n = m_arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        // generate a random number `j` such that `i <= j < n` and
        // swap the element present at index `j` with the element
        // present at current index `i`
        int j = i + rand() % (n - i);
        std::swap(m_arr[i], m_arr[j]);
        if (rendering) render(0);
    }
}


void SortVisualizer::decreaseArraySize() {
    if (startElement < HALF_ELEMENTS - 5 && endElement > HALF_ELEMENTS + 5) {
        startElement += 1; endElement -= 1;
        fitElementsToScreen();
    }
}


void SortVisualizer::increaeArraySize() {
    if (startElement > 0 && endElement < m_arr.size() -1 ) {
        startElement -= 1; endElement += 1;
        fitElementsToScreen();
    }
}


void SortVisualizer::goFaster() {
    if (delay > 50)
        delay -= 50;
}

void SortVisualizer::slowUp() {
    if (delay < 2000)
        delay += 50;
}



void SortVisualizer::handleInput() {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        switch (ev.type) {
        case SDL_QUIT:
            quit();
        case SDL_KEYDOWN:
            switch (ev.key.keysym.sym) {
            case SDLK_ESCAPE:
                skip = true;
                break;
            case SDLK_LEFT:
                slowUp();
                break;
            case SDLK_RIGHT:
                goFaster();
                break;
            case SDLK_SPACE:
                while (pause());
            }
        default:
            break;
        }
    }
}




bool SortVisualizer::pause() {

    SDL_Event ev;
    while (SDL_WaitEvent(&ev)) {
        switch (ev.type) {
        case SDL_QUIT:
            quit();
            return false;
        case SDL_KEYDOWN:
            switch (ev.key.keysym.sym) {
            case SDLK_SPACE:
                return 0;
            }
        default:
            break;
        }
    }
    SDL_Delay(30);
    return 1;
}


void SortVisualizer::initText() {

    font = TTF_OpenFont(TTF_FONT.c_str(), 16);

    stats_rect.x = 5;
    stats_rect.y = 5;
    stats_rect.w = 500;
    stats_rect.h = 25;
}

void SortVisualizer::updateStats() {

    // destroy previous displayed texture.
    SDL_DestroyTexture(messageTexture);

    statsMessage = AlgorithmName + " - Comparisons : " + std::to_string(comparisons) + " , Array accesses : " + std::to_string(arrayAccesses) + " , Delay : " + std::to_string(delay) + "ms";
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, statsMessage.c_str(), WHITE);

    messageTexture = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    // done with surface free it here.
    SDL_FreeSurface(surfaceMessage);
}


void SortVisualizer::quit() {
    running = false;
    delay = 0;
}


// Use this function at the end of function sort to 
// have a clear final look at your array elements before 
// switching to main minu.
void SortVisualizer::gaze() {
    render(0);
    SDL_Event ev;
    SDL_WaitEvent(&ev);
}

void SortVisualizer::incComparisons(int x) { comparisons += x; }
void SortVisualizer::incArrayAccess(int x) { arrayAccesses += x; }
