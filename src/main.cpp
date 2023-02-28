#include <iostream>
#include <string>
#include <vector>

#include "zip_view.hpp"

int main()
{
    std::vector<int> v1({ 1, 2, 3, 4 });
    std::vector<std::string> v2({ "a", "b", "c", "d" });

    for (auto&& [a, b] : zip_view(v1, v2))
        std::cout << a << " : " << b << "\n";
}