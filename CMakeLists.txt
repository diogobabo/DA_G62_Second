cmake_minimum_required(VERSION 3.22)
project(da_t6_g62)

set(CMAKE_CXX_STANDARD 17)

include_directories(codigo)

add_executable(da_t6_g62
        codigo/main.cpp
        codigo/graph/graph.cpp codigo/graph/graph.h
        codigo/graph/minHeap.h codigo/graph/disjointSets.h
        codigo/empresa.cpp codigo/empresa.h
        codigo/menu.cpp codigo/menu.h
        codigo/cenario1.cpp codigo/cenario2.cpp codigo/cenarios.h
        )
