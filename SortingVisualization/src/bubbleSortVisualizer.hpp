#pragma once

#include "sortVisualizer.hpp"


namespace Visualizer {

    class BubbleSortVisualizer : public SortVisualizer
    {
    public:
        BubbleSortVisualizer(SDL_Renderer* renderer);
        ~BubbleSortVisualizer();

        void sort();

    private:
        void addPointers() override;
        void bubbleSort();
    
        // pointers
        int idxOnePtr;
        int idxTwoPtr;

    };

}