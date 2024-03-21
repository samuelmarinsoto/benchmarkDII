#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
using namespace chrono;

// Function prototypes
long long maxElement(const vector<int>& arr);
long long quadraticSearch(const vector<int>& arr, int target);
long long linearLogarithmicSearch(const vector<int>& arr, int target);
long long logarithmicSearch(const vector<int>& arr, int target);
long long exponentialSearch(const vector<int>& arr, int target);

int main() {
    ofstream outputFile;
    
    // Open output files for each complexity tier
    outputFile.open("max_element.csv");
    outputFile << "ArraySize,TimeTaken(ns)\n";
    outputFile.close();
    
    outputFile.open("quadratic.csv");
    outputFile << "ArraySize,TimeTaken(ns)\n";
    outputFile.close();
    
    outputFile.open("linear_logarithmic.csv");
    outputFile << "ArraySize,TimeTaken(ns)\n";
    outputFile.close();
    
    outputFile.open("logarithmic.csv");
    outputFile << "ArraySize,TimeTaken(ns)\n";
    outputFile.close();
    
    outputFile.open("exponential.csv");
    outputFile << "ArraySize,TimeTaken(ns)\n";
    outputFile.close();

    // Array sizes to test
    vector<int> arraySizes = {10, 100, 1000, 10000, 100000, 1000000, 10000000};

    for (int size : arraySizes) {
        // Generate random array
        vector<int> arr(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000000);
        generate(arr.begin(), arr.end(), [&]() { return dis(gen); });

        // Benchmark each algorithm and write results to respective CSV files
        auto start = high_resolution_clock::now();
        long long result = maxElement(arr);
        auto stop = high_resolution_clock::now();
        outputFile.open("max_element.csv", ios::app);
        outputFile << size << "," << duration_cast<nanoseconds>(stop - start).count() << endl;
        outputFile.close();

        int target = arr.back(); // Choose last element as target

        start = high_resolution_clock::now();
        result = quadraticSearch(arr, target);
        stop = high_resolution_clock::now();
        outputFile.open("quadratic.csv", ios::app);
        outputFile << size << "," << duration_cast<nanoseconds>(stop - start).count() << endl;
        outputFile.close();

        start = high_resolution_clock::now();
        result = linearLogarithmicSearch(arr, target);
        stop = high_resolution_clock::now();
        outputFile.open("linear_logarithmic.csv", ios::app);
        outputFile << size << "," << duration_cast<nanoseconds>(stop - start).count() << endl;
        outputFile.close();

        start = high_resolution_clock::now();
        result = logarithmicSearch(arr, target);
        stop = high_resolution_clock::now();
        outputFile.open("logarithmic.csv", ios::app);
        outputFile << size << "," << duration_cast<nanoseconds>(stop - start).count() << endl;
        outputFile.close();

        start = high_resolution_clock::now();
        result = exponentialSearch(arr, target);
        stop = high_resolution_clock::now();
        outputFile.open("exponential.csv", ios::app);
        outputFile << size << "," << duration_cast<nanoseconds>(stop - start).count() << endl;
        outputFile.close();
    }

    cout << "Benchmarking completed. Results saved in CSV files." << endl;

    return 0;
}

// Max element search (O(n))
long long maxElement(const vector<int>& arr) {
    auto start = high_resolution_clock::now();
    int maxValue = *max_element(arr.begin(), arr.end());
    auto stop = high_resolution_clock::now();
    return duration_cast<nanoseconds>(stop - start).count();
}

// Quadratic search (O(n^2))
long long quadraticSearch(const vector<int>& arr, int target) {
    auto start = high_resolution_clock::now();
    for (int num1 : arr) {
        for (int num2 : arr) {
            if (num1 == num2 && num1 == target) {
                break;
            }
        }
    }
    auto stop = high_resolution_clock::now();
    return duration_cast<nanoseconds>(stop - start).count();
}

// Linear-logarithmic search (O(nlogn))
long long linearLogarithmicSearch(const vector<int>& arr, int target) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    auto start = high_resolution_clock::now();
    if (binary_search(sortedArr.begin(), sortedArr.end(), target)) {
        auto stop = high_resolution_clock::now();
        return duration_cast<nanoseconds>(stop - start).count();
    }
    return -1;
}

// Logarithmic search (O(logn))
long long logarithmicSearch(const vector<int>& arr, int target) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    auto start = high_resolution_clock::now();
    if (binary_search(sortedArr.begin(), sortedArr.end(), target)) {
        auto stop = high_resolution_clock::now();
        return duration_cast<nanoseconds>(stop - start).count();
    }
    return -1;
}

// Exponential search (O(k^n))
long long exponentialSearch(const vector<int>& arr, int target) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            auto stop = high_resolution_clock::now();
            return duration_cast<nanoseconds>(stop - start).count();
        }
    }
    return -1;
}
