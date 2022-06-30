#pragma once
#include <stdio.h>

namespace Chanwool
{
	void _print(const char* _text)
	{
		printf(_text);
	}
}

namespace Test2
{
	void _print(const char* _text)
	{
		printf("Hello");
	}
}