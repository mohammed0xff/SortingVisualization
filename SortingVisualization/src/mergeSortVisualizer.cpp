#include "mergeSortVisualizer.hpp"
using namespace Visualizer;


MergeSortVisualizer::MergeSortVisualizer(SDL_Renderer* renderer)
    :SortVisualizer(renderer)
{
    AlgorithmName = "Merge Sort";
    addPointers();
}


MergeSortVisualizer::~MergeSortVisualizer() {
}


void MergeSortVisualizer::sort() {
    mergeSort(startElement, endElement);
    gaze();
}


void MergeSortVisualizer::addPointers() {

    m_pointers.push_back(std::pair<int&, Color>(startArrOnePtr, GREEN));
    m_pointers.push_back(std::pair<int&, Color>(endArrTwoPtr, GREEN));
    m_pointers.push_back(std::pair<int&, Color>(midPtr, YELLOW));
    m_pointers.push_back(std::pair<int&, Color>(subArrayOnePtr, BLUE));
    m_pointers.push_back(std::pair<int&, Color>(subArrayTwoPtr, BLUE));
}




void MergeSortVisualizer::mergeSort(int const left, int const right)
{
    incComparisons(1);
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    merge(left, mid, right);
}




void MergeSortVisualizer::merge(int const left, int const mid, int const right)
{

    const int subArrayOne = mid - left + 1;
    const int subArrayTwo = right - mid;

    int* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo],
        * tempArray = new int[subArrayOne + subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = m_arr[left + i];
    incArrayAccess(subArrayOne);

    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = m_arr[mid + 1 + j];
    incArrayAccess(subArrayTwo);

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = 0;

    subArrayOnePtr = left;
    subArrayTwoPtr = mid;

    startArrOnePtr = left;
    midPtr = mid;
    endArrTwoPtr = right;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            tempArray[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            subArrayOnePtr++;
        }
        else {
            tempArray[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            subArrayTwoPtr++;
        }
        incArrayAccess(4);
        incComparisons(3);
        indexOfMergedArray++;
        render();
    }

    //  rest of SubArrayOne
    while (indexOfSubArrayOne < subArrayOne) {
        tempArray[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        subArrayOnePtr++;
        indexOfMergedArray++;
        incArrayAccess(2);
        incComparisons(1);
        render();
    }

    //  rest of SubArrayTwo
    while (indexOfSubArrayTwo < subArrayTwo) {
        tempArray[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        subArrayTwoPtr++;
        indexOfMergedArray++;
        incArrayAccess(2);
        incComparisons(1);
        render();
    }

    // place changes .. 
    subArrayTwoPtr = midPtr = endElement + 1;
    subArrayOnePtr = left;
    indexOfMergedArray = 0;
    while (subArrayOnePtr <= right) {
        m_arr[subArrayOnePtr] = tempArray[indexOfMergedArray++];
        incArrayAccess(2);
        incComparisons(1);
        render();
        subArrayOnePtr++;
    }
}


