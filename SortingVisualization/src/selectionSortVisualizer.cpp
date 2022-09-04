#include "selectionSortVisualizer.hpp"

using namespace Visualizer;



SelectionSortVisulaizer::SelectionSortVisulaizer(SDL_Renderer* renderer)
    :SortVisualizer(renderer)
{
    AlgorithmName = "Selection Sort";
    addPointers();

}
SelectionSortVisulaizer::~SelectionSortVisulaizer()
{
}

void SelectionSortVisulaizer::sort() {
    selectionSort();
    gaze();
}


void SelectionSortVisulaizer::addPointers() {
    m_pointers.push_back(std::pair<int&, Color>(idxOnePtr, GREEN));
    m_pointers.push_back(std::pair<int&, Color>(idxTwoPtr, GREEN));
    m_pointers.push_back(std::pair<int&, Color>(min_idxPtr, BLUE));
}


void SelectionSortVisulaizer::selectionSort()
{
    for (idxOnePtr = startElement; idxOnePtr <= endElement; idxOnePtr++)
    {
        min_idxPtr = idxOnePtr;
        for (idxTwoPtr = idxOnePtr + 1; idxTwoPtr <= endElement; idxTwoPtr++) {

            if (m_arr[idxTwoPtr] < m_arr[min_idxPtr])
                min_idxPtr = idxTwoPtr;
            incArrayAccess(2);
            incComparisons(3);
            render();
        }
        std::swap(m_arr[min_idxPtr], m_arr[idxOnePtr]);
        incArrayAccess(2);
    }
}
