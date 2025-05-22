#include "Core/Core.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h" 
#include "backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

int main()
{
    Core::PrintHelloWorld();
    
    // Start GLFW (window library)
    if (!glfwInit()) {
        return -1;
    }

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "My First ImGui App", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Start ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark(); // Dark theme

    // Connect ImGui to our window
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Main loop - keep window open
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start new ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Create a simple window with text
        ImGui::Begin("Hello Window");
        ImGui::Text("Hello from ImGui!");
        if (ImGui::Button("Click me!")) {
            printf("Button was clicked!\n");
        }
        ImGui::End();

        // Draw everything
        ImGui::Render();
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Clean up
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();

    return 0;
}
