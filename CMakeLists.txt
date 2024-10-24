cmake_minimum_required(VERSION 3.20)
project(TrimanaEngine VERSION 1.0.0)

find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)
find_package(spdlog REQUIRED)
find_package(EnTT REQUIRED)
find_package(imgui REQUIRED)
find_package(imguizmo REQUIRED)
find_package(stb REQUIRED)
find_package(yaml-cpp REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(TE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Src)

set(
    TRIMANA_INCLUDE_DIRECTORIES
        ${TE_SRC_DIR}/Core
        ${TE_SRC_DIR}/EntryPoint
        ${TE_SRC_DIR}/Events
        ${TE_SRC_DIR}/OpenGL
        ${TE_SRC_DIR}/ImGui
        ${TE_SRC_DIR}/Application
        ${TE_SRC_DIR}/Camera
        ${TE_SRC_DIR}/Scene
        ${TE_SRC_DIR}/Editor
        ${TE_SRC_DIR}/Maths
        ${TE_SRC_DIR}/APIs
        ${TE_SRC_DIR}/APIs/OpenGL
        ${TE_SRC_DIR}/APIs/Vulkan
        ${TE_SRC_DIR}/APIs/DirectX
        ${TE_SRC_DIR}/APIs/GLFW
        ${TE_SRC_DIR}/APIs/ImGui/GLFW
        ${TE_SRC_DIR}/Renderer
)

set(
    TRIMANA_HEADERS_FILES
        # CORE
        ${TE_SRC_DIR}/Core/Base.hpp
        ${TE_SRC_DIR}/Core/Asserts.hpp
        ${TE_SRC_DIR}/Core/Logs.hpp
        ${TE_SRC_DIR}/Core/KeyCodes.hpp
        ${TE_SRC_DIR}/Core/TypeDef.hpp
        ${TE_SRC_DIR}/Core/Window.hpp
        ${TE_SRC_DIR}/Core/Timer.hpp
        ${TE_SRC_DIR}/Core/Layer.hpp
        ${TE_SRC_DIR}/Core/LayerStack.hpp
        ${TE_SRC_DIR}/Core/Instrument.hpp
    
        # EVENTS
        ${TE_SRC_DIR}/Events/Events.hpp
        ${TE_SRC_DIR}/Events/WindowEvents.hpp
        ${TE_SRC_DIR}/Events/KeyboardEvents.hpp
        ${TE_SRC_DIR}/Events/MouseEvents.hpp
        ${TE_SRC_DIR}/Events/EventsReceiver.hpp
        ${TE_SRC_DIR}/Events/InputHandler.hpp

        # UI
        ${TE_SRC_DIR}/UI/UI.hpp

        # IMGUI - GLFW
        ${TE_SRC_DIR}/APIs/ImGui/GLFW/GLFW_ImGui_KeyCode.hpp

        # APIS - OPENGL
        ${TE_SRC_DIR}/APIs/OpenGL/OpenGL.hpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Buffers.hpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Context.hpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Debug.hpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Renderer.hpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_SystemInfo.hpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Shader.hpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_VertexArray.hpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Texture2D.hpp

        # APIS - GLFW
        ${TE_SRC_DIR}/APIs/GLFW/GLFW.hpp
        ${TE_SRC_DIR}/APIs/GLFW/GLFW_Window.hpp
        ${TE_SRC_DIR}/APIs/GLFW/GLFW_EventsReceiver.hpp
        ${TE_SRC_DIR}/APIs/GLFW/GLFW_InputHandler.hpp

        # Renderer
        ${TE_SRC_DIR}/Renderer/Renderer.hpp
        ${TE_SRC_DIR}/Renderer/Buffers.hpp
        ${TE_SRC_DIR}/Renderer/Context.hpp
        ${TE_SRC_DIR}/Renderer/Shaders.hpp
        ${TE_SRC_DIR}/Renderer/VertexArray.hpp
        ${TE_SRC_DIR}/Renderer/Texture2D.hpp
)

set(
    TRIMANA_SOURCES_FILES
        # CORE
        ${TE_SRC_DIR}/Core/Logs.cpp
        ${TE_SRC_DIR}/Core/Window.cpp
        ${TE_SRC_DIR}/Core/LayerStack.cpp
        ${TE_SRC_DIR}/EntryPoint/TrimanaEngine.cpp

        # EVENTS
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events/EventsReceiver.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events/InputHandler.cpp

        # UI
        ${TE_SRC_DIR}/UI/UI.cpp

        # IMGUI - GLFW
        ${TE_SRC_DIR}/APIs/ImGui/GLFW/GLFW_ImGui_KeyCode.cpp

        # APIS - OPENGL
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Buffers.cpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Context.cpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Debug.cpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Renderer.cpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_SystemInfo.cpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Shader.cpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_VertexArray.cpp
        ${TE_SRC_DIR}/APIs/OpenGL/GL_Texture2D.cpp
          
        # APIS - GLFW
        ${TE_SRC_DIR}/APIs/GLFW/GLFW_Window.cpp
        ${TE_SRC_DIR}/APIs/GLFW/GLFW_EventsReceiver.cpp
        ${TE_SRC_DIR}/APIs/GLFW/GLFW_InputHandler.cpp

        # Renderer
        ${TE_SRC_DIR}/Renderer/Renderer.cpp
        ${TE_SRC_DIR}/Renderer/Buffers.cpp
        ${TE_SRC_DIR}/Renderer/Context.cpp
        ${TE_SRC_DIR}/Renderer/Shaders.cpp
        ${TE_SRC_DIR}/Renderer/VertexArray.cpp
        ${TE_SRC_DIR}/Renderer/Texture2D.cpp

)

add_executable(${PROJECT_NAME} ${TRIMANA_SOURCES_FILES} ${TRIMANA_HEADERS_FILES})

message(STATUS "CMAKE_BUILD_TYPE_INIT: ${CMAKE_BUILD_TYPE_INIT}")
if(CMAKE_BUILD_TYPE_INIT STREQUAL "Debug")
    add_compile_definitions(TRIMANA_DEBUG)
endif()

message(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(TRIMANA_PLATFORM_WINDOWS)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_definitions(TRIMANA_PLATFORM_LINUX)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin" OR CMAKE_SYSTEM_NAME STREQUAL "iOS" OR CMAKE_SYSTEM_NAME STREQUAL "MacOS")
    add_compile_definitions(TRIMANA_PLATFORM_MACOS)
endif()

target_link_libraries(
	${PROJECT_NAME} 
		PUBLIC
			glfw
			spdlog::spdlog
			glad::glad
			glm::glm
			EnTT::EnTT
			imgui::imgui
            imguizmo::imguizmo
			stb::stb
			yaml-cpp::yaml-cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${TRIMANA_INCLUDE_DIRECTORIES})

