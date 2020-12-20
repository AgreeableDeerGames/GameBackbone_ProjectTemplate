#pragma once

#include <ProjectTemplate/Utils/DllUtils.h>

#include <GameBackbone/Core/GameRegion.h>

#include <sfml/Graphics/RenderWindow.hpp>


namespace PT
{
    class libProjectTemplate TemplateRegion : public GB::GameRegion
    {
    public:
        TemplateRegion(sf::RenderWindow& window);
        ~TemplateRegion() override = default;
        TemplateRegion(const TemplateRegion& other) = delete;
        TemplateRegion(TemplateRegion&& other) = delete;
        TemplateRegion& operator=(const TemplateRegion& other) = delete;
        TemplateRegion& operator=(TemplateRegion&& other) = delete;

        bool handleEvent(sf::Int64 elapsedTime, const sf::Event& event) override;

    private:
        sf::RenderWindow& m_window;
        sf::View m_camera;
    };
}