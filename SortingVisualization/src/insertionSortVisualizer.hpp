#pragma once

#include "sortVisualizer.hpp"


namespace Visualizer {

    class InsertionSortVisualizer : public SortVisualizer
    {
    public:
        InsertionSortVisualizer(SDL_Renderer* renderer);
        ~InsertionSortVisualizer();

        void sort();

    private:
        void addPointers() override;
        void insertionSort();

        // pointers
        int idxOnePtr;
        int idxTwoPtr;
    };

}