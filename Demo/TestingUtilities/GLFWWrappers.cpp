//
// Created by LEOQ on 8/14/2024.
//

#include "TestingUtilities/GLFWWrappers.h"
#include "GLFW/glfw3.h"
#include <iostream>

namespace {
    void errorCallback(int error, const char* description) {
        std::cerr << error << description;
    }

    GLFWwindow& make_window() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        auto win{glfwCreateWindow(800, 600, "Hello GLFW", nullptr, nullptr)};
        if(!win)
            throw std::runtime_error{"Failed to create GLFW window"};

        glfwMakeContextCurrent(win);

        return *win;
    }
}

namespace Demo {
    glfw_manager::glfw_manager() {
        glfwSetErrorCallback(errorCallback);

        if(!glfwInit())
            throw std::runtime_error{"Failed to initialize GLFW\n"};
    }

    glfw_manager::~glfw_manager() { glfwTerminate(); }

    window glfw_manager::create_window() { return window{}; }

    window::window() : m_Window{make_window()} {}

    window::~window() { glfwDestroyWindow(&m_Window); }
}