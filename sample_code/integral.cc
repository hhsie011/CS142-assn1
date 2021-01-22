#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <ctime>
#include <iostream>
#include <math.h>
#include "get_time.h"

int main() {
    int segs = 10^8;
    long double sum = 0;
    timer t;
    for (int l = 0; l < 10000; l++) {
        for (int i = (long)l * segs / 10000; i < (long)(l + 1) * segs / 10000; i++) {
            sum += (sin(1 + i / segs) * log(1 + i / segs) + sin(1 + (i + 1) / segs) * log(1 + (i + 1) / segs)) / segs / 2;
        }
    }
    t.stop();
    std::cout << "sum: " << sum << std::endl;
    std::cout << "elapsed time: " << t.get_total() << std::endl;
    return 0;
}
