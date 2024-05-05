#include <iostream>
#include <chrono>
#include <vector>
#include <unistd.h>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

int main(int argc, char *argv[])
{
    double meanMerge = 0;
    double meanBubble = 0;

    for(unsigned int i = 1; i < argc; i++)
    {
        // prendo la dimensione del vettore, che do in input, e creo 2 vettori
        int dim = stoi(argv[i]);
        vector<double> vecMerge(dim);
        vector<double> vecBubble(dim);

        srand(time(NULL));

        // genero gli elementi dei vettori randomicamente tra 0 e 1000
        for (unsigned int i = 0; i < dim; i++)
        {
            vecMerge[i] = rand()%1000;
            vecBubble[i] = rand()%1000;
        }

        // richiamo sorting e cronometro la durata
        std::chrono::steady_clock::time_point mergeBegin = std::chrono::steady_clock::now();
        MergeSort(vecMerge);
        std::chrono::steady_clock::time_point mergeEnd = std::chrono::steady_clock::now();
        double mergeDuration = std::chrono::duration_cast<std::chrono::microseconds> (mergeEnd-mergeBegin).count();

        std::chrono::steady_clock::time_point bubbleBegin = std::chrono::steady_clock::now();
        BubbleSort(vecBubble);
        std::chrono::steady_clock::time_point bubbleEnd = std::chrono::steady_clock::now();
        double bubbleDuration = std::chrono::duration_cast<std::chrono::microseconds> (bubbleEnd-bubbleBegin).count();

        meanMerge += mergeDuration;
        meanBubble += bubbleDuration;

        cout << "Size of vector: " << dim << endl;
        cout << "Merge sort duration: " << mergeDuration << " microseconds" << endl;
        cout << "Bubble sort duration: " << bubbleDuration << " microseconds" << endl;
        cout << endl;

    }

    meanMerge = meanMerge/(argc - 1);
    meanBubble = meanBubble/(argc - 1);

    cout << "Average time of Merge sort: " << meanMerge << " microseconds" << endl;
    cout << "Average time of Bubble sort: " << meanBubble << " microseconds" << endl;

    // per vettori di dimensioni minori, il metodo Merge ha durata maggiore di Bubble
    // mentre per vettori di dimensioni maggiori al contrario
    // la media di Merge è in generale più bassa di Bubble

    return 0;
}

