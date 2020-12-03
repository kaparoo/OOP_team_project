#include "display.h"

void displayClear() {
    try {
        if(system("clear") != 0) throw -1;
    } catch(int e) {
        system("cls");
    }
}

void displayPromptInBox(const vector<string>& prompt, const int& padding = 2) {
    int max_length = 0;
    for(const string& line : prompt)
        max_length = (max_length > line.length()) ? max_length: line.length();
    
    string horizontal_border = "";
    for(int i = 0; i < max_length + padding*2; ++i)
        horizontal_border += "─";
    
    cout << "┌" << horizontal_border << "┐" << endl;
    for(int i = 0; i < padding; ++i)
        cout << "│" << setw(max_length + padding*2) << " " << "│" << endl;
    for(const string& line : prompt) {
        cout << "│" << setw(padding) << " ";
        cout << left << setw(max_length) << line;
        cout << setw(padding) << " " << "│" << endl;
    }
    for(int i = 0; i < padding; ++i)
        cout << "│" << setw(max_length + padding*2) << " " << "│" << endl;
    cout << "└" << horizontal_border << "┘" << endl;
}

int main() {
    vector<string> prompt = {"Hello", "World", "I\'m", "kaparoo!"};
    displayPromptInBox(prompt);
}
