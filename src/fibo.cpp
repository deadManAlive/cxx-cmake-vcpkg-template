#include <fibo.h>
#include <range/v3/view.hpp>

namespace view = ranges::views;

int fib(int x) {
    int a = 0;
    int b = 1;

    for (int it : view::repeat(0) | view::take(x)) {
        (void)it;
        int tmp = a;
        a += b;
        b = tmp;
    }

    return a;
}
