#pragma once
#include <vector>
#include <string>

typedef std::vector<std::vector<unsigned>> Matrix;

Matrix getTriangle(const std::string &file);

unsigned bruteforce_solution(const Matrix &mat, unsigned hor = 0, unsigned ver = 0, unsigned sum = 0);
