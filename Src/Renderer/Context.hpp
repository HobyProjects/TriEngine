#pragma once

#include <memory>
#include "TypeDef.hpp"

namespace TE::Renderer
{
    class IContext
    {
        public:
            IContext() = default;
            virtual ~IContext() = default;

            virtual Boolean MakeContextCurrent() = TE_NULL;
            virtual void SwapBuffers() = TE_NULL;
            virtual void ChangeSwapInterval(UInt32 interval) = TE_NULL;
    };
    
    Ref<IContext> CreateContext(NativeWindow window);
}