#pragma once

#ifndef AE_RESOURCE_SYS_SOUND_DATA_HANDLER_H
#define AE_RESOURCE_SYS_SOUND_DATA_HANDLER_H

#include "../resource_handler.h"

namespace ae { namespace resource {

	class C_SoundDataResourceHandler : public I_ResourceHandler
	{
	public:
		C_SoundDataResourceHandler();
		virtual void Activate();
		virtual void Deactivate();
		virtual void PrintDebug();
	};

} } // namespace ae { namespace resource {

#endif // #ifdef AE_RESOURCE_SYS_SOUND_DATA_HANDLER_H
