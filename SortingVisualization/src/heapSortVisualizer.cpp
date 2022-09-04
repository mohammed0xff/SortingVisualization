#include "heapSortVisualizer.hpp"


using namespace Visualizer;



HeapSortVisualizer::HeapSortVisualizer(SDL_Renderer* renderer)
    :SortVisualizer(renderer)
{
    AlgorithmName = "Heap Sort";
    addPointers();
}



void HeapSortVisualizer::sort() {
    heapSort();
    gaze();
}



void HeapSortVisualizer::addPointers() {
    m_pointers.push_back(std::pair<int&, Color>(curr_i, YELLOW));
    m_pointers.push_back(std::pair<int&, Color>(largest, BLUE));
    m_pointers.push_back(std::pair<int&, Color>(end_ptr, GREEN));
}


void HeapSortVisualizer::max_heapify(int i, int size)
{
    curr_i = i;
    int left, right;
    largest, left = (2 * i) + 1, right = left + 1;

    if (left < size && m_arr[left] > m_arr[i])
        largest = left;
    else
        largest = i;

    if (right < size && m_arr[right] > m_arr[largest])
        largest = right;
    
    if (largest != i)
    {
        render();
        std::swap(m_arr[i], m_arr[largest]);
        incArrayAccess(2);
        max_heapify(largest, size);
    }
    incArrayAccess(4);
    incComparisons(6);
    render();
}



void HeapSortVisualizer::heapSort()
{

    // building max heap
    for (int i = (m_arr.size() / 2); i >= 0; i--) {
        max_heapify(i, m_arr.size());
    }

    for (end_ptr = m_arr.size() - 1; end_ptr > 0; end_ptr--)
    {
        // largest element of the array is at index 0. 
        // So the first value is swapped with the last value. 
        std::swap(m_arr[0], m_arr[end_ptr]);
        incArrayAccess(2);
        render();
        // remove the node with largest value from the tree..
        // and create new max-heap
        max_heapify(0, end_ptr);
    }
}

