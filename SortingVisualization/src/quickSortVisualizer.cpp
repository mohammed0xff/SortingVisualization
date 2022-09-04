#include "quickSortVisualizer.hpp"
using namespace Visualizer;


QuickSortSortVisualizer::QuickSortSortVisualizer(SDL_Renderer* renderer)
    :SortVisualizer(renderer)
{
    AlgorithmName = "Quick Sort";
    addPointers();
}

QuickSortSortVisualizer::~QuickSortSortVisualizer()
{
}

void QuickSortSortVisualizer::addPointers() {
    m_pointers.push_back(std::pair<int&, Color>(pivot, BLUE));
    m_pointers.push_back(std::pair<int&, Color>(idxOnePtr, GREEN));
    m_pointers.push_back(std::pair<int&, Color>(idxTwoPtr, GREEN));
}


void QuickSortSortVisualizer::sort() {
    quickSort(startElement, endElement);
    gaze();
}


int QuickSortSortVisualizer::partition(int low, int high)
{
    int piv = m_arr[high];
    idxOnePtr = (low - 1);

    for (idxTwoPtr = low; idxTwoPtr <= high - 1; idxTwoPtr++)
    {
        // If current element is smaller than the pivot
        if (m_arr[idxTwoPtr] < piv)
        {
            idxOnePtr++; // increment index of smaller element
            std::swap(m_arr[idxOnePtr], m_arr[idxTwoPtr]);
        }
        incComparisons(2);
        incArrayAccess(3);
        render();
    }
    std::swap(m_arr[idxOnePtr + 1], m_arr[high]);
    incArrayAccess(3);
    return (idxOnePtr + 1);
}


void QuickSortSortVisualizer::quickSort(int low, int high)
{
    if (low < high)
    {
        // partitioning index
        pivot = partition(low, high); 

        // Separately sort elements before
        // partition and after partition
        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }
}
