#include "camera.h"
#include <glm/gtx/transform.hpp>


Camera::Camera()
{
	m_speed = 0.1f;
	m_sensitivity = 0.005f;

	setProjection();
	setView();
}


Camera::~Camera()
{
}


void Camera::setProjection(float fov, float aspect, float near, float far)
{
	m_fov = fov;
	m_aspect = aspect;
	m_near = near;
	m_far = far;
	m_projection = glm::perspective(fov, aspect, near, far);
}


void Camera::setView(glm::vec3 pos, glm::vec3 dir, glm::vec3 up)
{
	m_pos = pos;
	m_dir = dir;
	m_up = up;
	m_view = glm::lookAt(pos, pos + dir, up);
}


void Camera::setPosition(float dx, float dy, float dz)
{
	if (dz != 0.0f)
	{
		m_pos += -1 * dz * m_speed * m_dir;
	}
	if (dx != 0.0f)
	{
		m_pos += dx * m_speed * glm::cross(m_dir, m_up);
	}
	if (dy != 0.0f)
	{
		m_pos += dy * m_speed * m_up;
	}
}


void Camera::setDirection(float dx, float dy)
{
	glm::mat4 xRot = glm::rotate(-1 * dx * m_sensitivity, m_up);
	glm::mat4 yRot = glm::rotate(-1 * dy * m_sensitivity, glm::cross(m_dir, m_up));
	glm::vec3 newDir = glm::mat3(xRot * yRot) * m_dir;

	if (newDir.y <= 0.95f && newDir.y >= -0.95f)
		m_dir = newDir;
}


glm::mat4 Camera::getViewMat()
{
	setView(m_pos, m_dir, m_up);
	return m_view;
}
