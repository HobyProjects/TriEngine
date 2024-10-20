/**
 * @file TypeDef.hpp
 * @brief A collection of type definitions used throughout the engine
 *
 * These type definitions are used to create a level of abstraction between the
 * engine and the underlying graphics API. They are used to identify various
 * objects in the engine, such as vertex buffers, index buffers, textures, and
 * shaders.
 */
#pragma once

#include <fstream>
#include <filesystem>
#include <string>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

/**
 * @brief Basic type definitions
 *
 * These are basic type definitions used to represent fundamental data types
 * in the engine. They are used to abstract away the underlying types, so that
 * the engine can be compiled on different platforms.
 */

typedef int Int32;                  // A 32-bit signed integer
typedef unsigned int UInt32;        // A 32-bit unsigned integer
typedef unsigned short UInt16;      // A 16-bit unsigned integer
typedef unsigned char UInt8;        // An 8-bit unsigned integer
typedef char Int8;                  // An 8-bit signed integer
typedef float Float32;              // A 32-bit floating-point number
typedef double Float64;             // A 64-bit floating-point number
typedef std::string String;         // A string of characters
typedef std::filesystem::path Path; // A path to a file
typedef std::ifstream InputFile;    // A file stream
typedef void* WindowAPIPtr;         // A pointer to a window

//==============================================================================

/**
 * @brief A type definition for a 2D vector of floats
 *
 * This type definition is used to represent a 2D vector of floats in the
 * engine. It is used throughout the engine to represent vectors in 2D space.
 */
typedef glm::vec2 Vec2;

/**
 * @brief A type definition for a 3D vector of floats
 *
 * This type definition is used to represent a 3D vector of floats in the
 * engine. It is used throughout the engine to represent vectors in 3D space.
 */
typedef glm::vec3 Vec3;

/**
 * @brief A type definition for a 4D vector of floats
 *
 * This type definition is used to represent a 4D vector of floats in the
 * engine. It is used throughout the engine to represent vectors in 4D space.
 */
typedef glm::vec4 Vec4;

/**
 * @brief A type definition for a 2x2 matrix of floats
 *
 * This type definition is used to represent a 2x2 matrix of floats in the
 * engine. It is used throughout the engine to represent transformations in
 * 2D space.
 */
typedef glm::mat2 Mat2;

/**
 * @brief A type definition for a 3x3 matrix of floats
 *
 * This type definition is used to represent a 3x3 matrix of floats in the
 * engine. It is used throughout the engine to represent transformations in
 * 3D space.
 */
typedef glm::mat3 Mat3;

/**
 * @brief A type definition for a 4x4 matrix of floats
 *
 * This type definition is used to represent a 4x4 matrix of floats in the
 * engine. It is used throughout the engine to represent transformations in
 * 4D space.
 */
typedef glm::mat4 Mat4;

/**
 * @brief A type definition for a quaternion of floats
 *
 * This type definition is used to represent a quaternion of floats in the
 * engine. It is used throughout the engine to represent rotations in 3D
 * space.
 */
typedef glm::quat Quat;

/**
 * @brief A type definition for a 2D vector of doubles
 *
 * This type definition is used to represent a 2D vector of doubles in the
 * engine. It is used throughout the engine to represent vectors in 2D space
 * with high precision.
 */
typedef glm::dvec2 DVec2;

/**
 * @brief A type definition for a 3D vector of doubles
 *
 * This type definition is used to represent a 3D vector of doubles in the
 * engine. It is used throughout the engine to represent vectors in 3D space
 * with high precision.
 */
typedef glm::dvec3 DVec3;

/**
 * @brief A type definition for a 4D vector of doubles
 *
 * This type definition is used to represent a 4D vector of doubles in the
 * engine. It is used throughout the engine to represent vectors in 4D space
 * with high precision.
 */
typedef glm::dvec4 DVec4;

/**
 * @brief A type definition for a 2x2 matrix of doubles
 *
 * This type definition is used to represent a 2x2 matrix of doubles in the
 * engine. It is used throughout the engine to represent transformations in
 * 2D space with high precision.
 */
typedef glm::dmat2 DMat2;

/**
 * @brief A type definition for a 3x3 matrix of doubles
 *
 * This type definition is used to represent a 3x3 matrix of doubles in the
 * engine. It is used throughout the engine to represent transformations in
 * 3D space with high precision.
 */
typedef glm::dmat3 DMat3;

/**
 * @brief A type definition for a 4x4 matrix of doubles
 *
 * This type definition is used to represent a 4x4 matrix of doubles in the
 * engine. It is used throughout the engine to represent transformations in
 * 4D space with high precision.
 */
typedef glm::dmat4 DMat4;

/**
 * @brief A type definition for a quaternion of doubles
 *
 * This type definition is used to represent a quaternion of doubles in the
 * engine. It is used throughout the engine to represent rotations in 3D
 * space with high precision.
 */
typedef glm::dquat DQuat;

//==============================================================================

/**
 * @brief A type definition for a vertex buffer ID
 *
 * This type definition is used to identify a vertex buffer in the engine. It
 * is an unsigned integer, which is used to index into an array of vertex
 * buffers.
 */
typedef unsigned int VertexBufferID;

/**
 * @brief A type definition for an index buffer ID
 *
 * This type definition is used to identify an index buffer in the engine. It
 * is an unsigned integer, which is used to index into an array of index
 * buffers.
 */
typedef unsigned int IndexBufferID;

/**
 * @brief A type definition for a texture ID
 *
 * This type definition is used to identify a texture in the engine. It is an
 * unsigned integer, which is used to index into an array of textures.
 */
typedef unsigned int TextureID;

/**
 * @brief A type definition for a shader ID
 *
 * This type definition is used to identify a shader in the engine. It is an
 * unsigned integer, which is used to index into an array of shaders.
 */
typedef unsigned int ShaderID;

/**
 * @brief A type definition for a shader program ID
 *
 * This type definition is used to identify a shader program in the engine. It
 * is an unsigned integer, which is used to index into an array of shader
 * programs.
 */
typedef unsigned int ShaderProgramID;

/**
 * @brief A type definition for a uniform ID
 *
 * This type definition is used to identify a uniform in the engine. It is an
 * unsigned integer, which is used to index into an array of uniforms.
 */
typedef unsigned int UniformLocation;

/**
 * @brief A type definition for vertex buffer data
 *
 * This type definition is used to identify the data stored in a vertex buffer.
 * The data is represented as a pointer to a float, which is the type of the
 * data stored in the buffer.
 */
typedef float* VertexBufferData;

/**
 * @brief A type definition for index buffer data
 *
 * This type definition is used to identify the data stored in an index buffer.
 * The data is represented as a pointer to an unsigned integer, which is the type
 * of the data stored in the buffer.
 */
typedef unsigned int* IndexBufferData;
