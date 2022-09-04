#pragma once

#include "sortVisualizer.hpp"


namespace Visualizer {

    class QuickSortSortVisualizer : public SortVisualizer
    {
    public:
        QuickSortSortVisualizer(SDL_Renderer* renderer);
	    ~QuickSortSortVisualizer();

        void sort();

    private:
        void addPointers() override;
        void quickSort(int low, int high);
        int partition(int low, int high);
    
        // pointers
        int idxOnePtr;
        int idxTwoPtr;
        int pivot;
    };
}