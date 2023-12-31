#pragma once
#include "Framework/World.h"
#include "Core/Math/Vector2.h"
#include "Renderer/Renderer.h"
#include <vector>

namespace nc
{
	class World02 : public World
	{
	public:
		bool Initialize() override;
		void Shutdown() override;
		void Update(float dt) override;
		void Draw(Renderer& renderer) override;

	private:
		float m_angle = 0;
		float m_time = 0;
		vec2 m_position;
		std::vector<vec2> m_positions;

		GLuint m_vao = 0;
	};
}