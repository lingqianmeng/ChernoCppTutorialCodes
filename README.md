# ChernoCppTutorialCodes

This repository contains C++ examples inspired by **The Cherno's C++ series**, organized by topic for easy navigation and learning. Each folder under `src` represents a concept withThis repository contains C++ examples inspired by **The Cherno's C++ series**, organized by topic for easy navigation and learning. Each folder under `src` represents a concept with a minimal, runnable example.

---
Each folder contains:
- `main.cpp` → runnable example
- Optional helper files for the concept

---

## 🔧 Prerequisites

- **C++ Compiler**:
  - Windows: MSVC (Visual Studio 2022 or Build Tools)
  - macOS: Apple Clang
  - Linux: GCC ≥ 11 or Clang ≥ 13
- **CMake** ≥ 3.16 (recommended for multi-project builds)

---

## 🚀 How to Build & Run

### ✅ Option 1: Compile a single example manually
Navigate to the topic folder and compile:

```bash
cd src/Basics
g++ main.cpp -o basics
./basics
```
On Windows (MSVC):
```bash
cd src\Basicscd
cl main.cpp
```

### ✅ Option 2: Build all examples with CMake
Create a top-level CMakeLists.txt like this:
```bash
make_minimum_required(VERSION 3.16)
project(ChernoCppTutorialCodes)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src/Basics)
add_subdirectory(src/ControlFlow)
add_subdirectory(src/Functions)
add_subdirectory(src/Templates)
add_subdirectory(src/Arrays)
add_subdirectory(src/Stringsadd_subdirectory(src/Strings)
add_subdirectory(src/Pointers)
```
Then in each topic folder, add a minimal CMakeLists.txt:
```bash
add_executable(Basics main.cpp)
```
Build everything:
```bash
cmake -S . -B build
cmake --build build
```
Run an example:
```bash
./build/src/Basics/Basics
```
## 🧩 Topics Covered

- Basics: variables, types, I/O
- Control flow: if/switch, loops
- Functions: overloading, templates
- Arrays & pointers
- Strings and operations
- Object-Oriented Programming
- Templates and generic programming


## 📄 License
MIT License – see LICENSE.

## 🙌 Acknowledgments
Inspired by The Cherno C++ tutorial series.
