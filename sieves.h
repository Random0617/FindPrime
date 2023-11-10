#ifndef SIEVES_H_INCLUDED
#define SIEVES_H_INCLUDED

#include <vector>
using namespace std;

void print_vector(vector<int> &nums);
vector<int> Eratosthenes(int &n);
vector<int> Sundaram(int &n);
vector<int> Atkin(int &n);
int random(int Min, int Max);
void generated_nums(vector<int> &nums);

#endif // SIEVES_H_INCLUDED
