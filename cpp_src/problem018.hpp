#pragma once
#include <vector>
#include <string>

typedef std::vector<std::vector<unsigned>> Triangle;

Triangle getTriangle(const std::string &file);

unsigned triangle_sum_bruteforce(const Triangle &tri, unsigned hor = 0, unsigned ver = 0, unsigned sum = 0);

unsigned triangle_sum_fast(const Triangle &tri);
