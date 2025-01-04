#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

// Structure to hold benchmark result
struct BenchmarkResult {
    std::string stage_name;
    double duration_ms;
};

// Benchmark class
class BenchmarkTool {
public:
    BenchmarkTool(unsigned int width, unsigned int height) : window_width(width), window_height(height) {}

    void run() {
        window.create(sf::VideoMode(window_width, window_height), "2D Benchmark Tool");
        std::cout << "Starting 2D Graphics Benchmark..." << std::endl;
        
        // Run benchmark stages
        runStage("Rectangle Rendering", &BenchmarkTool::benchmarkRectangles);
        runStage("Circle Rendering", &BenchmarkTool::benchmarkCircles);
        runStage("Line Rendering", &BenchmarkTool::benchmarkLines);

        // Display results
        displayResults();
    }

private:
    sf::RenderWindow window;
    unsigned int window_width;
    unsigned int window_height;
    std::vector<BenchmarkResult> results;

    void runStage(const std::string& name, void (BenchmarkTool::*benchmarkFunc)()) {
        auto start = std::chrono::high_resolution_clock::now();
        (this->*benchmarkFunc)();
        auto end = std::chrono::high_resolution_clock::now();

        double duration = std::chrono::duration<double, std::milli>(end - start).count();
        results.push_back({name, duration});
        std::cout << name << " completed in " << duration << " ms." << std::endl;
    }

    void benchmarkRectangles() {
        for (int i = 0; i < 10000; ++i) {
            sf::RectangleShape rectangle(sf::Vector2f(50, 50));
            rectangle.setPosition(rand() % window_width, rand() % window_height);
            rectangle.setFillColor(sf::Color::Red);
            window.clear();
            window.draw(rectangle);
            window.display();
        }
    }

    void benchmarkCircles() {
        for (int i = 0; i < 10000; ++i) {
            sf::CircleShape circle(25);
            circle.setPosition(rand() % window_width, rand() % window_height);
            circle.setFillColor(sf::Color::Green);
            window.clear();
            window.draw(circle);
            window.display();
        }
    }

    void benchmarkLines() {
        for (int i = 0; i < 10000; ++i) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(rand() % window_width, rand() % window_height)),
                sf::Vertex(sf::Vector2f(rand() % window_width, rand() % window_height))
            };
            line[0].color = sf::Color::Blue;
            line[1].color = sf::Color::Blue;
            window.clear();
            window.draw(line, 2, sf::Lines);
            window.display();
        }
    }

    void displayResults() {
        std::cout << "\nBenchmark Results:" << std::endl;
        for (const auto& result : results) {
            std::cout << result.stage_name << ": " << result.duration_ms << " ms" << std::endl;
        }
    }
};

