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

/**
 * @brief A type definition for a vertex buffer ID
 *
 * This type definition is used to identify a vertex buffer in the engine. It
 * is an unsigned integer, which is used to index into an array of vertex
 * buffers.
 */
typedef unsigned int TE_VertexBufferID;

/**
 * @brief A type definition for an index buffer ID
 *
 * This type definition is used to identify an index buffer in the engine. It
 * is an unsigned integer, which is used to index into an array of index
 * buffers.
 */
typedef unsigned int TE_IndexBufferID;

/**
 * @brief A type definition for a texture ID
 *
 * This type definition is used to identify a texture in the engine. It is an
 * unsigned integer, which is used to index into an array of textures.
 */
typedef unsigned int TE_TextureID;

/**
 * @brief A type definition for a shader ID
 *
 * This type definition is used to identify a shader in the engine. It is an
 * unsigned integer, which is used to index into an array of shaders.
 */
typedef unsigned int TE_ShaderID;

/**
 * @brief A type definition for a shader program ID
 *
 * This type definition is used to identify a shader program in the engine. It
 * is an unsigned integer, which is used to index into an array of shader
 * programs.
 */
typedef unsigned int TE_ShaderProgramID;

/**
 * @brief A type definition for a uniform ID
 *
 * This type definition is used to identify a uniform in the engine. It is an
 * unsigned integer, which is used to index into an array of uniforms.
 */
typedef unsigned int TE_UniformID;

/**
 * @brief A type definition for vertex buffer data
 *
 * This type definition is used to identify the data stored in a vertex buffer.
 * The data is represented as a pointer to a float, which is the type of the
 * data stored in the buffer.
 */
typedef float* TE_VertexBufferData;

/**
 * @brief A type definition for index buffer data
 *
 * This type definition is used to identify the data stored in an index buffer.
 * The data is represented as a pointer to an unsigned integer, which is the type
 * of the data stored in the buffer.
 */
typedef unsigned int* TE_IndexBufferData;
