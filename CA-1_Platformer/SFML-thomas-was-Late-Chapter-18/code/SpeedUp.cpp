#include "SpeedUp.h"
#include "TextureHolder.h"
#include <iostream>
#include "Engine.h"

SpeedUp::SpeedUp()
{
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/speedup.png"));
}

bool SpeedUp::handleInput()
{
	return false;
}
