#pragma once
#include "Pickup.h"

class ExtraTime : public Pickup
{
public:
	// A constructor specific to Bob
	ExtraTime();

	// The overriden input handler for Bob
	bool virtual handleInput();
};

