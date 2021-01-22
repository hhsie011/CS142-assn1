#include <ctime>
#include <iostream>
#include <math.h>
#include "get_time.h"

// long double getIntegral(int, int n) {
//     if (n == 1) {
//         return (sin(1 + ))
//     }
//     left_integral = cilk_spawn getIntegral();
//     right_integral = getIntegral();
//     return left_integral + right_integral;
// }

int main() {
    int segs = 10^8;
    long double sum = 0;
    timer t;
    // sum = getIntegral();
    cilk_for (int i = 0; i < segs; i++) {
        sum += (sin(1 + i / segs) * log(1 + i  segs) + sin(1 + (i + 1) / segs) * log(1 + (i + 1) / segs) / segs / 2);
    }
    t.stop();
    std::cout << "sum: " << sum << std::endl;
    std::cout << "elapsed time: " << t.get_total() << std::endl;
    return 0;
}
