#include <ProjectTemplate/Core/EventController.h>

#include <string>

using namespace PT;

#define APP_NAME "ProjectTemplate"

EventController::EventController() : CoreEventController(APP_NAME), mainRegion(*window)
{
	// Set the camera to the same as the window
	camera.reset(sf::FloatRect(0, 0, (float)window->getSize().x, (float)window->getSize().y));
	activeRegion = &mainRegion;
}

bool EventController::handleCoreEvent(sf::Event & event)
{
	// Handle events not handled by the GUI
	switch (event.type) 
	{
		case sf::Event::Closed:
		{
			// Close the window, thus closing the game.
			window->close();
			return true;
		}
		case sf::Event::MouseMoved:
		{
			// Get the pixel position and map it to coordinates
			sf::Vector2i mousePos(event.mouseMove.x, event.mouseMove.y);
			sf::Vector2f actualPosition = window->mapPixelToCoords(mousePos);
			// Pass the event to the active region to handle
			return true;
		}
		case sf::Event::MouseButtonPressed:
		{
			// Get the pixel position and map it to coordinates
			sf::Vector2i mousePos(event.mouseButton.x, event.mouseButton.y);
			sf::Vector2f actualPosition = window->mapPixelToCoords(mousePos);
			// Pass the event to the active region to handle
			return true;
		}
		case sf::Event::MouseWheelScrolled:
		{
			// Pass the event to the active region to handle
			return true;
		}
		case sf::Event::KeyPressed:
		{
			// Pass the event to the active region to handle
			return true;
		}
		case sf::Event::KeyReleased:
		{
			// Pass the event to the active region to handle
			return true;
		}
		case sf::Event::Resized:
		{
			// Reset the camera to the same as the window
			camera.reset(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height));
			// Set the view on the window to be the reset camera
			window->setView(camera);
			// Set the view on the GUI to be the reset camera
			activeRegion->getGUI().setView(camera);
			return true;
		}
		default:
		{
			return false;
		}
	}
}