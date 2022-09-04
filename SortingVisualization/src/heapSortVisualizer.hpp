#pragma once

#include "sortVisualizer.hpp"


namespace Visualizer {

    class HeapSortVisualizer : public SortVisualizer
    {
    public:
        HeapSortVisualizer(SDL_Renderer* renderer);
        ~HeapSortVisualizer() {};

        void sort();

    private:
        void heapSort();
        void build_max_heap();
        void max_heapify(int i, int size_);
        void addPointers() override;

        // pointers
        int largest;
        int curr_i;
        int right;
        int end_ptr;
    };

}