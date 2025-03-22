#ifndef SORTING_HPP
#define SORTING_HPP

namespace sorting
{

    // Bubble Sort
    template<typename TContainer>
    void bubbleSort(TContainer& container);

    // Selection Sort
    template<typename TContainer>
    void selectionSort(TContainer& container);

    // Insertion Sort
    template<typename TContainer>
    void insertionSort(TContainer& container);

    // Merge Sort
    template<typename TContainer>
    void mergeSort(TContainer& container);

    // Quick Sort
    template<typename TContainer>
    void quickSort(TContainer& container);

    // Heap Sort
    template<typename TContainer>
    void heapSort(TContainer& container);

    // Shell Sort
    template<typename TContainer>
    void shellSort(TContainer& container);

} // namespace sorting

#endif // SORTING_HPP
