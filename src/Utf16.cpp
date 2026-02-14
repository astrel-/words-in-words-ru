#include <string>
#include <windows.h>


namespace Utf16 {
	std::wstring read_line_utf16() {
		HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

		wchar_t buffer[1024];
		DWORD read = 0;

		ReadConsoleW(hIn, buffer, 1023, &read, nullptr);

		// Remove CRLF
		if (read >= 2 && buffer[read - 2] == L'\r')
			read -= 2;

		return std::wstring(buffer, buffer + read);
	}

	void print_line(const std::wstring& s) {
		DWORD written = 0;
		WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE),
			s.data(), (DWORD)s.size(),
			&written, nullptr);
		WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE),
			L"\n", 1, &written, nullptr);
	}

	void print_symbol(const std::wstring& s) {
		DWORD written = 0;
		WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE),
			s.data(), (DWORD)s.size(),
			&written, nullptr);
	}
}