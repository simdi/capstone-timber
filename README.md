# Timber game written with c++ and SFML(Simple Fast Media Library).
This is a timber game. The code for this repo was inspired by a game instructor [John Horton].

---

## Prerequisites
* cmake >= 3.X
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SFML >= 2.0
  * All installation instructions can be found [here](https://www.sfml-dev.org/download/sfml/2.5.1/)
  * Windows
    * [SFML 2.5.1 - GCC 7.3.0 MinGW (DW2) 32-bit (for Windows)](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip)
  * MacOS
    * [SFML 2.5.1 - Clang 64-bit](https://www.sfml-dev.org/files/SFML-2.5.1-macOS-clang.tar.gz)
    * Command Line Tools / XCode (type "xcode-select --install" in terminal to trigger the installer)
    * [Homebrew](https://brew.sh/) (for makeicns, or to optionally install SFML)
  * Linus
    * Get SFML 2.5.1 from your distro if it has it, or compile from source
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

---

## SFML Installation

### Windows

1. Download & Extract SFML to **C:/SFML-2.5.1/** where the bin/lib/include folders are contained within
2. Download & Extract MinGW to **C:/mingw32/** where the bin/lib/include folders are contained within

### MacOS

1. Install "Command Line Tools" in MacOS if they're not already installed (type "xcode-select --install" in terminal)
2. Follow the "Installing SFML" directions here: https://www.sfml-dev.org/tutorials/2.5/start-osx.php#installing-sfml

### Linux
1. Ensure the GCC Toolchain is installed (**sudo apt install build-essential**)
2. Run **sudo apt install libsfml-dev**. The SFML version you got will vary depending on the distro. 2.5.1 is included in [Ubuntu 19.04 Disco Dingo](http://cdimage.ubuntu.com/daily-live/current/HEADER.html) for example.


## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./capstone-timber`.

---

## Folder structure

```
+ cmake/
  + Modules/
    + FindSFML.cmake
+ fonts/
  + KOMIKAP_ttf
+ graphics/
  + axe.png
  + background-1280-720.png
  + background.png
  + bee.png
  + branch.png
  + cloud.png
  + log.png
  + player.png
  + rip.png
  + tree.png
  + tree2.png
+ sound/
  + chop.wav
  + death.wav
  + out_of_time.wav
+ src/
  + include/
    + axe.h
    + bee.h
    + branches.h
    + cloud.h
    + entity.h
    + game.h
    + main.h
    + player.h
    + rip.h
    + tree.h
  + axe.cpp
  + bee.cpp
  + branches.cpp
  + cloud.cpp
  + game.cpp
  + main.cpp
  + player.cpp
  + rip.cpp
  + tree.cpp

```

