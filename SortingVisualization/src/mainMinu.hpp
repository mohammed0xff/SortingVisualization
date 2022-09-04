#pragma once 

#include "mergeSortVisualizer.hpp"
#include "quickSortVisualizer.hpp"
#include "selectionSortVisualizer.hpp"
#include "bubbleSortVisualizer.hpp"
#include "heapSortVisualizer.hpp"
#include "insertionSortVisualizer.hpp"

#include "arrow.hpp"


using namespace Visualizer;


class MainMinu
{
public:
    MainMinu(SDL_Renderer* renderer);
    ~MainMinu();

    void update();
    SortVisualizer* chosenVisualizer();
    SortVisualizer* choose();

private:
    Arrow arrow;
    SDL_Texture* m_texture;
    SDL_Rect m_ScreenDistRect;
    SDL_Renderer* m_renderer;
    
	MergeSortVisualizer *mergeSortVisualizer;
	BubbleSortVisualizer *bubbleSortVisualizer;
	QuickSortSortVisualizer *quickSortSortVisualizer;
	SelectionSortVisulaizer *selectionSortVisulaizer;
	InsertionSortVisualizer * insertionSortVisualizer;
	HeapSortVisualizer *heapSortVisualizer;

};
