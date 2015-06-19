#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
	private:
		glm::mat4 modelMatrix;

	public:
		glm::vec3 translation;	
		float angle;
		glm::vec3 axis;
		glm::vec3 scale;

		Transform() 
			: translation(glm::vec3(0.0f, 0.0f, 0.0f)),
			  axis(glm::vec3(0.0f, 1.0f, 0.0f)),
			  scale(glm::vec3(1.0f, 1.0f, 1.0f))
		{
			angle = 0.0f;
		}

		glm::mat4 getModelMat()
		{
			glm::mat4 translate = glm::translate(glm::mat4(1.0f), translation);
			glm::mat4 rotate = glm::rotate(translate, angle, axis);
			modelMatrix = glm::scale(rotate, scale);

			return modelMatrix;
		}
};


#endif
