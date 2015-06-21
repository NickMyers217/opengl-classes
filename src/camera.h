#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
	private:
		glm::mat4 m_projection;
		glm::mat4 m_view;

	public:
		float m_speed;
		float m_sensitivity;
		float m_fov;
		float m_aspect;
		float m_near;
		float m_far;
		glm::vec3 m_pos;
		glm::vec3 m_dir;
		glm::vec3 m_up;

		Camera();
		~Camera();

		void setProjection(float fov = 45.0f, float aspect = 16.0f / 9.0f, float near = 0.1f, float far = 100.0f);
		void setView(glm::vec3 pos = glm::vec3(0,0,5), glm::vec3 dir = glm::vec3(0,0,0), glm::vec3 up = glm::vec3(0,1,0));
		void setPosition(float dx, float dy, float dz);
		void setDirection(float dx, float dy);
		glm::mat4 getViewMat();

		glm::mat4 getProjectionMat() { return m_projection; }
};

#endif
