project( Neuron)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Neuron NetworkNeurons.cpp Neuron.cpp main.cpp)
add_executable(NeuronsTEST Neuron.cpp NeuronsTEST.cpp)

target_link_libraries(NeuronsTEST gtest gtest_main)
add_test(NeuronsTEST NeuronsTEST)

