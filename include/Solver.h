#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace Solver {

	std::unordered_map<wchar_t, int> to_hashtable(const std::wstring& input);

	bool is_sub_hashtable(
		const std::unordered_map<wchar_t, int>& small,
		const std::unordered_map<wchar_t, int>& big);

	std::vector<std::wstring> solve(
		const std::wstring& input,
		const std::vector<std::wstring>& dictionary);
}
