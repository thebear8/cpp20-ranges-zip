#include <catch2/catch_all.hpp>
#include <iostream>
#include <ranges>
#include <string>
#include <type_traits>
#include <vector>

#include "zip_view.hpp"

TEST_CASE("Zipping functionality", "[zip_view]")
{
    std::vector<int> v1({ 1, 2, 3, 4 });
    std::vector<std::string> v2({ "a", "b", "c", "d" });
    std::vector<std::pair<int, std::string>> result(
        { { 1, "a" }, { 2, "b" }, { 3, "c" }, { 4, "d" } }
    );

    REQUIRE(std::ranges::equal(
        zip_view(std::views::all(v1), std::views::all(v2)),
        result,
        [&](auto a, auto b) {
        return a.first == b.first && a.second == b.second;
        }));
}

TEST_CASE(
    "begin/end non-const zip_view",
    "[const_correctness]"
    "[zip_view]"
)
{
    std::vector<int> v1({ 1, 2, 3, 4 });
    std::vector<std::string> v2({ "a", "b", "c", "d" });
    auto zip = zip_view(std::views::all(v1), std::views::all(v2));

    for (auto it = zip.begin(), end = zip.end(); it != end; ++it)
    {
        auto&& [a, b] = *it;

        REQUIRE(std::is_reference_v<decltype(a)>);
        REQUIRE(!std::is_const_v<decltype(a)>);

        REQUIRE(std::is_reference_v<decltype(b)>);
        REQUIRE(!std::is_const_v<decltype(b)>);
    }
}

TEST_CASE(
    "begin/end const zip_view",
    "[const_correctness]"
    "[zip_view]"
)
{
    std::vector<int> v1({ 1, 2, 3, 4 });
    std::vector<std::string> v2({ "a", "b", "c", "d" });
    const auto zip = zip_view(std::views::all(v1), std::views::all(v2));

    for (auto it = zip.begin(), end = zip.end(); it != end; ++it)
    {
        auto&& [a, b] = *it;

        REQUIRE(std::is_reference_v<decltype(a)>);
        REQUIRE(!std::is_const_v<decltype(a)>);

        REQUIRE(std::is_reference_v<decltype(b)>);
        REQUIRE(!std::is_const_v<decltype(b)>);
    }
}

TEST_CASE(
    "cbegin/cend non-const zip_view",
    "[const_correctness]"
    "[zip_view]"
)
{
    std::vector<int> v1({ 1, 2, 3, 4 });
    std::vector<std::string> v2({ "a", "b", "c", "d" });
    auto zip = zip_view(std::views::all(v1), std::views::all(v2));

    for (auto it = zip.cbegin(), end = zip.cend(); it != end; ++it)
    {
        auto&& [a, b] = *it;

        REQUIRE(std::is_reference_v<decltype(a)>);
        REQUIRE(std::is_const_v<decltype(a)>);

        REQUIRE(std::is_reference_v<decltype(b)>);
        REQUIRE(std::is_const_v<decltype(b)>);
    }
}

TEST_CASE(
    "cbegin/cend const zip_view",
    "[const_correctness]"
    "[zip_view]"
)
{
    std::vector<int> v1({ 1, 2, 3, 4 });
    std::vector<std::string> v2({ "a", "b", "c", "d" });
    const auto zip = zip_view(std::views::all(v1), std::views::all(v2));

    for (auto it = zip.cbegin(), end = zip.cend(); it != end; ++it)
    {
        auto&& [a, b] = *it;

        REQUIRE(std::is_reference_v<decltype(a)>);
        REQUIRE(std::is_const_v<decltype(a)>);

        REQUIRE(std::is_reference_v<decltype(b)>);
        REQUIRE(std::is_const_v<decltype(b)>);
    }
}