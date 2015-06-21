#include "camera.h"


Camera::Camera()
{
	m_speed = 0.1f;
	m_sensitivity = 0.01f;

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
	m_view = glm::lookAt(pos, dir, up);
}


void Camera::setPosition(float dx, float dy, float dz)
{
	m_pos.x += dx * m_speed;
	m_pos.y += dy * m_speed;
	m_pos.z += dz * m_speed;
	m_dir.x += dx * m_speed;
	m_dir.y += dy * m_speed;
	m_dir.z += dz * m_speed;
}


void Camera::setDirection(float dx, float dy)
{
	m_dir.x += dx * m_sensitivity;
	m_dir.y += -1 * dy * m_sensitivity;
}


glm::mat4 Camera::getViewMat()
{
	setView(m_pos, m_dir, m_up);
	return m_view;
}
