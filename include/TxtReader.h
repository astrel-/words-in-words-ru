#pragma once
#include <string>
#include <vector>

namespace TxtReader {
	std::vector<std::wstring> read_file(const std::string& fileName);
}
