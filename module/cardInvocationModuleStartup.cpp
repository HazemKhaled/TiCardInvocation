/**
 *
 *
 *
 */

#include "cardInvocationModuleStartup.h"
#include "cardInvocationModule.h"

Handle<Object> cardInvocationModuleStartup::CreateModule() {
	fprintf(stderr, "Yes Mezoooooo :)");
	return cardInvocationModule::CreateModule();
}
