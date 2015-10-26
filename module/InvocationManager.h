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

class InvocationManager: Ti::TiProxy {
public:
	CREATE_PROXY (InvocationManager);
	InvocationManager(const char*);
	virtual ~InvocationManager();

	// Methods
	Ti::TiValue openURLMethod(Ti::TiValue);
	EXPOSE_METHOD(InvocationManager, openURLMethod);

	Ti::TiValue callPhoneNumberMethod(Ti::TiValue);
	EXPOSE_METHOD(InvocationManager, callPhoneNumberMethod);

	Ti::TiValue facebookShareMethod(Ti::TiValue);
	EXPOSE_METHOD(InvocationManager, facebookShareMethod);

	Ti::TiValue openSettingsMethod(Ti::TiValue);
	EXPOSE_METHOD(InvocationManager, openSettingsMethod);

	Ti::TiValue openPdfMethod(Ti::TiValue);
	EXPOSE_METHOD(InvocationManager, openPdfMethod);

	Ti::TiValue openMapMethod(Ti::TiValue);
	EXPOSE_METHOD(InvocationManager, openMapMethod);

	Ti::TiValue openContactsMethod(Ti::TiValue);
	EXPOSE_METHOD(InvocationManager, openContactsMethod);

private:
	bb::system::InvokeManager invokeManager_;
	QPointer<bb::system::InvokeTargetReply> invokeReply_;
};

#endif /* NATIVE_cardInvocation_TESTPROXY_H_ */
