# algorithms

[![Build Status](https://travis-ci.org/dgkimura/algorithms.svg?branch=master)](https://travis-ci.org/dgkimura/algorithms)

The algorithms project contains the implementations of a collection of well
known algorithms.


### Build
You will need a C compiler. You can then use CMake to generate MakeFiles for
this project.
```
$ mkdir build && cd build
$ cmake ..
$ make && ./unittests/all_unittests
```

### Contents
- Kadane's algorithm
- Knuth-Morris-Pratt algorithm
- Manacher's algorithm
