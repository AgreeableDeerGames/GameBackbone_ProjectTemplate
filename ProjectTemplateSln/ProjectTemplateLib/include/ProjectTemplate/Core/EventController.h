#pragma once

#include <ProjectTemplate/Utils/DllUtils.h>

#include <GameBackbone/Core/CoreEventController.h>


namespace PT
{
	class libProjectTemplate EventController : public GB::CoreEventController <EventController>
	{
	public:
		// Constructors
		EventController();
		EventController(const EventController& other) = delete;
		EventController(EventController&& other) = default;
		EventController& operator=(const EventController& other) = delete;
		EventController& operator=(EventController&& other) = default;
		virtual ~EventController() = default;

		// Event handling
		bool handleCoreEvent(sf::Event& event);

	private:
		sf::View camera;

		//std::unique_ptr<MainMenuDemoRegion> mainMenuDemoRegion;
	};
}
