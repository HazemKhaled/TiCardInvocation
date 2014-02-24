/**
 * cardInvocation.cpp
 *
 * @auther Hazem Khaled <hazem.khaled@gmail.com>
 */

#include "cardInvocationModule.h"
#include "ExampleProxy.h"

cardInvocationModule::cardInvocationModule(const char* name) :
		Ti::TiModule(name) {
	addFunction("createInvocationManager", ExampleProxy::CreateProxy);
}

cardInvocationModule::~cardInvocationModule() {

}

Ti::TiValue cardInvocationModule::getModuleId() {
	Ti::TiValue val;
	val.setString("net.digipresence.cardinvocation");
	return val;
}
Ti::TiValue cardInvocationModule::getModuleVersion() {
	Ti::TiValue val;
	val.setString("0.1");
	return val;
}
Ti::TiValue cardInvocationModule::getModuleName() {
	Ti::TiValue val;
	val.setString("cardInvocation");
	return val;
}
