/*
 * TestProxy.h
 *
 *  Created on: Sep 6, 2013
 *      Author: penrique
 */

#ifndef NATIVE_cardInvocation_TESTPROXY_H_
#define NATIVE_cardInvocation_TESTPROXY_H_

#include "TiCore.h"
#include <bb/system/InvokeManager>
#include <bb/system/InvokeTargetReply>

class ExampleProxy: Ti::TiProxy {
public:
	CREATE_PROXY (ExampleProxy);
	ExampleProxy(const char*);
	virtual ~ExampleProxy();

	// Methods
	Ti::TiValue openURLMethod(Ti::TiValue);
	EXPOSE_METHOD(ExampleProxy, openURLMethod);

	Ti::TiValue callPhoneNumberMethod(Ti::TiValue);
	EXPOSE_METHOD(ExampleProxy, callPhoneNumberMethod);

	Ti::TiValue socialShareMethod(Ti::TiValue);
	EXPOSE_METHOD(ExampleProxy, socialShareMethod);

	Ti::TiValue openSettingsMethod(Ti::TiValue);
	EXPOSE_METHOD(ExampleProxy, openSettingsMethod);

	Ti::TiValue openPdfMethod(Ti::TiValue);
	EXPOSE_METHOD(ExampleProxy, openPdfMethod);

	Ti::TiValue openMapMethod(Ti::TiValue);
	EXPOSE_METHOD(ExampleProxy, openMapMethod);

private:
	bb::system::InvokeManager invokeManager_;
	QPointer<bb::system::InvokeTargetReply> invokeReply_;
};

#endif /* NATIVE_cardInvocation_TESTPROXY_H_ */
