#include "Pickup.h"

void Pickup::spawn(Vector2f startPosition)
{
	// Place the player at the starting point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	startPos = startPosition;

	// Move the sprite in to position
	m_Sprite.setPosition(m_Position);

	active = true;
}

void Pickup::update(float elapsedTime)
{

	if (active)
	{
		// Move the sprite into position
		m_Sprite.setPosition(m_Position);
	}
	else
	{
		m_Sprite.setPosition(0, 0);
	}
}

FloatRect Pickup::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f Pickup::getCenter()
{
	return Vector2f(
		m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2
	);
}

Sprite Pickup::getSprite()
{
	return m_Sprite;
}
