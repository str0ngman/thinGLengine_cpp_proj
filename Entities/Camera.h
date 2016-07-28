#ifndef CAMERA_H
#define CAMERA_H

#include <glm\glm.hpp>

class Camera{
public:
	Camera();
	virtual ~Camera();

	void Move();

	inline glm::vec3 GetPosition(){ return m_position; }
	inline float GetPitch(){ return m_pitch; }
	inline float GetYaw(){ return m_yaw; }
	inline float GetRoll(){ return m_roll; }

private:
	glm::vec3 m_position;
	float m_pitch;
	float m_yaw;
	float m_roll;
};

#endif //!CAMERA_H