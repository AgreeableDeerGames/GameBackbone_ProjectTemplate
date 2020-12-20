#include <ProjectTemplate/Core/TemplateRegion.h>

#include <GameBackbone/Core/GameRegion.h>

#include <sfml/Graphics/RenderWindow.hpp>

using namespace PT;

TemplateRegion::TemplateRegion(sf::RenderWindow& window) : m_window(window)
{
	m_camera.reset(sf::FloatRect(0, 0, (float)m_window.getSize().x, (float)m_window.getSize().y));
}

bool TemplateRegion::handleEvent(sf::Int64 elapsedTime, const sf::Event& event)
{
	// Handle events not handled by the GUI
	switch (event.type)
	{
		case sf::Event::Closed:
		{
			// Close the window, thus closing the game.
			m_window.close();
			return true;
		}
		case sf::Event::MouseMoved:
		{
			// Get the pixel position and map it to coordinates
			sf::Vector2i mousePos(event.mouseMove.x, event.mouseMove.y);
			sf::Vector2f actualPosition = m_window.mapPixelToCoords(mousePos);
			return true;
		}
		case sf::Event::MouseButtonPressed:
		{
			// Get the pixel position and map it to coordinates
			sf::Vector2i mousePos(event.mouseButton.x, event.mouseButton.y);
			sf::Vector2f actualPosition = m_window.mapPixelToCoords(mousePos);
			return true;
		}
		case sf::Event::MouseWheelScrolled:
		{
			return true;
		}
		case sf::Event::KeyPressed:
		{
			return true;
		}
		case sf::Event::KeyReleased:
		{
			return true;
		}
		case sf::Event::Resized:
		{
			// Reset the camera to the same as the window
			m_camera.reset(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height));
			// Set the view on the window to be the reset camera
			m_window.setView(m_camera);
			return true;
		}
		default:
		{
			return false;
		}
	}
}