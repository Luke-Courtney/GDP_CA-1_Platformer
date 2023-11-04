#include "GravityDown.h"
#include "TextureHolder.h"
#include <iostream>
#include "Engine.h"

GravityDown::GravityDown()
{
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/gravitydown.png"));
}

bool GravityDown::handleInput()
{
	return false;
}
