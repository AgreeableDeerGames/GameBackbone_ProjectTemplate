#include <ProjectTemplate/Core/EventController.h>

#include <string>

using namespace PT;

static constexpr char* APP_NAME = "ProjectTemplate";

EventController::EventController() : CoreEventController(APP_NAME), mainRegion(getWindow())
{
	// Set the camera to the same as the window
	setActiveRegion(&mainRegion);
}
