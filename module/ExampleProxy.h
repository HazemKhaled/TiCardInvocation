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

	// Method exampleMethod
	Ti::TiValue openURLMethod(Ti::TiValue);
	EXPOSE_METHOD(ExampleProxy, openURLMethod);

private slots:
	//void cardReplyFinished();
	//void cardDone(const bb::system::CardDoneMessage& message);

private:
	bb::system::InvokeManager invokeManager_;
	QPointer<bb::system::InvokeTargetReply> invokeReply_;
};

#endif /* NATIVE_cardInvocation_TESTPROXY_H_ */
