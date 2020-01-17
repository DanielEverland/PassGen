#include "Clipboard.h"

#include <Windows.h>

void Clipboard::FromString(string text)
{
	const char* output = text.c_str();
	const size_t length = text.size() + 1;
	HGLOBAL memory = GlobalAlloc(GMEM_MOVEABLE, length);
	memcpy(GlobalLock(memory), output, length);

	GlobalUnlock(memory);
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, memory);
	CloseClipboard();
}