#include <iostream>
#include <vector>
#include <cmath>
#include "sieves.h"
using namespace std;

//Source: https://www.baeldung.com/cs/prime-number-algorithms
void print_vector(vector<int> &nums){
    int n = nums.size();
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
}
vector<int> Eratosthenes(int &n){
    bool* isPrime = new bool[n + 1];
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= n; i++){
        isPrime[i] = true;
    }
    for (int i = 2; i <= sqrt(n); i++){
        if (isPrime[i]){
            for (int j = i * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }
    vector<int> result;
    for (int i = 2; i <= n; i++){
        if (isPrime[i])
            result.push_back(i);
    }
    return result;
}
vector<int> Sundaram(int &n){
    int k = (n + 1) / 2;
    bool* isPrime = new bool[k + 1];
    for (int i = 0; i <= k; i++){
        isPrime[i] = true;
    }
    for (int i = 1; i <= sqrt(k); i++){
        int j = i;
        while (i + j + 2*i*j <= k){
            isPrime[i + j + 2*i*j] = false;
            j++;
        }
    }
    vector<int> result;
    for (int i = 1; i <= k; i++){
        if (isPrime[i])
            result.push_back(2*i + 1);
    }
    return result;
}
vector<int> Atkin(int &n){
    //This one uses https://en.wikipedia.org/wiki/Sieve_of_Atkin#Algorithm
    //Another source: https://www.geeksforgeeks.org/sieve-of-atkin/
    //Step 2
    bool* isPrime = new bool[n + 1];
    for (int i = 0; i <= n; i++){
        isPrime[i] = false;
    }
    //Step 1
    if (n > 2)
        isPrime[2] = true;
    if (n > 3)
        isPrime[3] = true;
    //Step 3
    for (int x = 1; x * x <= n; x++){
        for (int y = 1; y * y <= n; y++){
            int m = 4*x*x + y*y;
            if ((m % 12 == 1 || m % 12 == 5) && m <= n)
                isPrime[m] = !isPrime[m];
            m = 3*x*x + y*y;
            if (m % 12 == 7 && m <= n)
                isPrime[m] = !isPrime[m];
            m = 3*x*x - y*y;
            if (x > y && m % 12 == 11 && m <= n)
                isPrime[m] = !isPrime[m];
        }
    }
    //Steps 4-7
    for (int i = 5; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int k = i * i; k <= n; k += i * i)
                isPrime[k] = false;
        }
    }
    vector<int> result;
    for (int i = 1; i <= n; i++){
        if (isPrime[i])
            result.push_back(i);
    }
    return result;
}
int random(int Min, int Max){
    //Default: 0 to 1073741823
    int diff = Max - Min;
    int a = rand(), b = rand();
    int large_rand = a * (RAND_MAX + 1) + b;
    int small_rand = large_rand % diff;
    int correct_rand = small_rand + Min;
    return correct_rand;
}
void generated_nums(vector<int> &nums){
    nums.clear();
    for (int i = 1; i <= 10; i++){ //0 to 9
        int generated_num = random(10,99);
        nums.push_back(generated_num);
    }
    for (int i = 1; i <= 100; i++){ //10 to 109
        int generated_num = random(100,999);
        nums.push_back(generated_num);
    }
    for (int i = 1; i <= 200; i++){ //110 to 309
        int generated_num = random(1000,9999);
        nums.push_back(generated_num);
    }
    for (int i = 1; i <= 200; i++){ //310 to 509
        int generated_num = random(10000,99999);
        nums.push_back(generated_num);
    }
    for (int i = 1; i <= 200; i++){ //510 to 709
        int generated_num = random(100000,999999);
        nums.push_back(generated_num);
    }
    for (int i = 1; i <= 200; i++){ //710 to 909
        int generated_num = random(1000000,9999999);
        nums.push_back(generated_num);
    }
    for (int i = 1; i <= 100; i++){ //910 to 1009
        int generated_num = random(10000000,99999999);
        nums.push_back(generated_num);
    }
    for (int i = 1; i <= 10; i++){ //1010 to 1019
        int generated_num = random(100000000,999999999);
        nums.push_back(generated_num);
    }
}
