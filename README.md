# Enhanced Sorting Algorithms

Реализация двух улучшенных алгоритмов сортировки на C++ с модульными тестами.

## Алгоритмы
- Binary Insertion Sort (сортировка вставками с бинарным поиском)
- Shaker Sort (сортировка шейкером)

## Стек
- C++17
- CMake 3.16+
- Catch2 v2 (vendored)
- clangd / Neovim

## Сборка
```bash
cmake -S . -B build
cmake --build build
```

## Запуск тестов
```bash
./build/tests/sorting_tests
```
