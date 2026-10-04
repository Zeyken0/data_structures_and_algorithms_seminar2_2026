#include <catch.hpp>
#include "shaker_sort.h"
#include <vector>

TEST_CASE("ShakerSort: пустой массив", "[shaker_sort]") {
    std::vector<int> arr;
    shaker_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("ShakerSort: один элемент", "[shaker_sort]") {
    std::vector<int> arr = {0};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{0});
}

TEST_CASE("ShakerSort: уже отсортированный", "[shaker_sort]") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("ShakerSort: обратный порядок", "[shaker_sort]") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("ShakerSort: произвольный порядок", "[shaker_sort]") {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("ShakerSort: все элементы равны", "[shaker_sort]") {
    std::vector<int> arr = {7, 7, 7, 7, 7};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{7, 7, 7, 7, 7});
}

TEST_CASE("ShakerSort: отрицательные числа", "[shaker_sort]") {
    std::vector<int> arr = {-3, 0, -1, 5, -10, 2};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{-10, -3, -1, 0, 2, 5});
}

TEST_CASE("ShakerSort: два элемента, оба порядка", "[shaker_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {1, 2};
        shaker_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {2, 1};
        shaker_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2});
    }
}

TEST_CASE("ShakerSort: double", "[shaker_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {3.5, 1.25, 2.75, 0.5, 4.0};
        shaker_sort(arr);
        REQUIRE(arr == std::vector<double>{0.5, 1.25, 2.75, 3.5, 4.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-1.5, 2.25, -3.75, 0.0, 1.5};
        shaker_sort(arr);
        REQUIRE(arr == std::vector<double>{-3.75, -1.5, 0.0, 1.5, 2.25});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        shaker_sort(arr);
        REQUIRE(arr.empty());
    }
}
