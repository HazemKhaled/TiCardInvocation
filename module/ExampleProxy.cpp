/*
 * TestProxy.cpp
 *
 *  Created on: Sep 6, 2013
 *      Author: penrique
 */

#include "ExampleProxy.h"

#include <bb/system/CardDoneMessage>
#include <bb/system/InvokeRequest>

using namespace bb::system;

ExampleProxy::ExampleProxy(const char* name) :
		Ti::TiProxy(name) {

	// Create a method, it also has to start with `_`
	createPropertyFunction("openURL", _openURLMethod);

}

ExampleProxy::~ExampleProxy() {
	// delete instatiated pointers
}

Ti::TiValue ExampleProxy::openURLMethod(Ti::TiValue url) {

	Ti::TiValue returnValue;
	returnValue.toBool();
	if (invokeReply_ && !invokeReply_->isFinished()) {
		// Don't send another invoke request if one is already pending.
		return returnValue;
	}

	// convert url variable to QString
	QString myUrl = url.toString();

	InvokeRequest request;
	request.setTarget("sys.browser");
	request.setAction("bb.action.OPEN");
	request.setUri(myUrl);
	invokeReply_ = invokeManager_.invoke(request);
	if (!invokeReply_) {
		fprintf(stderr, "Failed to invoke this card\n");
		return returnValue;
	}

	//connect(invokeReply_, SIGNAL(finished()), SLOT(cardReplyFinished));
	returnValue.setBool(true);
	return returnValue;
}
/*
void ExampleProxy::cardReplyFinished() {
	Q_ASSERT(invokeReply_ && invokeReply_->isFinished());
	if (invokeReply_->error()) {
		// TODO: invoke "error" callback
		fprintf(stderr, "Error invoking card! %d\n", invokeReply_->error());
	}

	// We don't need the reply anymore so free up memory.
	invokeReply_->deleteLater();
}

void ExampleProxy::cardDone(const CardDoneMessage& message) {
	fprintf(stderr, "cardDone");
}*/
