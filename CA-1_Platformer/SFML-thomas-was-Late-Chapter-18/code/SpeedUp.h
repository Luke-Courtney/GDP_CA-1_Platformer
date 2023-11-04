#pragma once
#include "Pickup.h"

class SpeedUp : public Pickup
{
public:
	// A constructor specific to Bob
	SpeedUp();

	// The overriden input handler for Bob
	bool virtual handleInput();
};

