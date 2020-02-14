#include "gui_container.h"

#include "../gl/vertex_array.h"
#include "gui_rectangle.h"
#include "gui_shader.h"
#include <glm/gtc/matrix_transform.hpp>

int GuiContainer::uidCount = 0;

GuiContainer::GuiContainer()
    : m_uid(uidCount++)
{
}

void GuiContainer::hide()
{
    m_isHidden = true;
}

void GuiContainer::show()
{
    m_isHidden = false;
}

void GuiContainer::addRectangle(GuiRectangle& rectangle)
{
    m_guiRectangles.push_back(&rectangle);
}

void GuiContainer::render(GuiShader& shader, const glm::vec2& viewport,
                          const gl::Drawable& quad)
{
    // TODO Maybe render to a framebuffer to avoid having to bind a bunch of textures over
    // and over
    for (auto rect : m_guiRectangles) {
        // TODO Bind the texture?
        glm::mat4 transform = rect->getRenderTransform(viewport);
        shader.updateTransform(transform);
        quad.draw();
    }
}