#pragma once

#include "sortVisualizer.hpp"


namespace Visualizer {

    class MergeSortVisualizer : public SortVisualizer
    {
    public:
        MergeSortVisualizer(SDL_Renderer* renderer);
	    ~MergeSortVisualizer();

        void sort() override;

    private:
        void addPointers() override;

        void mergeSort( int const begin, int const end);
        void merge( int const left, int const mid, int const right);
    
        // pointers
        int subArrayOnePtr;
        int subArrayTwoPtr;

        int startArrOnePtr;
        int midPtr;
        int endArrTwoPtr;
    };

}



