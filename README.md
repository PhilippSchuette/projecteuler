# Project Euler

[![Build Status](https://travis-ci.org/PhilippSchuette/projecteuler.svg?branch=master)](https://travis-ci.org/PhilippSchuette/projecteuler) [![codecov](https://codecov.io/gh/PhilippSchuette/projecteuler/branch/master/graph/badge.svg)](https://codecov.io/gh/PhilippSchuette/projecteuler) [![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/dwyl/esta/issues)

## Overview

**The code in this repository is a potential spoiler and you should NOT read NOR run it if you want to solve the problems yourself.**

Project Euler problem solutions, written in multiple programming languages. For more information, check [their website](https://projecteuler.net/). Contributions are appreciated!

### Python

Tests are implemented using the [unittest module](https://docs.python.org/3/library/unittest.html).Run tests with:

```bash
cd py_src
python3 test.py
```

### C

### C++

Tested with g++8. Build using

```bash
cmake . && make
```

and run with

```bash
./problem<number>.out
```

### Go

If you want to run the problem solutions in this repository, you need to install Go from [here](https://golang.org/). After you confirmed that your Go installation works (you need to set up a workspace and set your `$GOPATH` accordingly, see [here](https://golang.org/doc/code.html)), you can `$go get` all solutions as follows:

```bash
go get github.com/DanielSchuette/geulerproject
```

If this does not work for you, you can clone this repository and manually put all files into a folder in your Go workspace:

```bash
GOPATH/src/github.com/DanielSchuette/geulerproject/<all_files_are_here>
```

Now, confirm that all tests run successfully and print the % of code that is covered by unit tests:

```bash
go test -v -cover .
```

You can then run individual examples, too:

```bash
go run main/<problemXX.go>
```

### JavaScript


## Project Status

The following table summarizes the current project status. The `test coverage` tab indicates whether there are unit tests across programming languages (`yes`, `partially`, `no`). The speed of the fastest solution per problem is shown as well (all test were run on a ThinkPad T440 with an Intel i5-4300U CPU).

| Problem | No. of Solutions | Test Coverage |    Python | C |       C++ | JS |    Go |
| ------- | ---------------- | ------------- | --------- |---| --------- | -- | ----- |
|       1 |                3 |           yes | + (0.00s) | - |      -    |  - | + (s) |
|       2 |                3 |           yes | + (0.00s) | - |      -    |  - | + (s) |
|       3 |                2 |           yes | + (33.0s) | - |      -    |  - | + (s) |
|       4 |                2 |           yes | + (0.09s) | - |      -    |  - | + (s) |
|       5 |                3 |           yes | + (0.00s) | - |      -    |  - | + (s) |
|       6 |                2 |           yes | + (0.00s) | - |      -    |  - | + (s) |
|       7 |                2 |           yes | + (56.0s) | - |      -    |  - | + (s) |
|       8 |                3 |           yes | + (0.00s) | - |      -    |  - | + (s) |
|       9 |                - |           yes | + (0.60s) | - |      -    |  - | + (s) |
|      10 |                2 |     partially |    -      | - | + (0.66s) |  - | + (s) |
|      11 |                - |             - |    -      | - |      -    |  - |    -  |
|      12 |                - |             - |    -      | - |      -    |  - |    -  |
|      13 |                - |           yes |    TBD    | - |      -    |  - |    -  |
|      14 |                - |             - |    -      | - |      -    |  - |    -  |
|      15 |                - |             - |    -      | - |      -    |  - |    -  |
|      16 |                - |           yes |    TBD    | - |      -    |  - |    -  |
|      17 |                - |             - |    -      | - |      -    |  - |    -  |
|      18 |                - |             - |    -      | - |      -    |  - |    -  |
|      19 |                - |             - |    -      | - |      -    |  - |    -  |
|      20 |                - |             - |    -      | - |      -    |  - |    -  |


## Programming Languages

Solutions are mainly implemented in [Python3](https://www.python.org/). For the future, solutions in [Go](https://golang.org/), [JavaScript](https://www.javascript.com/), C and C++ will be added. Whenever possible, unit tests are implemented, too. Please consider contributing!

## License

The code in this repository is MIT-licensed (see [here](./LICENSE.md) for more information).
