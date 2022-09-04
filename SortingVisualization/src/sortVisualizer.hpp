#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>       

#include "universals.hpp"
#include "color.hpp"



namespace Visualizer {

    class SortVisualizer
    {
    public: 
        SortVisualizer(SDL_Renderer* renderer);
        ~SortVisualizer();
        static bool running;

        void init();
        void adjustSize();
        void virtual sort() = 0;
    
    private:
        void goFaster();
        void slowUp();
        void quit();

        void increaeArraySize();
        void decreaseArraySize();
        void perfectIncreasingElements();
        void shuffleArray(bool rendering);
        void fitElementsToScreen();
        void renderPointers();
        void handleInput();
        void updateStats();
        void initText();


    protected:
        void render(bool renderPtrs = true);
        bool pause();
        void virtual addPointers() = 0;
        void gaze();
        void incArrayAccess(int);
        void incComparisons(int);

    private:
        
        int delay;
        bool skip;
        int comparisons;
        int arrayAccesses;

        float space;
        float rectWidth;

        TTF_Font* font;
        SDL_FRect DrawingRect;
        SDL_Rect stats_rect;
        SDL_Texture* messageTexture;
        std::string statsMessage;

        SDL_Renderer* m_renderer;

    protected:
        std::vector <int> m_arr;
        std::vector<std::pair<int&, Color>> m_pointers;
        std::string AlgorithmName;

        int startElement;
        int endElement;
        int numberOfElements;

    };
}

