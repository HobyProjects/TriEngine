#pragma once

#include <glad/glad.h>

#include "TypeDef.hpp"
#include "Shaders.hpp"

namespace TE::APIs::OpenGL
{
    class GL_Shader : public TE::Renderer::Shader
    {
        public:
            GL_Shader() = default;
            GL_Shader(const String& name, const Path& vtxShader, const Path& fragShader);
            virtual ~GL_Shader();

            virtual void Bind() const override;
            virtual void Unbind() const override;
            virtual ShaderProgramID GetID() const override;
            virtual const String& GetName() const override;
            virtual UniformLocation GetUniformLocation(const String& uniformName) override;
            virtual void SetUnifrom(const String& uniformName, Float value) override;
            virtual void SetUniform(const String& uniformName, Int32 value) override;
            virtual void SetUniform(const String& uniformName, UInt32 value) override;
            virtual void SetUniform(const String& uniformName, const Vec2& value) override;
            virtual void SetUniform(const String& uniformName, const Vec3& value) override;
            virtual void SetUniform(const String& uniformName, const Vec4& value) override;
            virtual void SetUniform(const String& uniformName, const Mat2& value) override;
            virtual void SetUniform(const String& uniformName, const Mat3& value) override;
            virtual void SetUniform(const String& uniformName, const Mat4& value) override;

        private:
            void CompileShaders(std::unordered_map<GLenum, String>& shaders);
            String ReadShaderFiles(const Path& filePath);

        private:
            ShaderProgramID m_programID{TE_NULL};
            String m_Name{String()};
            std::unordered_map<String, UniformLocation> m_UniformLocations;
    };
}