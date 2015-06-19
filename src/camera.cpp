#include "camera.h"


Camera::Camera()
{
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
