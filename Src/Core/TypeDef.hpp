#pragma once

#include <fstream>
#include <filesystem>
#include <string>
#include <memory>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

typedef int                         Int32;         
typedef unsigned int                UInt32;        
typedef unsigned short              UInt16;        
typedef unsigned char               UInt8;         
typedef char                        Int8;         
typedef float                       Float;         
typedef double                      Double;       
typedef std::string                 String;        
typedef const char*                 CString;       
typedef bool                        Boolean;      
typedef std::filesystem::path       Path;           
typedef std::ifstream               InputFile;      
typedef void*                       NativeWindow;   

template<typename T>
using Ref = std::shared_ptr<T>;         

template<typename T>
using WeakRef = std::weak_ptr<T>;      

template<typename T>
using Scope = std::unique_ptr<T>;       

template<typename T, typename... Args>
inline Ref<T> CreateRef(Args&&... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template<typename T, typename... Args>
inline Scope<T> CreateScope(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

#define TE_TRUE     1
#define TE_FALSE    0
#define TE_NULL     0

//==============================================================================

typedef glm::vec2 Vec2;
typedef glm::vec3 Vec3;
typedef glm::vec4 Vec4;
typedef glm::mat2 Mat2;
typedef glm::mat3 Mat3;
typedef glm::mat4 Mat4;
typedef glm::quat Quat;
typedef glm::dvec2 DVec2;
typedef glm::dvec3 DVec3;
typedef glm::dvec4 DVec4;
typedef glm::dmat2 DMat2;
typedef glm::dmat3 DMat3;
typedef glm::dmat4 DMat4;
typedef glm::dquat DQuat;

namespace Maths = glm;

//==============================================================================

typedef unsigned int VertexBufferID;
typedef unsigned int IndexBufferID;
typedef unsigned int TextureID;
typedef unsigned int ShaderID;
typedef unsigned int ShaderProgramID;
typedef unsigned int UniformLocation;
typedef float* VertexBufferData;
typedef unsigned int* IndexBufferData;
typedef unsigned int VertexArrayID;
typedef unsigned int TextureID;
typedef unsigned char* TextureData;
typedef unsigned int FrameBufferID;
typedef unsigned int FrameBufferAttachmentID;
