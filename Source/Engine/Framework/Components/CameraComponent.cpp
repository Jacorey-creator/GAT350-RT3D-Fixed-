#include "CameraComponent.h"
#include "Framework/Actor.h"

namespace nc
{
	void CameraComponent::Update(float dt)
	{
		//view = glm::lookAt(m_owner->transform.position, m_owner->transform.position + m_owner->transform.Forward(), glm::vec3{ 0, 1, 0 });
		projection = glm::perspective(glm::radians(fov), aspect, near, far);
	}

	void CameraComponent::SetPerspective(float fov, float aspectRatio, float near, float far)
	{
		this->fov = fov;
		this->aspect = aspect;
		this->near = near;
		this->far = far;

		projection = glm::perspective(glm::radians(fov), aspect, near, far);
	}

	void CameraComponent::SetLookAt(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up)
	{
		view = glm::lookAt(eye, center, up);
	}

	void CameraComponent::ProcessGui()
	{
		ImGui::Begin("CameraComponent");
		ImGui::DragFloat("FOV", &fov);
		ImGui::DragFloat("Aspect", &aspect);
		ImGui::DragFloat("Near", &near);
		ImGui::DragFloat("Far", &far);
		ImGui::End();
	}

	void CameraComponent::Read(const json_t& value)
	{
		READ_DATA(value, fov);
		READ_DATA(value, aspect);
		READ_DATA(value, near);
		READ_DATA(value, far);
	}
}