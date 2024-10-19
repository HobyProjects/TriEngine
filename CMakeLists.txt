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

set(
    TRIMANA_INCLUDE_DIRECTORIES
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Core
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/EntryPoint
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/OpenGL
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/ImGui
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Application
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Camera
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Scene
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Editor
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Maths
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/OpenGL
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/Vulkan
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/DirectX
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/GLFW
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Renderer
)

set(
    TRIMANA_HEADERS_FILES
        # CORE
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Core/Base.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Core/Asserts.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Core/Logs.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Core/KeyCodes.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Core/TypeDef.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Core/Window.hpp
    

        # EVENTS
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events/Events.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events/WindowEvents.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events/KeyboardEvents.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events/MouseEvents.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events/EventsReceiver.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events/InputHandler.hpp

        # APIS - OPENGL
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/OpenGL/OpenGL.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/OpenGL/GL_Buffers.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/OpenGL/GL_Context.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/OpenGL/GL_Debug.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/OpenGL/GL_Renderer.hpp

        # APIS - GLFW
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/GLFW/GLFW.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/GLFW/GLFW_Window.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/GLFW/GLFW_EventsReceiver.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/GLFW/GLFW_InputHandler.hpp

        # Renderer
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Renderer/Renderer.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Renderer/Buffers.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Renderer/Context.hpp
)

set(
    TRIMANA_SOURCES_FILES
        # CORE
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Core/Logs.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Core/Window.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/EntryPoint/TrimanaEngine.cpp

        # EVENTS
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events/EventsReceiver.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Events/InputHandler.cpp

        # APIS - OPENGL
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/OpenGL/GL_Buffers.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/OpenGL/GL_Context.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/OpenGL/GL_Debug.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/OpenGL/GL_Renderer.cpp
  
        # APIS - GLFW
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/GLFW/GLFW_Window.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/GLFW/GLFW_EventsReceiver.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/APIs/GLFW/GLFW_InputHandler.cpp

        # Renderer
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Renderer/Renderer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Renderer/Buffers.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Src/Renderer/Context.cpp

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

