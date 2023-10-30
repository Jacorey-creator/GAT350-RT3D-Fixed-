#pragma once
#include "Component.h"
#include "Renderer/Gui.h"
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>

namespace nc
{
	class CameraComponent : public Component, public IGui
	{
	public:
		CLASS_DECLARATION(CameraComponent)

		void Update(float dt) override;
		void ProcessGui() override;

		void SetPerspective(float fov, float aspectRatio, float near, float far);
		void SetLookAt(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up = { 0, 1, 0 });

	public:
		glm::mat4 projection{ 1 };
		glm::mat4 view{ 1 };

		float fov = 0;
		float aspect = 0;
		float near = 0;
		float far = 0;
	};
}
