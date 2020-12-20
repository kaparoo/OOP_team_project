#include "display.h"

#include <iostream>
#include <iomanip>

/*
#include <windows.h>

// for Windows
void displayClear() {
    system("cls");
}
*/

// for UNIX
void displayClear() {
    std::system("clear");
}

void displayPromptInBox(const std::vector<std::string>& prompt, const unsigned int& padding) {
    unsigned long max_length = prompt[0].length();
    for (const auto& line : prompt) {
        const unsigned long& _length = line.length();
        if (max_length < _length) max_length = _length;
    }

    const unsigned long& _width = max_length + padding * 2;

    std::string horizontal_border = "";
    for (unsigned int i = 0; i < _width; ++i)
        horizontal_border += "─";

    std::cout << "┌" << horizontal_border << "┐" << std::endl;

    for (int i = 0; i < padding; ++i)
        std::cout << "│" << std::setw(_width) << " " << "│" << std::endl; // up padding

    for (const std::string& line : prompt) {
        std::cout << "│" << std::setw(padding) << " "; // left padding
        std::cout << std::left << std::setw(max_length) << line; // content
        std::cout << std::setw(padding) << " " << "│" << std::endl; // right padding
    }

    for (int i = 0; i < padding; ++i)
        std::cout << "│" << std::setw(_width) << " " << "│" << std::endl; // bottom padding

    std::cout << "└" << horizontal_border << "┘" << std::endl;
}