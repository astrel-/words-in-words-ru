#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Solver.h"

static const std::wstring subword = L"проруб";
static const std::wstring word = L"прорубь";

TEST_CASE("Finds Subword") {
    std::vector<std::wstring> dictionary{ subword };
    
    auto result = Solver::solve(word, dictionary);

    CHECK(result.size() == 1);
    CHECK(result[0] == subword);
}

TEST_CASE("Doesn't find subword") {
    std::vector<std::wstring> dictionary{ word };

    auto result = Solver::solve(subword, dictionary);

    CHECK(result.empty());
}

TEST_CASE("Doesn't find 'e' letter substitution") {
    std::vector<std::wstring> dictionary1{ L"ё"};
    std::vector<std::wstring> dictionary2{ L"e" };

    auto result1 = Solver::solve(L"e", dictionary1);
    auto result2 = Solver::solve(L"ё", dictionary2);

    CHECK(result1.empty());
    CHECK(result2.empty());
}