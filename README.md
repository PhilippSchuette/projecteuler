# Project Euler Solutions

[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/dwyl/esta/issues) [![Build Status](https://travis-ci.org/PhilippSchuette/projecteuler.svg?branch=master)](https://travis-ci.org/PhilippSchuette/projecteuler) [![codecov](https://codecov.io/gh/PhilippSchuette/projecteuler/branch/master/graph/badge.svg)](https://codecov.io/gh/PhilippSchuette/projecteuler) ![open issues](https://img.shields.io/github/issues/PhilippSchuette/projecteuler.svg?style=flat)

[![Gitter chat](https://badges.gitter.im/gitterHQ/gitter.png)](https://gitter.im/projecteuler-all-languages/community)

![language js](https://img.shields.io/badge/Language-JS-blue.svg) ![language c](https://img.shields.io/badge/Language-C-blue.svg) ![language c++](https://img.shields.io/badge/Language-C++-blue.svg) ![language go](https://img.shields.io/badge/Language-Go-blue.svg) ![language python](https://img.shields.io/badge/Language-Python-blue.svg) ![language rust](https://img.shields.io/badge/Language-Rust-blue.svg)

## <a name="overview"></a> Overview

**The code in this repository is a potential spoiler and you should NOT read NOR run it if you want to solve the problems yourself.**

Project Euler problem solutions, written in multiple programming languages. For more information, check [their website](https://projecteuler.net/). Contributions are appreciated!

## <a name="toc"></a> Table of Contents

1. [Overview](#overview)

2. [Programming Languages](#langs)

    - [Python](#python)
    - [C](#c)
    - [C++](#cpp)
    - [Go](#go)
    - [JavaScript](#js)
    - [Rust](#rust)

3. [Project Status](#project-status)

4. [Adding Solutions](#adding-solutions)

5. [License](#license)

## <a name="langs"></a> Programming Languages

Solutions are mainly implemented in [Python3](https://www.python.org/). For the future, solutions in [Go](https://golang.org/), [JavaScript](https://www.javascript.com/), C and C++ will be added. Whenever possible, unit tests are implemented, too. Please consider contributing!

### <a name="python"></a> Python

Tests are implemented using the [unittest module](https://docs.python.org/3/library/unittest.html). Run tests with:

```bash
cd py_src
python3 test.py
```

### <a name="c"></a> C

To compile all solutions at once, type:

```bash
cd c_src/
make
```

To run test:
```bash
make test
```

To clean up binaries:

```bash
make clean
```

Unit tests are implemented using a custom framework (`c_src/utest`) with a basic set of assertion functions. Suggestions for improvements are welcome!

### <a name="cpp"></a> C++

Tested with `g++8`. First of all navigate to `cpp_src` and execute

```bash
cmake .
```

Afterwards you can build and run the tests with

```bash
make tests && ./tests.out
```

To build the problems use

```bash
make -j n
```

where `n` is the number of threads to use for the build.
Now run with

```bash
./problem<number>.out
```

### <a name="go"></a> Go

The `Go` code in this repository is managed in another repository [here](https://github.com/DanielSchuette/goeulerproject). You can get the code by running:

```bash
go get github.com/DanielSchuette/goeulerproject
```

Then, run individual problem solutions, all problem solutions or the test suite:

```bash
go run main/problem<number>.go
sh install.sh --cover
go test .
```

### <a name="js"></a> JavaScript

The solutions are intended to be run with `node` from the command line:

```bash
npm install
node <solution_number.js> # or:
npm run <solution_number> # no 'js' extension required
```

Unit tests are implemented using [Jest](https://jestjs.io/docs/en/getting-started.html) and can be run using:

```bash
npm run test # or:
jest # uses test.js as an entry point by default
```

### <a name="rust"></a> Rust

To build the source files, you must have the Rust compiler (`rustc`) and Rust's package manager (`cargo`) installed. Then run:
```bash
cd rust_src

# builds and runs all solutions WITHOUT compiler optimizations
# faster build but slower execution times
cargo run

# build WITH compiler optimizations (much faster execution times)
cargo build --release
./target/release/rust_src
```

To run a certain problem, it must be selected via a `,`-separated list
or two `:`-separated integers that get expanded to a range:

```bash
cargo build -- 1,2,7 # runs problems 1, 2, and 7
cargo build -- 1,4:7 # runs problems 1 and 4 through 7

# or as arguments to the binary:
./target/release/rust_src 1,2,5:7

# run unit tests
cargo test
```

## <a name="project-status"></a> Project Status

The following table summarizes the current project status. The speed of the fastest solution per problem and programming language is shown as well (all test were run on a ThinkPad T440 with an Intel i5-4300U CPU). Rust solutions were built and run with `--release` flag for compiler optimizations. *Solutions that are written in bold face and italics are still very slow and need improvement*! The unit test coverage for all solutions is monitored via `Travis` and `CodeCov`.

| Problem | Fastest Python |   Fastest C |    Fastest C++ | Fastest JS |     Fastest Go |   Fastest Rust |
| ------- | -------------- |------------ | -------------- | ---------- | -------------- | -------------- |
|       1 |    + (0.00s)   |  + (0.00s)  |    + (0.00s)   |  + (0.23s) |    + (0.00s)   |    + (0.00s)   |
|       2 |    + (0.00s)   |  + (0.00s)  |    + (0.00s)   |  + (0.17s) |    + (0.04s)   |    + (0.00s)   |
|       3 | _**+ (33.0s)**_|  + (0.01s)  |         -      |     -      |    + (0.83s)   |    + (0.84s)   |
|       4 |    + (0.09s)   |    -        |    + (0.01s)   |     -      |    + (0.07s)   |    + (0.16s)   |
|       5 |    + (0.00s)   |    -        |    + (0.07s)   |     -      | _**+ (6.74s)**_|    + (0.16s)   |
|       6 |    + (0.00s)   |    -        |    + (0.00s)   |     -      |    + (0.00s)   |    + (0.00s)   |
|       7 |    + (0.29s)   |    -        |    + (0.028s)  |     -      | _**+ (5.14s)**_|    + (0.021s)  |
|       8 |    + (0.00s)   |    -        |         -      |     -      |    + (0.00s)   |    + (0.00s)   |
|       9 |    + (0.60s)   |    -        |    + (0.01s)   |     -      |    + (0.00s)   |    + (0.01s)   |
|      10 | _**+ (19.9s)**_|    -        |    + (0.66s)   |     -      | _**+ (2.04s)**_|    + (0.98s)   |
|      11 |    + (0.00)    |    -        |         -      |     -      |        -       |    + (0.00s)   |
|      12 |       -        |    -        |        TBD     |     -      |        -       | _**+ (1.45s)**_|
|      13 |    + (0.00s)   |    -        |         -      |     -      |        -       |    + (0.00s)   |
|      14 |       -        |    -        |    + (0.25s)   |     -      |        -       |    + (0.27s)   |
|      15 |       -        |    -        |         -      |     -      |        -       |    + (0.00s)   |
|      16 |    + (0.00s)   |    -        |         -      |     -      |        -       |    + (0.00s)   |
|      17 |       -        |    -        |         -      |     -      |        -       |    + (0.01s)   |
|      18 |       -        |    -        |        TBD     |     -      |        -       |    + (0.00s)   |
|      19 |    + (0.00s)   |    -        |    + (0.00s)   |     -      |        -       |        -       |
|      20 |       -        |    -        |         -      |     -      |        -       |        -       |
|      21 |       -        |    -        |         -      |     -      |        -       |        -       |
|      22 |    + (0.02s)   |    -        |         -      |     -      |        -       |        -       |
|      23 |       -        |    -        |         -      |     -      |        -       |        -       |
|      24 |       -        |    -        |         -      |     -      |        -       |        -       |
|      25 |    + (0.03s)   |    -        |         -      |     -      |        -       |        -       |
|      26 |       -        |    -        |         -      |     -      |        -       |        -       |
|      27 |       -        |    -        |         -      |     -      |        -       |        -       |
|      28 |       -        |    -        |         -      |     -      |        -       |        -       |
|      29 |       -        |    -        |         -      |     -      |        -       |        -       |
|      30 |       -        |    -        |         -      |     -      |        -       |        -       |
|      31 |       -        |    -        |         -      |     -      |        -       |        -       |
|      32 |       -        |    -        |         -      |     -      |        -       |        -       |
|      33 |       -        |    -        |         -      |     -      |        -       |        -       |
|      34 |       -        |    -        |         -      |     -      |        -       |        -       |
|      35 |       -        |    -        |         -      |     -      |        -       |        -       |
|      36 |       -        |    -        |         -      |     -      |        -       |        -       |
|      37 |       -        |    -        |         -      |     -      |        -       |        -       |
|      38 |       -        |    -        |         -      |     -      |        -       |        -       |
|      39 |       -        |    -        |         -      |     -      |        -       |        -       |
|      40 |       -        |    -        |         -      |     -      |        -       |        -       |
|      41 |       -        |    -        |         -      |     -      |        -       |        -       |
|      42 |       -        |    -        |         -      |     -      |        -       |        -       |
|      43 |       -        |    -        |         -      |     -      |        -       |        -       |
|      44 |       -        |    -        |         -      |     -      |        -       |        -       |
|      45 |       -        |    -        |         -      |     -      |        -       |        -       |
|      46 |       -        |    -        |         -      |     -      |        -       |        -       |
|      47 |       -        |    -        |         -      |     -      |        -       |        -       |
|      48 |       -        |    -        |         -      |     -      |        -       |        -       |
|      49 |       -        |    -        |         -      |     -      |        -       |        -       |
|      50 |       -        |    -        |         -      |     -      |        -       |        -       |
|      51 |       -        |    -        |         -      |     -      |        -       |        -       |
|      52 |       -        |    -        |         -      |     -      |        -       |        -       |
|      53 |       -        |    -        |         -      |     -      |        -       |        -       |
|      54 |       -        |    -        |         -      |     -      |        -       |        -       |
|      55 |       -        |    -        |         -      |     -      |        -       |        -       |
|      56 |       -        |    -        |         -      |     -      |        -       |        -       |
|      57 |       -        |    -        |         -      |     -      |        -       |        -       |
|      58 |       -        |    -        |         -      |     -      |        -       |        -       |
|      59 |       -        |    -        |         -      |     -      |        -       |        -       |
|      60 |       -        |    -        |         -      |     -      |        -       |        -       |
|      61 |       -        |    -        |         -      |     -      |        -       |        -       |
|      62 |       -        |    -        |         -      |     -      |        -       |        -       |
|      63 |       -        |    -        |         -      |     -      |        -       |        -       |
|      64 |       -        |    -        |         -      |     -      |        -       |        -       |
|      65 |       -        |    -        |         -      |     -      |        -       |        -       |
|      66 |       -        |    -        |         -      |     -      |        -       |        -       |
|      67 |       -        |    -        |       TBD      |     -      |    + (0.00s)   |        -       |
|      68 |       -        |    -        |         -      |     -      |        -       |        -       |
|      69 |       -        |    -        |         -      |     -      |        -       |        -       |

## <a name="adding-solutions"></a> Adding Solutions

You can use the script `gen_new_probl.sh` to quickly generate a template for your problem solution. Problem number, author name and date will be automatically filled in. **Javascript, Go and Rust are not yet fully supported**, i.e. source files are created from templates but need to be modified to a certain amount.

E.g. to generate a template for your C++ solution to problem 123 use

```bash
./gen_new_problem.sh -l cpp -n 123
```

## <a name="license"></a> License

The code in this repository is MIT-licensed (see [LICENSE.md](./LICENSE.md) for more information).
