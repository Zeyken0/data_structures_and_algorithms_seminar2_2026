#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "binary_insertion_sort.h"
#include <vector>

TEST_CASE("BinaryInsertionSort: пустой массив", "[binary_insertion_sort]") {
    std::vector<int> arr;
    binary_insertion_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("BinaryInsertionSort: один элемент", "[binary_insertion_sort]") {
    std::vector<int> arr = {42};
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("BinaryInsertionSort: уже отсортированный", "[binary_insertion_sort]") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("BinaryInsertionSort: обратный порядок", "[binary_insertion_sort]") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("BinaryInsertionSort: произвольный порядок", "[binary_insertion_sort]") {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("BinaryInsertionSort: много дубликатов", "[binary_insertion_sort]") {
    std::vector<int> arr = {5, 1, 5, 1, 5, 1};
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 1, 5, 5, 5});
}

TEST_CASE("BinaryInsertionSort: отрицательные числа", "[binary_insertion_sort]") {
    std::vector<int> arr = {-1, -5, -3, -2, -4};
    binary_insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{-5, -4, -3, -2, -1});
}

TEST_CASE("BinaryInsertionSort: два элемента, оба порядка", "[binary_insertion_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {1, 2};
        binary_insertion_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {2, 1};
        binary_insertion_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2});
    }
}

TEST_CASE("BinaryInsertionSort: double", "[binary_insertion_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {3.5, 1.25, 2.75, 0.5, 4.0};
        binary_insertion_sort(arr);
        REQUIRE(arr == std::vector<double>{0.5, 1.25, 2.75, 3.5, 4.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-1.5, 2.25, -3.75, 0.0, 1.5};
        binary_insertion_sort(arr);
        REQUIRE(arr == std::vector<double>{-3.75, -1.5, 0.0, 1.5, 2.25});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        binary_insertion_sort(arr);
        REQUIRE(arr.empty());
    }
}
