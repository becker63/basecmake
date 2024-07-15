#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
#include <cstdio>
#include "../include/public/main.h"

int appmain(int argc, char** argv){
    puts("appmain\n");
    int num = factorial(3);
    printf("\n%d\n", num);
    return 0;
}

int main(int argc, char** argv) {
    doctest::Context context;

    // !!! THIS IS JUST AN EXAMPLE SHOWING HOW DEFAULTS/OVERRIDES ARE SET !!!

    // defaults
    context.addFilter("test-case-exclude", "*math*"); // exclude test cases with "math" in their name
    context.setOption("abort-after", 5);              // stop test execution after 5 failed assertions
    context.setOption("order-by", "name");            // sort the test cases by their name

    context.applyCommandLine(argc, argv);

    // overrides
    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail

    int res = context.run(); // run

    if(context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
        return res;          // propagate the result of the tests

    puts("\n\nRunning Main App\n\n");
    int client_stuff_return_code = appmain(argc, argv);

    return res + client_stuff_return_code; // the result from doctest is propagated here as well
}
