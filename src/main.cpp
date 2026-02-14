#include <iostream>

#include "Solver.h"
#include "TxtReader.h"
#include "Utf16.h"

static const std::string FILE_NAME = "data/russian-nouns.txt";

int main() {
	// Read input word
	std::wstring input = Utf16::read_line_utf16();
	std::cout << std::endl;

	// Read Dictionary
	auto words = TxtReader::read_file(FILE_NAME);

	auto results = Solver::solve(input, words);
	//Print out results

	for (const auto& word : results) {
		Utf16::print_symbol(word);
		std::cout << ": " << word.size() << std::endl;
	}

	return 0;
}