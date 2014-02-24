/*
 * TestProxy.h
 *
 *  Created on: Sep 6, 2013
 *      Author: penrique
 */

#ifndef NATIVE_cardInvocation_TESTPROXY_H_
#define NATIVE_cardInvocation_TESTPROXY_H_

#include "TiCore.h"

class ExampleProxy: Ti::TiProxy {
public:
	CREATE_PROXY (ExampleProxy);
	ExampleProxy(const char*);
	virtual ~ExampleProxy();

	// Method exampleMethod
	Ti::TiValue exampleMethod(Ti::TiValue);
	EXPOSE_METHOD(ExampleProxy, exampleMethod);
};

#endif /* NATIVE_cardInvocation_TESTPROXY_H_ */
