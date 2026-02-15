#pragma once
#include "Solver.h"

static const wchar_t ye = L'\u0435'; // e
static const wchar_t yo = L'\u0451'; // ё

namespace Solver {

	std::unordered_map<wchar_t, int> to_hashtable(const std::wstring& input) {
		std::unordered_map<wchar_t, int> result;
		result.reserve(input.size());
		for (wchar_t ch : input) {
			ch = ch == yo ? ye : ch;
			result[ch]++;
		}
		return result;
	}

	bool is_sub_hashtable(
		const std::unordered_map<wchar_t, int>& subword,
		const std::unordered_map<wchar_t, int>& word) {
		for (const auto& kv : subword) {
			auto c = kv.first;
			int countSmall = kv.second;

			auto it = word.find(c);
			int countBig = (it != word.end()) ? it->second : 0;

			if (countSmall > countBig)
				return false;
		}
		return true;
	}

	std::vector<std::wstring> solve(
		const std::wstring& input,
		const std::vector<std::wstring>& dictionary) {

		std::vector<std::wstring> result;

		auto inputHt = to_hashtable(input);

		for (const auto& word : dictionary) {
			// Dictionary is sorted by increasing length, so we can stop early
			if (word.size() > input.size())
				break;

			auto wordHt = to_hashtable(word);

			if (is_sub_hashtable(wordHt, inputHt)) {
				result.push_back(word);
			}
		}

		return result;
	}
}


