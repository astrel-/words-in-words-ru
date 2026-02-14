#include <iostream>
#include <string>
#include <unordered_map>

#include "TxtReader.h"
#include "Utf16.h"


//static_assert(__cplusplus >= 202302L, "Not compiling as C++23");
static const std::string FILE_NAME = "data/russian-nouns.txt";

static std::unordered_map<wchar_t, int> to_hashtable(const std::wstring& input) {
	std::unordered_map<wchar_t, int> result;
	result.reserve(input.size());
	for (wchar_t ch : input) {
		result[ch]++;
	}
	return result;
}

static bool is_sub_hashtable(
	const std::unordered_map<wchar_t, int>& small, 
	const std::unordered_map<wchar_t, int>& big) {
	for (const auto& kv : small) {
		auto c = kv.first;
		int countSmall = kv.second;

		auto it = big.find(c);
		int countBig = (it != big.end()) ? it->second : 0;

		if (countSmall > countBig)
			return false;
	}
	return true;
}


int main() {

	std::wstring input = Utf16::read_line_utf16();
	auto inputHt = to_hashtable(input);

	std::cout << std::endl;

	auto words = TxtReader::read_file(FILE_NAME);

	for (const auto& word : words) {
		// Dictionary is sorted by increasing length, so we can stop early
		if (word.size() > input.size())
			break;

		auto wordHt = to_hashtable(word);


		if (is_sub_hashtable(wordHt, inputHt))
		{
			Utf16::print_symbol(word);
			std::cout << ": " << word.size() << std::endl;
		}
	}

	return 0;
}