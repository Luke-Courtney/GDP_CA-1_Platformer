#include "Blue_bob.h"
#include "TextureHolder.h"
#include <iostream>
#include "Engine.h"

Blue_bob::Blue_bob()
{
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/Blue_bob.png"));

	hasPatrolPoint = false;
	//SetPatrolPoint(getCenter());

	m_JumpDuration = .25;
}

void Blue_bob::SetPatrolPoint(Vector2f newPatrolPoint)
{
	if (!hasPatrolPoint)
	{
		patrolPoint = newPatrolPoint;
		hasPatrolPoint = true;
	}
}

void Blue_bob::patrol()
{
	//If bob moves far enough from of his patrol point, flip direction
	if (moving && !flipped && m_Position.x > patrolPoint.x + 150)
	{
		flipped = true;
		//m_Sprite.setScale(-1, 0);
	}

	if (moving && flipped && m_Position.x < patrolPoint.x - 150)
	{
		flipped = false;
		//m_Sprite.setScale(1, 0);
	}
}

bool Blue_bob::handleInput()
{
	m_JustJumped = false;

	patrol();

	if (true)
	{

		// Start a jump if not already jumping
		// but only if standing on a block (not falling)
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}

	}
	else
	{
		m_IsJumping = false;
		m_IsFalling = true;

	}

	if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::A))
	{
		if (moving && flipped)
		{
			m_LeftPressed = true;

		}
		else
		{
			m_LeftPressed = false;
		}


		if (moving && !flipped)
		{
			m_RightPressed = true;
		}
		else
		{
			m_RightPressed = false;
		}
	}
	
	return m_JustJumped;
}