#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Solver.h"

static const std::wstring subword = L"проруб";
static const std::wstring word = L"прорубь";
static const std::wstring ye = L"\u0435"; // e
static const std::wstring yo = L"\u0451"; // ё

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
    std::vector<std::wstring> dictionary1{ yo };
    std::vector<std::wstring> dictionary2{ ye };

    auto result1 = Solver::solve(ye, dictionary1);
    auto result2 = Solver::solve(yo, dictionary2);

    CHECK(result1.size() == 1);
    CHECK(result1[0] == yo);
    CHECK(result2.size() == 1);
    CHECK(result2[0] == ye);
}