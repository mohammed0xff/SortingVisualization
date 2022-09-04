#include "bubbleSortVisualizer.hpp"
using namespace Visualizer;



BubbleSortVisualizer::BubbleSortVisualizer(SDL_Renderer* renderer)
    :SortVisualizer(renderer)
{
    AlgorithmName = "Bubble Sort";
    addPointers();
}

BubbleSortVisualizer::~BubbleSortVisualizer()
{
}


void BubbleSortVisualizer::sort() {
    bubbleSort();
    gaze();
}


void BubbleSortVisualizer::addPointers() {
    m_pointers.push_back(std::pair<int&, Color>(idxOnePtr, BLUE));
    m_pointers.push_back(std::pair<int&, Color>(idxTwoPtr, GREEN));
}



void BubbleSortVisualizer::bubbleSort()
{
    bool swapped;

    for (idxOnePtr = startElement; idxOnePtr < endElement; idxOnePtr++)
    {
        swapped = false;
        for (idxTwoPtr = startElement; idxTwoPtr < endElement - (idxOnePtr - startElement); idxTwoPtr++)
        {
            render();
            if (m_arr[idxTwoPtr] > m_arr[idxTwoPtr + 1])
            {
                std::swap(m_arr[idxTwoPtr], m_arr[idxTwoPtr + 1]);
                swapped = true;
            }
            incArrayAccess(4);
            incComparisons(2);
        }
        if (swapped == false)
            break;
        incComparisons(1);
    }
}



