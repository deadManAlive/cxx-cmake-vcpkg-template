#include <cxxopts.hpp>
#include <fibo.h>
#include <fmt/format.h>
#include <range/v3/view.hpp>

namespace view = ranges::views;

int main(int argc, char** argv) {
    cxxopts::Options options("fibo", "Print fibonacci sequence up to 'n'");
    options.add_options()("n,value", "The value to print to", cxxopts::value<int>()->default_value("10"));

    auto result = options.parse(argc, argv);
    auto n = result["value"].as<int>();

    for (int x : view::iota(1) | view::take(n)) {
        fmt::print("fib({}) = {}\n", x, fib(x));
    }
}
