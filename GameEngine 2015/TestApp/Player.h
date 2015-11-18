#pragma once
#include <GameEngine\GameEngine.hpp>
class Player
{
public:
	Player(ge::GameContext& gameContext);
	~Player();

	void Initialise();
	void ProcessInput(const std::vector<SDL_Event>& events);
	void Update(float elapsedTime);
	void Restrictions();
	void Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera);

private:
	ge::GameContext& m_gameContext;

	// A sprite
	ge::Rendering::Sprite m_sprite;
	glm::vec2 m_spriteDir;
};

