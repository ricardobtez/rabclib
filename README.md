
# RABCLIB

Personal library to be used in all the projects needed. The library contains
several core functionalities to be used in various projects.

The set of features/functionalities inclided in this project are:
- Linked List

## Tools used by this project

GCC
Make
CMocka
Python3

## Compile project

To compile the project you first need to have the tools specified above installed.
Then you need to run the following commands:

### Release build

The release build type is the default build type. You need to run a single command
as follows:
```bash
make
```
or you could be explicit about the build type as follows:
```bash
make release
```

### Debug build

For the debug release, you do need to be explicit about the build type:
```bash
make debug
```

### Test build

For the test build, we use CMocka as the Unit testing framework. The software
is compiled in debug mode and tested using the CMocka executable created.

```bash
make test
```
This command will create the required executable and run the tests.
