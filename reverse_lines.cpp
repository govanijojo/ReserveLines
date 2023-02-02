#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct Line
{
    Line* prev;
    string line;
};

int main()
{
    Line* last = nullptr;

    // Чтение строк.
    for (string line; getline(cin, line);)
    {
        Line* new_line = new Line;
        new_line->prev = last;
        new_line->line = line;
        last = new_line;
    }

    // Вывод строк в обратном порядке.
    while (last)
    {
        cout << last->line << '\n';
        Line* old_line = last;
        last = last->prev;
        delete old_line;
    }

    return EXIT_SUCCESS;
}