#pragma once

#include <memory>
#include "TypeDef.hpp"

namespace TE::Renderer
{
    class Context
    {
        public:
            Context() = default;
            virtual ~Context() = default;

            virtual Boolean MakeContextCurrent() = TE_NULL;
            virtual void SwapBuffers() = TE_NULL;
            virtual void ChangeSwapInterval(UInt32 interval) = TE_NULL;
    };
    
    Ref<Context> CreateContext(NativeWindow window);
}