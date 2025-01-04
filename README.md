# Computational Mathematics


## Brief description
This repository aimed to creating programming implementation of various methods of Computational Mathematics

## Detailed description
Repository has several directories with solutions for certain theme. These directories are:

* ### SLAE
  SLAE - System of Linear Algebraic Equations. This directory contains methods of exact and numeric solving of SLAE. There are:
  * Gauss method (C++, Python)
  * ...




## Interaction with the solutions
You can use these solutions in several ways:
1. Just copy the source code of needed methods.
2. Clone the whole repo to your computer:
    ```bash
      git clone https://github.com/MatheMateCS/Computational-Mathematics
    ```
   * If you use Python solutions, just create main.py in root directory of repo and then write appropriate imports in it, such as:
    ```python
   from SLAE.gauss import *
    
    gauss()
    ```
   * If you use C++ solutions, create main.cpp in root directory, include in it appropriate headers from directories:
   
   ```C++
   #include "SLAE/slae.h"
   
   int main() {
       gauss();
   }
   ``` 
   And then build the project with cmake builder, for example create CMakeLists.txt:
   
   ```cmake
    cmake_minimum_required(VERSION 3.29)
    project(Computational-Mathematics)
    
    set(CMAKE_CXX_STANDARD 14)
    
    add_executable(Computational-Mathematics
        SLAE/slae.h
        SLAE/gauss.cpp
        main.cpp
    )
    ```