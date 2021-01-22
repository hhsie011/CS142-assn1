#include <ctime>
#include <iostream>
#include "get_time.h"

int main() {
    int segs = 10^8;
    long long sum = 0;
    timer t;
    for (int i = 0; i < segs; ++i) {
        sum += (sin(1 + i / segs) * log(1 + i / segs) + sin(1 + (i + 1) / segs) * log(1 + (i + 1) / segs)) / segs / 2;
    }
    t.stop();
    std::cout << "sum: " << sum << std::endl;
    std::cout << "elapsed time: " << t.get_total() << std::endl;
    return 0;
}