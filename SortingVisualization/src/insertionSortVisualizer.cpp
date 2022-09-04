#include "insertionSortVisualizer.hpp"
using namespace Visualizer;


InsertionSortVisualizer::InsertionSortVisualizer(SDL_Renderer* renderer)
    :SortVisualizer(renderer)
{
    AlgorithmName = "Insertion Sort";
    addPointers();
}

InsertionSortVisualizer::~InsertionSortVisualizer()
{
}


void InsertionSortVisualizer::sort() {
    insertionSort();
    gaze();
}


void InsertionSortVisualizer::addPointers() {
    m_pointers.push_back(std::pair<int&, Color>(idxOnePtr, GREEN));
    m_pointers.push_back(std::pair<int&, Color>(idxTwoPtr, GREEN));
}



void InsertionSortVisualizer::insertionSort()
{
    int pivot;

    for (idxOnePtr = startElement; idxOnePtr <= endElement; idxOnePtr++)
    {
        pivot = m_arr[idxOnePtr];
        idxTwoPtr = idxOnePtr - 1;

        // Move elements that are greater than key and after the i-1 index
        // one position forward.
        while (idxTwoPtr >= startElement && m_arr[idxTwoPtr] > pivot)
        {
            m_arr[idxTwoPtr + 1] = m_arr[idxTwoPtr];
            incComparisons(3);
            incArrayAccess(3);
            render();
            idxTwoPtr = idxTwoPtr - 1;
        }
        m_arr[idxTwoPtr + 1] = pivot;
        incArrayAccess(1);
        incArrayAccess(2);
        render();
    }
}



