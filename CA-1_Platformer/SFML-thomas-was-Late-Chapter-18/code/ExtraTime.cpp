#include "ExtraTime.h"
#include "TextureHolder.h"
#include <iostream>
#include "Engine.h"

ExtraTime::ExtraTime()
{
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/extratime.png"));
}

bool ExtraTime::handleInput()
{
	return false;
}
