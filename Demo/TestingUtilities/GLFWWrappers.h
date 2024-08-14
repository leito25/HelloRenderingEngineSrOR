//
// Created by LEOQ on 8/14/2024.
//

struct GLFWwindow;

namespace Demo {
    class window;

    struct [[nodiscard]] glfw_manager
    {
        glfw_manager();

        glfw_manager(const glfw_manager&) = delete;

        glfw_manager& operator=(const glfw_manager&) = delete;

        ~glfw_manager();

        window create_window();
    };

    class [[nodiscard]] window
    {
        friend glfw_manager;

        GLFWwindow& m_Window;

        window();

        public:
        window(const window&) = delete;
        window& operator=(const window&) = delete;
        ~window();

        [[nodiscard]] GLFWwindow& get() {return m_Window;}
    };
}
