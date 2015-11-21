#include "World.h"

World::World(ge::GameContext& gameContext) :
m_gameContext(gameContext),
m_player(gameContext),
m_Background(gameContext)
{
}

World::~World()
{
}

void World::Initialise()
{
	for (int i = 0; i < 1000; i++)
	{
		m_sprite[i].Load("Textures/stars.png",
			m_gameContext,
			glm::vec4(-1280.0f * i, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);
	}
	
	int size = -1280.0f;
		// Initialise our sprite
		m_sprite1.Load("Textures/Background1.png",
			m_gameContext,
			glm::vec4(size * 2, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite2.Load("Textures/Background1flare.png",
			m_gameContext,
			glm::vec4(size * 6, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);


		m_sprite3.Load("Textures/Clouds.png",
			m_gameContext,
			glm::vec4(size * 10, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);	

		m_sprite4.Load("Textures/Gasblue.png",
			m_gameContext,
			glm::vec4(size * 15, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite5.Load("textures/GasOrange.png",
			m_gameContext,
			glm::vec4(size * 16, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite6.Load("Textures/GasPurple.png",
			m_gameContext,
			glm::vec4(size * 17, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite7.Load("Textures/MettalicWithflare.png",
			m_gameContext,
			glm::vec4(size * 18, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite8.Load("Textures/MettalicWithflare2.png",
			m_gameContext,
			glm::vec4(size * 19, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite9.Load("Textures/MettalicWithflare21.png",
			m_gameContext,
			glm::vec4(size * 20, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);	

		m_sprite10.Load("Textures/MettalicWithoutflare.png",
			m_gameContext,
			glm::vec4(size * 24, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);
	

	// Add some more items to our item list here
	for (int i = 0; i < 8; i++)
	{
		Item& key = Item(m_gameContext, "Key", glm::vec2(i * 150, i * 75));
		key.Initialise();
		m_items.push_back(key);
	}

	m_player.Initialise();
}

void World::ProcessInput(std::vector<SDL_Event> events)
{
	m_player.ProcessInput(events);
}

void World::Update(float elapsedTime)
{
	// Update the player here
	m_player.Update(elapsedTime);

	glm::vec2 coOfBackgrounds(10.0f,0);
	m_sprite1.Move(coOfBackgrounds);
	m_sprite2.Move(coOfBackgrounds);
	m_sprite3.Move(coOfBackgrounds);
	m_sprite4.Move(coOfBackgrounds);
	m_sprite5.Move(coOfBackgrounds);
	m_sprite6.Move(coOfBackgrounds);
	m_sprite7.Move(coOfBackgrounds);
	m_sprite8.Move(coOfBackgrounds);
	m_sprite9.Move(coOfBackgrounds);
	m_sprite10.Move(coOfBackgrounds);

	//m_sprite2.Move(coOfBackgrounds);
	for (int i = 0; i < 1000; i++)
	{
		m_sprite[i].Move(coOfBackgrounds);

	}
	CheckCollisions();
}

void World::CheckCollisions()
{
	// Check collisions between player and items
	// Remove item from list if the player collides with it
}

void World::Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera)
{
	// Render the background here

	for (int i = 0; i < 1000; i++)
	{
		spriteBatch.Draw(m_sprite[i]);
	}
	spriteBatch.Draw(m_sprite1);
	spriteBatch.Draw(m_sprite2);
	spriteBatch.Draw(m_sprite3);
	spriteBatch.Draw(m_sprite4);
	spriteBatch.Draw(m_sprite5);
	spriteBatch.Draw(m_sprite6);
	spriteBatch.Draw(m_sprite7);
	spriteBatch.Draw(m_sprite8);
	spriteBatch.Draw(m_sprite9);
	spriteBatch.Draw(m_sprite10);
	//spriteBatch.Draw(m_sprite2);

	// Render the player here
	m_player.Draw(spriteBatch, camera);

	// Render all the items here
	
		
}