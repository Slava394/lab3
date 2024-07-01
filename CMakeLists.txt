cmake_minimum_required(VERSION 3.27)
project(lab3)

set(CMAKE_CXX_STANDARD 23)

find_path(READLINE_INCLUDE_DIR readline/readline.h)
find_library(READLINE_LIBRARY NAMES readline)

include_directories(${READLINE_INCLUDE_DIR})

if(NOT READLINE_INCLUDE_DIR OR NOT READLINE_LIBRARY)
    message(FATAL_ERROR "Readline library not found")
endif()

add_executable(
        lab3
        main.cpp

        sequence_lab2/BaseCollection.h
        sequence_lab2/DynamicArray.h
        sequence_lab2/LinkedList.h
        sequence_lab2/Sequence.h
        sequence_lab2/ArraySequence.h
        sequence_lab2/ListSequence.h

        auxiliary_types/Complex.h
        auxiliary_types/Person.h
        auxiliary_types/Person.cpp

        smart_pointer/UniquePointer.h
        smart_pointer/SharedPointer.h

        abstract_data_type/SparseMatrix.h
        abstract_data_type/SegmentedDeque.h

        test/lab2/ImmutableArraySequenceTest.h
        test/lab2/ImmutableArraySequenceTest.cpp
        test/lab2/ImmutableListSequenceTest.h
        test/lab2/ImmutableListSequenceTest.cpp
        test/lab2/MutableArraySequenceTest.h
        test/lab2/MutableArraySequenceTest.cpp
        test/lab2/MutableListSequenceTest.h
        test/lab2/MutableListSequenceTest.cpp

        test/lab3/SmartPointerTest.h
        test/lab3/SmartPointerTest.cpp
        test/lab3/ComplexTest.h
        test/lab3/ComplexTest.cpp
        test/lab3/SparseMatrixTest.h
        test/lab3/SparseMatrixTest.cpp
        test/lab3/SegmentedDequeTest.h
        test/lab3/SegmentedDequeTest.cpp

        cli/CLI.h
        cli/CLI.cpp
)

target_link_libraries(lab3 ${READLINE_LIBRARY})
