#include "repch.h"
#include "RendererAPI.h"

#include "REngine/Platform/OpenGL/OpenGLRendererAPI.h"


namespace REngine {
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Unique<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
		case RendererAPI::API::None:    RE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateUnique<OpenGLRendererAPI>();
		}

		RE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}