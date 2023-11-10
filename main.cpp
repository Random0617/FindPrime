#include <iostream>
#include <time.h>
#include "sieves.h"
using namespace std;

void single_method(vector<int> &generated, int x){
    clock_t start;
    clock_t stop;
    int start_points[8] = {0, 10, 110, 310, 510, 710, 910, 1010};
    int stop_points[8] = {9, 109, 309, 509, 709, 909, 1009, 1019};
    for (int k = 0; k < 8; k++){
        start = clock();
        for (int i = start_points[k]; i < stop_points[k]; i++){
            if (x == 1)
                vector<int> primes = Eratosthenes(generated[i]);
            else if (x == 2)
                vector<int> primes = Sundaram(generated[i]);
            else
                vector<int> primes = Atkin(generated[i]);
        }
        stop = clock();
        cout << "Time: " << double(stop - start) / CLOCKS_PER_SEC << " seconds\n";
    }
}
void permanent_memory(vector<int> &generated, int x){
    clock_t start;
    clock_t stop;
    int start_points[8] = {0, 10, 110, 310, 510, 710, 910, 1010};
    int stop_points[8] = {9, 109, 309, 509, 709, 909, 1009, 1019};
    vector<int> primes;
    int custom_max = 999999999;
    start = clock();
    if (x == 1)
        primes = Eratosthenes(custom_max);
    else if (x == 2)
        primes = Sundaram(custom_max);
    else
        primes = Atkin(custom_max);
    stop = clock();
    cout << "Time: " << double(stop - start) / CLOCKS_PER_SEC << " seconds\n";
    for (int k = 0; k < 8; k++){
        start = clock();
        for (int i = start_points[k]; i < stop_points[k]; i++){
            int num_of_primes = 0;
            int primes_index = 0;
            while (primes_index < primes.size() && primes[primes_index] <= generated[i]){
                primes_index++;
                num_of_primes++;
            }

        }
        stop = clock();
        cout << "Time: " << double(stop - start) / CLOCKS_PER_SEC << " seconds\n";
    }
}
int main()
{
    vector<int> generated;
    generated_nums(generated);
    print_vector(generated);
    single_method(generated, 1);
    //single_method(generated, 2);
    //single_method(generated, 3);
    //permanent_memory(generated, 1);
    //permanent_memory(generated, 2);
    //permanent_memory(generated, 3);
    return 0;
}
