#pragma once

#include <glm/glm.hpp>

#include <glad/glad.h>

namespace walnut {
	class OrthographicCamera {
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		void SetProjection(float left, float right, float bottom, float top);
		void SetPosition(const glm::vec3 &position) { m_Position = position; RecalculateViewMatrix(); }
		void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		glm::vec3 GetPosition() const { return m_Position; }
		GLfloat GetRotation() const { return m_Rotation; }
		glm::mat4 GetProjectionMatrix() const { return m_ProjectionMatrix; }
		glm::mat4 GetViewMatrix() const { return m_ViewMatrix; }
		glm::mat4 GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
	private:
		void RecalculateViewMatrix();
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;
	};

	class OrthographicCameraController {
	public:
		OrthographicCameraController(float aspectRatio, bool rotationEnabled = false);

		OrthographicCamera &GetCamera(void) { return m_Camera; }
		const OrthographicCamera &GetCamera(void) const { return m_Camera; }
		const float &GetZoomLevel(void) const { return m_CameraZoomLevel; }

		void SetZoomLevel(float level) { m_CameraZoomLevel = level; }
	private:
		float m_AspectRatio;

		OrthographicCamera m_Camera;
		float m_CameraZoomLevel = 1.0f;
		bool m_CameraRotationEnabled;
		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f; // in degrees, anti-clockwise
		float m_CameraTranslationSpeed = 5.0f;
		float m_CameraRotationSpeed = 180.0f;
	};
}

