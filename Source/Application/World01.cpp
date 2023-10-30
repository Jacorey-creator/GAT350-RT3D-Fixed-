#include "World01.h"
#include "Framework/Framework.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"

namespace nc
{
    bool World01::Initialize()
    {
        return true;
    }

    void World01::Shutdown()
    {
    }

    void World01::Update(float dt)
    {
        m_angle += 180 * dt;

        if (ENGINE.GetSystem<InputSystem>()->GetMouseButtonDown(0))
        {
            auto position = ENGINE.GetSystem<InputSystem>()->GetMousePosition();
            position /= vec2{ ENGINE.GetSystem<Renderer>()->GetWidth(), ENGINE.GetSystem<Renderer>()->GetHeight() };
            position *= 2;
            position -= 1;
            position.y *= -1;

            m_positions.push_back(position);
        }

        m_position.x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_A) ? -dt : 0;
        m_position.x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_D) ? +dt : 0;
        m_time += dt;
    }

    void World01::Draw(Renderer& renderer)
    {
        // pre-render
        renderer.BeginFrame();

        for (int i = 0; i < m_positions.size(); i++)
        {
            // render
            glPushMatrix();

            glTranslatef(m_positions[i].x, m_positions[i].y, 0);
            glRotatef(m_angle + (i * 0.1f), 0, 0, 1);
            float scale = (((sin((m_time * 5) + (i * 0.03f)) + 1) * 0.5f) * 0.1f) + 0.05f;
            glScalef(scale, scale, 0);

            glBegin(GL_TRIANGLES);

            glColor3f(1, 0, 0);
            glVertex2f(-0.5f, -0.5f);

            glColor3f(0, 1, 0);
            glVertex2f(0, 0.5f);

            glColor3f(0, 0, 1);
            glVertex2f(0.5f, -0.5f);

            glEnd();

            glPopMatrix();
        }

        // post-render
        renderer.EndFrame();
    }
}
