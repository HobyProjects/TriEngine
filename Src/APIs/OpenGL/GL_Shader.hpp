#pragma once

#include <glad/glad.h>

#include "TypeDef.hpp"
#include "Shaders.hpp"

namespace TE::APIs::OpenGL
{
    /**
     * @class GL_Shader
     *
     * @brief A class to represent an OpenGL shader
     *
     * This class is used to represent an OpenGL shader. It provides functions
     * to bind and unbind the shader, as well as to get the ID and name of the
     * shader. Additionally, it provides functions to set uniforms for the
     * shader.
     */
    class GL_Shader : public TE::Renderer::Shader
    {
        public:
            /**
             * @brief Default constructor
             *
             * This is the default constructor for the GL_Shader class. It does
             * not initialize anything.
             */
            GL_Shader() = default;

            /**
             * @brief Constructor
             *
             * This is the constructor for the GL_Shader class. It takes the
             * name of the shader, the path to the vertex shader, and the path
             * to the fragment shader as arguments. It uses these arguments to
             * create the shader program and compile the shaders.
             *
             * @param[in] name The name of the shader
             * @param[in] vtxShader The path to the vertex shader
             * @param[in] fragShader The path to the fragment shader
             */
            GL_Shader(const String& name, const Path& vtxShader, const Path& fragShader);

            /**
             * @brief Virtual destructor
             *
             * This is the virtual destructor for the GL_Shader class. It is
             * used to ensure that the correct destructor is called when a
             * derived class is destroyed.
             */
            virtual ~GL_Shader();

            /**
             * @brief Bind the shader
             *
             * This function binds the shader, so that it can be used for
             * rendering.
             */
            virtual void Bind() const override;

            /**
             * @brief Unbind the shader
             *
             * This function unbinds the shader, so that it can no longer be
             * used for rendering.
             */
            virtual void Unbind() const override;

            /**
             * @brief Get the ID of the shader
             *
             * This function returns the ID of the shader. The ID is a unique
             * identifier for the shader, and is used by the engine to identify
             * the shader.
             *
             * @return The ID of the shader
             */
            virtual ShaderProgramID GetID() const override;

            /**
             * @brief Get the name of the shader
             *
             * This function returns the name of the shader. The name is a
             * string that is used to identify the shader.
             *
             * @return The name of the shader
             */
            virtual const String& GetName() const override;

            /**
             * @brief Get the uniform location
             *
             * This function returns the location of a uniform in the shader.
             * The location is an ID that is used to identify the uniform.
             *
             * @param[in] uniformName The name of the uniform
             * @return The location of the uniform
             */
            virtual UniformLocation GetUniformLocation(const String& uniformName) override;

            /**
             * @brief Set a float uniform
             *
             * This function sets a float uniform for the shader. The uniform
             * is identified by its name, and the value is the value of the
             * uniform.
             *
             * @param[in] uniformName The name of the uniform
             * @param[in] value The value of the uniform
             */
            virtual void SetUnifrom(const String& uniformName, float value) override;

            /**
             * @brief Set a 32-bit signed integer uniform
             *
             * This function sets a 32-bit signed integer uniform for the
             * shader. The uniform is identified by its name, and the value is
             * the value of the uniform.
             *
             * @param[in] uniformName The name of the uniform
             * @param[in] value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, Int32 value) override;

            /**
             * @brief Set a 32-bit unsigned integer uniform
             *
             * This function sets a 32-bit unsigned integer uniform for the
             * shader. The uniform is identified by its name, and the value is
             * the value of the uniform.
             *
             * @param[in] uniformName The name of the uniform
             * @param[in] value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, UInt32 value) override;

            /**
             * @brief Set a 2D vector uniform
             *
             * This function sets a 2D vector uniform for the shader. The
             * uniform is identified by its name, and the value is the value of
             * the uniform.
             *
             * @param[in] uniformName The name of the uniform
             * @param[in] value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Vec2& value) override;

            /**
             * @brief Set a 3D vector uniform
             *
             * This function sets a 3D vector uniform for the shader. The
             * uniform is identified by its name, and the value is the value of
             * the uniform.
             *
             * @param[in] uniformName The name of the uniform
             * @param[in] value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Vec3& value) override;

            /**
             * @brief Set a 4D vector uniform
             *
             * This function sets a 4D vector uniform for the shader. The
             * uniform is identified by its name, and the value is the value of
             * the uniform.
             *
             * @param[in] uniformName The name of the uniform
             * @param[in] value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Vec4& value) override;

            /**
             * @brief Set a 2x2 matrix uniform
             *
             * This function sets a 2x2 matrix uniform for the shader. The
             * uniform is identified by its name, and the value is the value of
             * the uniform.
             *
             * @param[in] uniformName The name of the uniform
             * @param[in] value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Mat2& value) override;

            /**
             * @brief Set a 3x3 matrix uniform
             *
             * This function sets a 3x3 matrix uniform for the shader. The
             * uniform is identified by its name, and the value is the value of
             * the uniform.
             *
             * @param[in] uniformName The name of the uniform
             * @param[in] value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Mat3& value) override;

            /**
             * @brief Set a 4x4 matrix uniform
             *
             * This function sets a 4x4 matrix uniform for the shader. The
             * uniform is identified by its name, and the value is the value of
             * the uniform.
             *
             * @param[in] uniformName The name of the uniform
             * @param[in] value The value of the uniform
             */
            virtual void SetUniform(const String& uniformName, const Mat4& value) override;

        private:
            /**
             * @brief Compile the shaders
             *
             * This function compiles the shaders and creates the shader
             * program. It takes a map of shaders as an argument, where the key
             * is the type of shader and the value is the shader code.
             *
             * @param[in] shaders A map of shaders
             */
            void CompileShaders(std::unordered_map<GLenum, String>& shaders);

            /**
             * @brief Read a shader file
             *
             * This function reads a shader file and returns its contents as a
             * string.
             *
             * @param[in] filePath The path to the shader file
             * @return The contents of the shader file
             */
            String ReadShaderFiles(const Path& filePath);

        private:
            /**
             * @brief The ID of the shader program
             *
             * This is the ID of the shader program. The ID is a unique
             * identifier for the shader program, and is used by the engine to
             * identify the shader program.
             */
            ShaderProgramID m_programID{NULL};

            /**
             * @brief The name of the shader
             *
             * This is the name of the shader. The name is a string that is used
             * to identify the shader.
             */
            String m_Name{String()};

            /**
             * @brief The uniform locations
             *
             * This is a map of uniform locations. The key is the name of the
             * uniform, and the value is the location of the uniform.
             */
            std::unordered_map<String, UniformLocation> m_UniformLocations;
    };
}