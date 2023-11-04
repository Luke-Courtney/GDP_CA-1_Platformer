#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Pickup
{
protected:
	Sprite m_Sprite;

	Vector2f m_Position;

private:

	// And a texture
	Texture m_Texture;

public:

	void spawn(Vector2f startPosition);

	Vector2f startPos;

	bool virtual handleInput() = 0;

	FloatRect getPosition();

	Sprite getSprite();

	Vector2f getCenter();

	void update(float elapsedTime);

	bool active;
};
