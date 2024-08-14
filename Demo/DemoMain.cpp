////////////////////////////////////////////////////////////////////
//                Copyright Oliver J. Rosten 2024.                //
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.0. //
//    (See accompanying file LICENSE.md or copy at                //
//          https://www.gnu.org/licenses/gpl-3.0.en.html)         //
////////////////////////////////////////////////////////////////////

#include "TestingUtilities/GLFWWrappers.h"
#include "GLFW/glfw3.h"

#include <iostream>

int main()
{
    try {
        Demo::glfw_manager manager{};
        auto w{manager.create_window()};

        while(!glfwWindowShouldClose(&w.get())) {
            // Render here (optional)
            //glClear(GL_Colo...

            //Swap front and back buffers
            glfwSwapBuffers(&w.get());

            //Poll for and process events
            glfwPollEvents();
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
    }
    catch (...) {
        std::cerr << "Unrecognized error\n";
    }
}


