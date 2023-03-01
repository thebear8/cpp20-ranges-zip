# A C++20 zip_view for two ranges, similar to C++23 std::ranges zip_view
Since there is still very little compiler support for std::ranges::zip_view, I built this replacement. It currently only handles two ranges.

## Example
```c++
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

#include "zip_view.hpp"

int main()
{
    std::vector<int> v1({ 1, 2, 3, 4 });
    std::vector<std::string> v2({ "a", "b", "c", "d" });

    for (auto&& [a, b] : zip_view(std::views::all(v1), std::views::all(v2)))
        std::cout << a << " : " << b << "\n";
}
```

## Disclaimer
This code may not be 100% const correct. While I think it should be reasonably correct, I am by no means an expert on this topic.