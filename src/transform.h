#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
private:
	glm::mat4 m_modelMatrix;

public:
	glm::vec3 m_translation;
	float m_angle;
	glm::vec3 m_axis;
	glm::vec3 m_scale;

	Transform()
		: m_translation(glm::vec3(0.0f, 0.0f, 0.0f)),
		m_axis(glm::vec3(0.0f, 1.0f, 0.0f)),
		m_scale(glm::vec3(1.0f, 1.0f, 1.0f))
	{
		m_angle = 0.0f;
	}

	inline glm::mat4 getModelMat()
	{
		glm::mat4 translate = glm::translate(glm::mat4(1.0f), m_translation);
		glm::mat4 rotate = glm::rotate(translate, m_angle, m_axis);
		m_modelMatrix = glm::scale(rotate, m_scale);

		return m_modelMatrix;
	}
};


#endif
