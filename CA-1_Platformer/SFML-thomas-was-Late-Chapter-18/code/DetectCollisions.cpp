#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal = false;
	// Make a rect for all his parts
	FloatRect detectionZone = character.getPosition();

	// Make a FloatRect to test each block
	FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Build a zone around thomas to detect collisions
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;

	// Thomas is quite tall so check a few tiles vertically
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	// Make sure we don't test positions lower than zero
	// Or higher than the end of the array
	if (startX < 0)startX = 0;
	if (startY < 0)startY = 0;
	if (endX >= m_LM.getLevelSize().x)
		endX = m_LM.getLevelSize().x;
	if (endY >= m_LM.getLevelSize().y)
		endY = m_LM.getLevelSize().y;

	// Has the character fallen out of the map?
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);
	if (!character.getPosition().intersects(level))
	{
		//Respawn the character
		character.spawn(character.startPos, GRAVITY);
	}

	//Detect thomas collisions with enemy
	if (m_Thomas.getPosition().intersects(m_Bob.getPosition()) || m_Thomas.getPosition().intersects(m_RedBob.getPosition()) || m_Thomas.getPosition().intersects(m_BlueBob.getPosition()))
	{
		if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Bob.spawn(Vector2f(10,10), GRAVITY);
		}
		else if(m_Thomas.getFeet().intersects(m_RedBob.getHead()))
		{
			m_RedBob.spawn(Vector2f(10, 10), GRAVITY);
		}
		else if (m_Thomas.getFeet().intersects(m_BlueBob.getHead()))
		{
			m_BlueBob.spawn(Vector2f(10, 10), GRAVITY);
		}
		else
		{
			//Respawn thomas
			m_Thomas.spawn(m_Thomas.startPos, GRAVITY);
		}
	}

	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			// Initialize the starting position of the current block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			// Has character been burnt or drowned?
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3)
			{
				if (character.getPosition().intersects(block))
				{
					character.spawn(m_LM.getStartPosition(), GRAVITY);
					// Which sound should be played?
					if (m_ArrayLevel[y][x] == 2)// Fire, ouch!
					{
						// Play a sound
						m_SM.playFallInFire();

					}
					else // Water
					{
						// Play a sound
						m_SM.playFallInWater();
					}
				}
			}


			// Is character colliding with a regular block
			if (m_ArrayLevel[y][x] == 1)
			{

				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}


				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}


				//If a bob intersects a block, flip
				if (m_Bob.getRight().intersects(block))
				{
					m_Bob.flipped = true;
				}
				else if(m_Bob.getLeft().intersects(block))
				{
					m_Bob.flipped = false;
				}

				if (m_RedBob.getRight().intersects(block))
				{
					m_RedBob.flipped = true;
				}
				else if (m_RedBob.getLeft().intersects(block))
				{
					m_RedBob.flipped = false;
				}

				if (m_BlueBob.getRight().intersects(block))
				{
					m_BlueBob.flipped = true;
				}
				else if (m_BlueBob.getLeft().intersects(block))
				{
					m_BlueBob.flipped = false;
				}
			}

			//Pickups
			//SpeedUp
			if (m_Thomas.getPosition().intersects(m_SpeedUp.getPosition()))
			{
				m_Thomas.m_Speed += 15;
				m_SpeedUp.active = false;
			}

			//GravityDown
			if (m_Thomas.getPosition().intersects(m_GravityDown.getPosition()))
			{
				m_Thomas.m_Gravity += 2;
				m_GravityDown.active = false;
			}

			//ExtraTime
			if (m_Thomas.getPosition().intersects(m_ExtraTime.getPosition()))
			{
				m_TimeRemaining += 3;
				m_ExtraTime.active = false;
			}

			// More collision detection here once we have learned about particle effects
			// Has the characters' feet touched fire or water?
			// If so, start a particle effect
			// Make sure this is the first time we have detected this
			// by seeing if an effect is already running			
			if (!m_PS.running()) {
				if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3)
				{
					if (character.getFeet().intersects(block))
					{
						// position and start the particle system
						m_PS.emitParticles(character.getCenter());

					}
				}
			}

			// Has the character reached the goal?
			if (m_ArrayLevel[y][x] == 4)
			{
				// Character has reached the goal
				reachedGoal = true;
			}

		}

	}

	// All done, return, wheteher or not a new level might be required
	return reachedGoal;
}