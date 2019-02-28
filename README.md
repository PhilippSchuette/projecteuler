# Project Euler Solutions

[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/dwyl/esta/issues) [![Build Status](https://travis-ci.org/PhilippSchuette/projecteuler.svg?branch=master)](https://travis-ci.org/PhilippSchuette/projecteuler) [![codecov](https://codecov.io/gh/PhilippSchuette/projecteuler/branch/master/graph/badge.svg)](https://codecov.io/gh/PhilippSchuette/projecteuler) ![open issues](https://img.shields.io/github/issues/PhilippSchuette/projecteuler.svg?style=flat)

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
make
```

To clean up binaries:

```bash
make clean
```

Unit tests are implemented using custom framework (`c_src/test`).

### <a name="cpp"></a> C++

Tested with `g++8`. First of all navigate to `cpp_src` and execute

```bash
cmake .
```

Afterwards you can build and run the tests with

```bash
make test
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
or two `:` integers that get expanded to a range:

```bash
cargo build -- 1,2,7 # runs problems 1, 2, and 7
cargo build -- 1,4:7 # runs problems 1 and 4 through 7

# or as arguments to the binary:
./target/release/rust_src 1,2,5:7
```

Testing and CI is not yet implemented.

## <a name="project-status"></a> Project Status

The following table summarizes the current project status. The `test coverage` tab indicates whether there are unit tests across programming languages (`yes`, `partially`, `no`). The speed of the fastest solution per problem is shown as well (all test were run on a ThinkPad T440 with an Intel i5-4300U CPU). *Solutions that are written in bold face and italics are still very slow and need improvement*! The unit test coverage for all solutions is monitored via `Travis` and `CodeCov`, but **C++, Go and Rust** still need to be added to the CI pipeline.

| Problem | No. Solutions | Fastest Python |   Fastest C | Fastest C++ | Fastest JS | Fastest Go | Fastest Rust |
| ------- | ------------- | -------------- |------------ | ----------- | ---------- | ---------- | ------------ |
|       1 |             6 |    + (0.00s)   |  + (0.00s)  |       -     |  + (0.23s) |    + (s)   |   + (0.00s)  |
|       2 |             6 |    + (0.00s)   |  + (0.00s)  |       -     |  + (0.17s) |    + (s)   |   + (0.00s)  |
|       3 |             3 | _**+ (33.0s)**_|    -        |       -     |     -      |    + (s)   |   + (0.84s)  |
|       4 |             3 |    + (0.09s)   |    -        |       -     |     -      |    + (s)   |   + (0.16s)  |
|       5 |             4 |    + (0.00s)   |    -        |       -     |     -      |    + (s)   |   + (0.16s)  |
|       6 |             3 |    + (0.00s)   |    -        |       -     |     -      |    + (s)   |   + (0.00s)  |
|       7 |             3 | _**+ (56.0s)**_|    -        |       -     |     -      |    + (s)   |   + (1.36s)  |
|       8 |             3 |    + (0.00s)   |    -        |       -     |     -      |    + (s)   |   + (0.00s)  |
|       9 |             1 |    + (0.60s)   |    -        |       -     |     -      |    + (s)   |   + (0.01s)  |
|      10 |             2 | _**+ (> 60s)**_|    -        |  + (0.66s)  |     -      |    + (s)   |       -      |
|      11 |             1 |    + (0.00)    |    -        |       -     |     -      |       -    |       -      |
|      12 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      13 |             1 |    + (0.00s)   |    -        |       -     |     -      |       -    |       -      |
|      14 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      15 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      16 |             1 |    + (0.00s)   |    -        |       -     |     -      |       -    |       -      |
|      17 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      18 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      19 |             2 |    + (0.00s)   |    -        |  + (0.00s)  |     -      |       -    |       -      |
|      20 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      21 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      22 |             1 |    + (0.02s)   |    -        |       -     |     -      |       -    |       -      |
|      23 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      24 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      25 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      26 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      27 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      28 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      29 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      30 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      31 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      32 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      33 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      34 |             - |       -        |    -        |       -     |     -      |       -    |       -      |
|      35 |             - |       -        |    -        |       -     |     -      |       -    |       -      |

## <a name="adding-solutions"></a> Adding Solutions

You can use the script `gen_new_probl.sh` to quickly generate a template for your problem solution. Problem number, author name and date will be automatically filled in. **Javascript, Go and Rust and not yet fully supported**, i.e. source files are created from templates but need to be modified to a certain amount.

E.g. to generate a template for your C++ solution to problem 123 use

```bash
./gen_new_problem.sh -l cpp -n 123
```

## <a name="license"></a> License

The code in this repository is MIT-licensed (see [LICENSE.md](./LICENSE.md) for more information).
