#pragma once
#include "sortVisualizer.hpp"


namespace Visualizer {

    class SelectionSortVisulaizer : public SortVisualizer
    {
    public:
        SelectionSortVisulaizer(SDL_Renderer* renderer);
	    ~SelectionSortVisulaizer();

        void sort() override;

    private:
        void addPointers() override;
	void selectionSort();

        // pointers
        int min_idxPtr;
        int idxOnePtr;
        int idxTwoPtr;

    };

}
