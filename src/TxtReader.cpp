#include "TxtReader.h"
#include "Utf16.h"
#include <windows.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


static std::wstring utf8_to_utf16(const std::string& s) {
	if (s.empty()) return L"";

	int n = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
		s.data(), (int)s.size(),
		nullptr, 0);
	if (n == 0) throw std::runtime_error("Invalid UTF-8");

	std::wstring w(n, L'\0');
	MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
		s.data(), (int)s.size(),
		w.data(), n);
	return w;
}


namespace TxtReader {
	std::vector<std::wstring> read_file(const std::string& filename) {
		std::ifstream file(filename, std::ios::binary);
		std::vector<std::wstring> words;
		std::string line;
		std::wstring wline;

		while (std::getline(file, line)) {
			// strip UTF-8 BOM if present on first line
			if (words.empty() && line.size() >= 3 &&
				(unsigned char)line[0] == 0xEF &&
				(unsigned char)line[1] == 0xBB &&
				(unsigned char)line[2] == 0xBF) {
				line.erase(0, 3);
			}
			wline = utf8_to_utf16(line);
			words.push_back(wline);
		}

		return words;
	}
}