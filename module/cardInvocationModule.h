/**
 * cardInvocation.h
 *
 *
 */

#ifndef NATIVE_cardInvocation_MODULE
#define NATIVE_cardInvocation_MODULE

#include "TiCore.h"

class cardInvocationModule: public Ti::TiModule {
public:
	CREATE_MODULE (cardInvocationModule);
	cardInvocationModule(const char*);
	virtual ~cardInvocationModule();

	virtual Ti::TiValue getModuleId();
	virtual Ti::TiValue getModuleVersion();
	virtual Ti::TiValue getModuleName();

};

#endif
