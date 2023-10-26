#pragma once

class SpeedUp
{
public:
	//default Constructor
	SpeedUp();

	//Update
	void update();

	//Get sprite
	Sprite getSprite();

	//Spawn
	void spawn(Vector2f position);

	//SpriteSprite m_Sprite;
	Sprite m_Sprite;

	//Position
	Vector2f m_Position;

	FloatRect getPosition();
};

