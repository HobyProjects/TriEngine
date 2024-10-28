#pragma once

#include <filesystem>
#include <fstream>
#include <unordered_map>

#include "TypeDef.hpp"

namespace TE::Renderer
{
    class Shader
    {
        public:
            Shader() = default;
            virtual ~Shader() = default;

            virtual void Bind() const = TE_NULL;
            virtual void Unbind() const = TE_NULL;
            
            virtual ShaderProgramID GetID() const = TE_NULL;
            virtual const String& GetName() const = TE_NULL;
            virtual UniformLocation GetUniformLocation(const String& uniformName) = TE_NULL;

            virtual void SetUnifrom(const String& uniformName, Float value) = TE_NULL;
            virtual void SetUniform(const String& uniformName, Int32 value) = TE_NULL;
            virtual void SetUniform(const String& uniformName, UInt32 value) = TE_NULL;
            virtual void SetUniform(const String& uniformName, const Vec2& value) = TE_NULL;
            virtual void SetUniform(const String& uniformName, const Vec3& value) = TE_NULL;
            virtual void SetUniform(const String& uniformName, const Vec4& value) = TE_NULL;
            virtual void SetUniform(const String& uniformName, const Mat2& value) = TE_NULL;
            virtual void SetUniform(const String& uniformName, const Mat3& value) = TE_NULL;
            virtual void SetUniform(const String& uniformName, const Mat4& value) = TE_NULL;
    };

    Ref<Shader> CreateShader(const String& name, const Path& vtxShader, const Path& fragShader);
}