#include "Play.h"
#include "Editable.h"

// Return true to swap the spider for the rocket, false for normal game play
bool IsRocketTutorial() 
{
	return true;
}

// Controls the number of asteroids (in level 1)
int DefaultNumAsteroids()
{
	return 10;
}

// Controls the number of fiery meteors (in level 1)
int DefaultNumMeteors()
{
	return 2;
}

// Controls the initial movement speed of the spider when flying
float DefaultPlayerSpeed()
{
	return 7.0;
}

// Controls the movement speed of asteroids
float DefaultAsteroidSpeed()
{
	return 4.0;
}

//Controls the movement speed of firey meteors

float DefaultMeteorSpeed()
{
	return 4.0;
}

// Controls the movement of the rocket ship in the tutorial mode
void UpdatePlayerMovement(float& x, float& y, float& angle, float& speed)
{
	if(Play::KeyDown(VK_RIGHT))
	{
		angle = angle + 0.1;
	}

	if (Play::KeyDown(VK_LEFT))
	{
		angle = angle - 0.1;
	}

	x = x + sin(angle) * speed;
	y = y - cos(angle) * speed;

	if (Play::KeyDown(VK_UP))
	{
		speed = speed + 0.2;
	}

	if (Play::KeyDown(VK_DOWN))
	{
		speed = speed * 0.9;
	}

	speed = speed * 0.99;
	
	if (Play::KeyPressed(VK_SPACE))
	{
		CreateLaser(x, y, angle, speed + 10);
	}
}


// Controls the movement of lasers in the tutorial mode
void UpdateLaserMovement( float& x, float& y, float& angle, float& speed )
{
	x = x + sin(angle) * speed;
	y = y - cos(angle) * speed;
}

// Tests to see if a laser has collided with an asteroid
bool IsLaserCollidingWithAsteroid( float laserX, float laserY, float asteroidX, float asteroidY )
{
	float xDiff = asteroidX - laserX;
	float yDiff = asteroidY - laserY;

	float dist = sqrt(xDiff * xDiff + yDiff * yDiff);

	if (dist < 100)
	{
		return true;
	}

	return false;
	// Don't put any code after the return - it won't do anything!
}
