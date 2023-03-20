#ifndef __KEYBOARDCONTROLCOMPONENT_H__
#define __KEYBOARDCONTROLCOMPONENT_H__

#include <glm/glm.hpp>

struct KeyboardControlComponent
{
public: 
	glm::vec2 upVelocity; 
	glm::vec2 rightVelocity;
	glm::vec2 downVelocity;
	glm::vec2 leftVelocity;

public: 
	KeyboardControlComponent(glm::vec2 upVelocity = glm::vec2(0), glm::vec2 rightVelocity = glm::vec2(0), glm::vec2 downVelocity = glm::vec2(0), glm::vec2 leftVelocity = glm::vec2(0))
	{
		this->upVelocity = upVelocity; 
		this->rightVelocity = rightVelocity;
		this->downVelocity = downVelocity;
		this->leftVelocity = leftVelocity;
	}
};
#endif 