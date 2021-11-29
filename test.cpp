#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "1\n"
                "800\n"
                "1\n"
                "800 1000"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    INFO(buffer.str());
    REQUIRE(buffer.str() ==
            "1000"
    );
}

TEST_CASE("test 2", ""){
    std::stringstream input(
            "3\n"
            "1 2 3\n"
            "4\n"
            "1 10\n"
            "1 5\n"
            "10 7\n"
            "2 3"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "13"
    );
}

TEST_CASE("higher power costs less", ""){
    std::stringstream input(
            "3\n"
            "1 2 3\n"
            "4\n"
            "1 10\n"
            "1 5\n"
            "2 4\n"
            "3 6\n"
    );
    std::stringstream output;
    parseFile(input,output);
    INFO(output.str());
    REQUIRE(output.str() ==
            "14"
    );
}
