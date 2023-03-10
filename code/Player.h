#pragma once
#include "Constants.h"
class Player
{
public:
	Player(Texture* texture, float speed, float jumpHeight);
	~Player();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);

	Vector2f GetPosition();
	void OnCollision();
	FloatRect GetHitbox();
	void stopY();
	void Move(float yMove);
	float getY();
    void winBounds(); 

private:
	Sprite body;
	float jumpHeight;
	float speed;

	Vector2f velocity;
};
