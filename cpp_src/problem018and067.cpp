// Project Euler Problem 018 and 067 Solution
//
// Problem statement: By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.<p style="text-align:center;font-family:'courier new';font-size:12pt;"><span style="color:#ff0000;"><b>3</b></span><br /><span style="color:#ff0000;"><b>7</b></span> 4<br />2 <span style="color:#ff0000;"><b>4</b></span> 6<br />8 5 <span style="color:#ff0000;"><b>9</b></span> 3That is, 3 + 7 + 4 + 9 = 23.Find the maximum total from top to bottom of the triangle below:<p style="text-align:center;font-family:'courier new';">75<br />95 64<br />17 47 82<br />18 35 87 10<br />20 04 82 47 65<br />19 01 23 75 03 34<br />88 02 77 73 07 63 67<br />99 65 04 28 06 16 70 92<br />41 41 26 56 83 40 80 70 33<br />41 48 72 33 47 32 37 16 94 29<br />53 71 44 65 25 43 91 52 97 51 14<br />70 11 33 28 77 73 17 78 39 68 17 57<br />91 71 52 38 17 14 91 43 58 50 27 29 48<br />63 66 04 68 89 53 67 30 73 16 69 87 40 31<br />04 62 98 27 23 09 70 98 73 93 38 53 60 04 23<p class="note"><b>NOTE:</b> As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
//
// Solution description: Brute force solution and a faster solution that will iterate over the rows and only keep the paths with the higher sum
//
// Author: Tom Praschan
// 2019/03/18
// License: MIT (see ../LICENSE.md)

#include "problem018and067.hpp"
#include <omp.h>
#include <fmt/ostream.h>
#include <fstream>
#include <sstream>
#include <iostream>

Triangle getTriangle(const std::string &file) {
    std::ifstream ifs(file);
    Triangle tri;
    std::string line;
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        tri.emplace_back(std::istream_iterator<unsigned>(iss), std::istream_iterator<unsigned>());
    }
    return tri;
}

unsigned triangle_sum_bruteforce(const Triangle &tri, unsigned hor, unsigned ver, unsigned sum) {
    static std::vector<unsigned> finalSums;
    sum += tri.at(ver).at(hor);
    if (ver == tri.size() - 1) {
        finalSums.emplace_back(sum);
        return 0;
    } else {
        triangle_sum_bruteforce(tri, hor, ver + 1, sum);
        triangle_sum_bruteforce(tri, hor + 1, ver + 1, sum);
    }
    return *std::max_element(finalSums.begin(), finalSums.end());
}

unsigned triangle_sum_fast(const Triangle &tri) {
    Triangle partialSum(tri.size());

    for (unsigned i = 0; i < tri.size(); i++)
        partialSum.at(i).reserve(tri.at(i).size());
    partialSum.at(0).push_back(tri.at(0).at(0));

    for (unsigned ver = 1; ver < tri.size(); ver++) {
        partialSum.at(ver).push_back(tri.at(ver).at(0) + partialSum.at(ver-1).at(0));
        unsigned horSize = tri.at(ver).size();
        for (unsigned hor = 1; hor < horSize - 1; hor++) {
            partialSum.at(ver).push_back(tri.at(ver).at(hor)
                    + std::max(partialSum.at(ver-1).at(hor-1), partialSum.at(ver-1).at(hor)));
        }
        partialSum.at(ver).push_back(tri.at(ver).at(horSize - 1) + partialSum.at(ver-1).at(horSize - 2));
    }
    return *std::max_element(partialSum.back().begin(),partialSum.back().end());
}

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    auto solution = triangle_sum_bruteforce(getTriangle("../input_files/problem018.txt"));
    auto end = omp_get_wtime();

    fmt::print("Bruteforce problem 18 Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);

    start = omp_get_wtime();
    solution = triangle_sum_fast(getTriangle("../input_files/problem018.txt"));
    end = omp_get_wtime();

    fmt::print("Fast problem 18 Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);

    start = omp_get_wtime();
    solution = triangle_sum_fast(getTriangle("../input_files/problem067.txt"));
    end = omp_get_wtime();

    fmt::print("Fast problem 67 Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
