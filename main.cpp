//  Copyright 2024 Stephan Tchangov
#include <iostream>
#include <string>
#include <SFML/System.hpp>

#include "EDistance.hpp"

int main(int argc, const char* argv[]) {
    sf::Clock clock;

    std::string sequence1, sequence2;
    if (!(std::cin >> sequence1 >> sequence2)) {
        throw std::runtime_error("Error:"
                                 "Unable to read two sequences from input.");
    }

    EDistance ed(sequence1, sequence2);

    int distance = ed.optDistance();
    std::string result = ed.alignment();

    sf::Time t = clock.getElapsedTime();

    std::cout << "Edit distance = " << distance << std::endl;
    std::cout << result << std::endl;

    std::cout << "Execution time is: "
              << t.asSeconds() << "seconds" << std::endl;

    return 0;
}
