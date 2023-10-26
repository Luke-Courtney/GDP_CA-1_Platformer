#include "TextureHolder.h"
#include <iostream>
#include "Engine.h"
#include "SpeedUp.h"

SpeedUp::SpeedUp()
{
	// Create a texture to hold a graphic on the GPU
	Texture speedupTexture;

	// Load a graphic into the texture
	speedupTexture.loadFromFile("graphics/speedup.png");

	// Create a sprite
	Sprite m_Sprite;

	// Attach the texture to the sprite
	m_Sprite.setTexture(speedupTexture);

	// Associate a texture with the sprite
	//m_Sprite = Sprite(TextureHolder::GetTexture("graphics/speedup.png"));
}

void SpeedUp::spawn(Vector2f position)
{
	m_Position = position;
}

void SpeedUp::update()
{
	m_Sprite.setPosition(m_Position);
}

Sprite SpeedUp::getSprite()
{
	return Sprite();
}

FloatRect SpeedUp::getPosition()
{
	return m_Sprite.getGlobalBounds();
}
