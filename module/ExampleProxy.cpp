/*
 * TestProxy.cpp
 *
 *  Created on: Sep 6, 2013
 *      Author: penrique
 */

#include "ExampleProxy.h"

#include <bb/system/CardDoneMessage>
#include <bb/system/InvokeRequest>

// to send number data while invoking phone application
#include <bb/PpsObject>

using namespace bb::system;

ExampleProxy::ExampleProxy(const char* name) :
		Ti::TiProxy(name) {

	// Create a method, it also has to start with `_`
	createPropertyFunction("openURL", _openURLMethod);
	createPropertyFunction("callPhoneNumber", _callPhoneNumberMethod);
	createPropertyFunction("socialShare", _socialShareMethod);
	createPropertyFunction("openSettings", _openSettingsMethod);
	createPropertyFunction("openPdf", _openPdfMethod);

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

	// convert variable to QString
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

Ti::TiValue ExampleProxy::callPhoneNumberMethod(Ti::TiValue number) {

	Ti::TiValue returnValue;
	returnValue.toBool();
	if (invokeReply_ && !invokeReply_->isFinished()) {
		// Don't send another invoke request if one is already pending.
		return returnValue;
	}

	// convert variable to QString
	QString myNumber = number.toString();

	QVariantMap map;
	map.insert("number", myNumber);
    QByteArray requestData = bb::PpsObject::encode(map, NULL);

	InvokeRequest request;
	request.setAction("bb.action.DIAL");
	request.setMimeType("application/vnd.blackberry.phone.startcall");
	request.setData(requestData);
	invokeReply_ = invokeManager_.invoke(request);
	if (!invokeReply_) {
		fprintf(stderr, "Failed to invoke this card\n");
		return returnValue;
	}

	returnValue.setBool(true);
	return returnValue;
}

Ti::TiValue ExampleProxy::socialShareMethod(Ti::TiValue text) {
	//TODO: support image & url
	Ti::TiValue returnValue;
	returnValue.toBool();
	if (invokeReply_ && !invokeReply_->isFinished()) {
		// Don't send another invoke request if one is already pending.
		return returnValue;
	}

	// convert variable to QString
	QString myText = text.toString();

	InvokeRequest request;
	request.setAction("bb.action.SHARE");
	request.setMimeType("text/plain");
	//request.setUri(myUrl);
	request.setData(myText.toLocal8Bit());
	invokeReply_ = invokeManager_.invoke(request);
	if (!invokeReply_) {
		fprintf(stderr, "Failed to invoke this card\n");
		return returnValue;
	}

	//connect(invokeReply_, SIGNAL(finished()), SLOT(cardReplyFinished));
	returnValue.setBool(true);
	return returnValue;
}

Ti::TiValue ExampleProxy::openSettingsMethod(Ti::TiValue page) {
	Ti::TiValue returnValue;
	returnValue.toBool();
	if (invokeReply_ && !invokeReply_->isFinished()) {
		// Don't send another invoke request if one is already pending.
		return returnValue;
	}

	// convert variable to QString
	QString myPage = page.toString();

	InvokeRequest request;
	request.setTarget("sys.settings.card");
	request.setAction("bb.action.OPEN");
	request.setMimeType("settings/view");
	request.setUri(myPage);
	invokeReply_ = invokeManager_.invoke(request);
	if (!invokeReply_) {
		fprintf(stderr, "Failed to invoke this card\n");
		return returnValue;
	}

	//connect(invokeReply_, SIGNAL(finished()), SLOT(cardReplyFinished));
	returnValue.setBool(true);
	return returnValue;
}

Ti::TiValue ExampleProxy::openPdfMethod(Ti::TiValue url) {
	Ti::TiValue returnValue;
	returnValue.toBool();
	if (invokeReply_ && !invokeReply_->isFinished()) {
		// Don't send another invoke request if one is already pending.
		return returnValue;
	}

	// convert variable to QString
	QString myUrl = url.toString();

	InvokeRequest request;
	request.setTarget("com.rim.bb.app.adobeReader.viewer");
	request.setAction("bb.action.VIEW");
	request.setMimeType("application/pdf");
	request.setUri("file:" + QDir::currentPath() + "/app/native/assets/" + myUrl);
	invokeReply_ = invokeManager_.invoke(request);
	if (!invokeReply_) {
		fprintf(stderr, "Failed to invoke this card\n");
		return returnValue;
	}

	//connect(invokeReply_, SIGNAL(finished()), SLOT(cardReplyFinished));
	returnValue.setBool(true);
	return returnValue;
}
