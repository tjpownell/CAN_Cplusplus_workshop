# C++ CAN Helper

In this repository I have some examples of an object oriented approach to handling CAN bus traffic.

## Description

The goal here is to give some class definitions which can be helpful when starting a new C++ codebase which needs to handle CAN network traffic with several active nodes. 
One of the big challenges of such a task is assigning a correct source address for your controller. The MessageHandler Class gives a template for handling address claim collisions.

## Getting Started

### Dependencies

* CStdLib
  * Unordered_Map
  * IOStream

# Windows 10
* MinGW32
# Linux 
* Make
* GCC

### Installing

* Feel free to clone the repository to a local folder of choice.
* For the MessageHandler Class, it may be useful to overload the CanFrame struct with a definition like the one found here: https://doc.riot-os.org/sys_2include_2can_2can_8h.html

### Executing program

* In Windows, you will have to install MinGW32 and add it to your Path
* To build, type:
```
mingw32-make.exe
```
* To run, type:
```
.\output
```
* In Linux, you will have to sudo install make and gcc
* To build, type:
```
make
```
* To run, type:
```
./output
```
## Authors

Contributors names and contact info

* Tim Pownell  
* https://github.com/tjpownell

## Acknowledgments

Inspiration for ReadMe.
* [awesome-readme](https://gist.github.com/DomPizzie/7a5ff55ffa9081f2de27c315f5018afc)
