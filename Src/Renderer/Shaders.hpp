#pragma once

#include <filesystem>
#include <fstream>
#include <unordered_map>

#include "TypeDef.hpp"

namespace TE::Renderer
{
    /**
     * @class Shader
     *
     * @brief A base class for any shader used by the engine
     *
     * This class provides a common interface for any shader used by the engine. It
     * includes functions to bind and unbind the shader, as well as to get the ID
     * and name of the shader. Additionally, it includes functions to set various
     * types of uniforms.
     */
    class Shader
    {
        public:
            /**
             * @brief Default constructor
             *
             * This is the default constructor for the Shader class. It does not
             * initialize anything.
             */
            Shader() = default;

            /**
             * @brief Virtual destructor
             *
             * This is the virtual destructor for the Shader class. It is used to
             * ensure that the correct destructor is called when a derived class
             * is destroyed.
             */
            virtual ~Shader() = default;

            /**
             * @brief Bind the shader
             *
             * This function binds the shader, so that it can be used for
             * rendering.
             */
            virtual void Bind() const = 0;

            /**
             * @brief Unbind the shader
             *
             * This function unbinds the shader, so that it can no longer be
             * used for rendering.
             */
            virtual void Unbind() const = 0;

            /**
             * @brief Get the ID of the shader
             *
             * This function returns the ID of the shader. The ID is a unique
             * identifier for the shader, and is used by the engine to identify
             * the shader.
             *
             * @return The ID of the shader
             */
            virtual ShaderProgramID GetID() const = 0;

            /**
             * @brief Get the name of the shader
             *
             * This function returns the name of the shader. The name is a string
             * that is used to identify the shader.
             *
             * @return The name of the shader
             */
            virtual const String& GetName() const = 0;

            /**
             * @brief Get the uniform location
             *
             * This function returns the uniform location for the given uniform
             * name. The uniform location is an integer that is used by the engine
             * to identify the uniform.
             *
             * @param uniformName The name of the uniform
             *
             * @return The uniform location
             */
            virtual UniformLocation GetUniformLocation(const String& uniformName) = 0;

            /**
             * @brief Set a float uniform
             *
             * This function sets a float uniform with the given name to the
             * given value.
             *
             * @param uniformName The name of the uniform
             * @param value The value of the uniform
             */
            virtual void SetUnifrom(const String& uniformName, float value) = 0;

            /**
             * @brief Set an int uniform
             *
             * This function sets an int uniform with the given name to the
             * given value.
             *
             * @param uniformName The name of the uniform
             * @param value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, Int32 value) = 0;

            /**
             * @brief Set an unsigned int uniform
             *
             * This function sets an unsigned int uniform with the given name to
             * the given value.
             *
             * @param uniformName The name of the uniform
             * @param value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, UInt32 value) = 0;

            /**
             * @brief Set a vec2 uniform
             *
             * This function sets a vec2 uniform with the given name to the
             * given value.
             *
             * @param uniformName The name of the uniform
             * @param value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Vec2& value) = 0;

            /**
             * @brief Set a vec3 uniform
             *
             * This function sets a vec3 uniform with the given name to the
             * given value.
             *
             * @param uniformName The name of the uniform
             * @param value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Vec3& value) = 0;

            /**
             * @brief Set a vec4 uniform
             *
             * This function sets a vec4 uniform with the given name to the
             * given value.
             *
             * @param uniformName The name of the uniform
             * @param value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Vec4& value) = 0;

            /**
             * @brief Set a mat2 uniform
             *
             * This function sets a mat2 uniform with the given name to the
             * given value.
             *
             * @param uniformName The name of the uniform
             * @param value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Mat2& value) = 0;

            /**
             * @brief Set a mat3 uniform
             *
             * This function sets a mat3 uniform with the given name to the
             * given value.
             *
             * @param uniformName The name of the uniform
             * @param value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Mat3& value) = 0;

            /**
             * @brief Set a mat4 uniform
             *
             * This function sets a mat4 uniform with the given name to the
             * given value.
             *
             * @param uniformName The name of the uniform
             * @param value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Mat4& value) = 0;
    };

    /**
     * @brief Create a new shader
     *
     * This function creates a new shader with the given name and vertex/fragment
     * shader files. The shader is created with the appropriate OpenGL API calls
     * (glCreateProgram, glCreateShader, glShaderSource, glCompileShader, etc.).
     *
     * @param name The name of the shader
     * @param vtxShader The path to the vertex shader
     * @param fragShader The path to the fragment shader
     *
     * @return A shared pointer to the new shader
     */
    std::shared_ptr<Shader> CreateShader(const String& name, const Path& vtxShader, const Path& fragShader);
}