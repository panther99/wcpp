#pragma once

#include <iostream>

#include "InputManager.h"

class InputSource : public InputManager
{
public:
	InputSource(std::istream& istream) : InputManager(&istream) {}

	unsigned int bytes_count() const;
	bool empty() const;
};
