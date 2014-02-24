/**
 *
 *
 *
 */

#include "cardInvocationModuleStartup.h"
#include "cardInvocationModule.h"

Handle<Object> cardInvocationModuleStartup::CreateModule() {
	return cardInvocationModule::CreateModule();
}
