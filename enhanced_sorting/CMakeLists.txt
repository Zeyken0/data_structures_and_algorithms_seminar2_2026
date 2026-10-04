# Статическая библиотека со всеми улучшенными сортировками
add_library(enhanced_sorting STATIC
    src/binary_insertion_sort.cpp
    src/shaker_sort.cpp
)

# PUBLIC — заголовки видны и самой библиотеке, и всем, кто к ней линкуется
target_include_directories(enhanced_sorting PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Предупреждения компилятора
target_compile_options(enhanced_sorting PRIVATE
    -Wall -Wextra -Wpedantic
)
