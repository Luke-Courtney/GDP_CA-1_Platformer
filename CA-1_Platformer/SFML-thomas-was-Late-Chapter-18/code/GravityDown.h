#pragma once
#include "Pickup.h"

class GravityDown : public Pickup
{
public:
	// A constructor specific to Bob
	GravityDown();

	// The overriden input handler for Bob
	bool virtual handleInput();
};

