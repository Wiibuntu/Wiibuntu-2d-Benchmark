#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <numeric>

using namespace std;
using namespace std::chrono;

// Scoring system
int score = 0;

// Benchmark for Sorting Algorithms
void sortingBenchmark() {
    vector<int> data(100000);
    iota(data.begin(), data.end(), 1);
    shuffle(data.begin(), data.end(), mt19937(random_device()()));

    auto start = high_resolution_clock::now();
    sort(data.begin(), data.end());
    auto stop = high_resolution_clock::now();

    int duration = duration_cast<milliseconds>(stop - start).count();
    cout << "Sorting Benchmark: " << duration << " ms" << endl;
    score += max(1000 - duration, 0);
}

// Benchmark for Matrix Multiplication
void matrixMultiplicationBenchmark() {
    const int N = 300;
    vector<vector<double>> A(N, vector<double>(N, 1.0));
    vector<vector<double>> B(N, vector<double>(N, 2.0));
    vector<vector<double>> C(N, vector<double>(N, 0.0));

    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    auto stop = high_resolution_clock::now();

    int duration = duration_cast<milliseconds>(stop - start).count();
    cout << "Matrix Multiplication Benchmark: " << duration << " ms" << endl;
    score += max(2000 - duration, 0);
}

// Benchmark for Trigonometric Calculations
void trigonometricBenchmark() {
    vector<double> angles(1000000);
    iota(angles.begin(), angles.end(), 0.0);

    auto start = high_resolution_clock::now();
    for (auto &angle : angles) {
        angle = sin(angle) + cos(angle) + tan(angle);
    }
    auto stop = high_resolution_clock::now();

    int duration = duration_cast<milliseconds>(stop - start).count();
    cout << "Trigonometric Benchmark: " << duration << " ms" << endl;
    score += max(1500 - duration, 0);
}

// Benchmark for Random Number Generation
void randomNumberBenchmark() {
    vector<int> numbers(1000000);
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(1, 1000000);

    auto start = high_resolution_clock::now();
    for (auto &num : numbers) {
        num = dist(rng);
    }
    auto stop = high_resolution_clock::now();

    int duration = duration_cast<milliseconds>(stop - start).count();
    cout << "Random Number Generation Benchmark: " << duration << " ms" << endl;
    score += max(1200 - duration, 0);
}

// Benchmark for Prime Number Generation
void primeNumberBenchmark() {
    const int LIMIT = 1000000;
    vector<bool> isPrime(LIMIT + 1, true);
    isPrime[0] = isPrime[1] = false;

    auto start = high_resolution_clock::now();
    for (int p = 2; p * p <= LIMIT; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= LIMIT; i += p) {
                isPrime[i] = false;
            }
        }
    }
    auto stop = high_resolution_clock::now();

    int duration = duration_cast<milliseconds>(stop - start).count();
    cout << "Prime Number Generation Benchmark: " << duration << " ms" << endl;
    score += max(1800 - duration, 0);
}

int main() {
    cout << "Starting 2D Benchmark Program..." << endl;
    sortingBenchmark();
    matrixMultiplicationBenchmark();
    trigonometricBenchmark();
    randomNumberBenchmark();
    primeNumberBenchmark();

    cout << "Benchmarking Complete." << endl;
    cout << "Final Score: " << score << endl;
    return 0;
}
