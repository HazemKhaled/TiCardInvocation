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

// Map
#include <bb/platform/LocationMapInvoker>
#include <bb/platform/RouteMapInvoker>

// contacts
#include <bb/cascades/pickers/ContactPicker>

using namespace bb::system;
using namespace bb::platform;
using namespace bb::cascades::pickers;

ExampleProxy::ExampleProxy(const char* name) :
		Ti::TiProxy(name) {

	// Create a method, it also has to start with `_`
	createPropertyFunction("openURL", _openURLMethod);
	createPropertyFunction("callPhoneNumber", _callPhoneNumberMethod);
	createPropertyFunction("facebookShare", _facebookShareMethod);
	createPropertyFunction("openSettings", _openSettingsMethod);
	createPropertyFunction("openPdf", _openPdfMethod);
	createPropertyFunction("openMap", _openMapMethod);
	createPropertyFunction("openContacts", _openContactsMethod);

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

Ti::TiValue ExampleProxy::facebookShareMethod(Ti::TiValue text) {
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
	request.setTarget("Facebook");
	request.setAction("bb.action.SHARE");
	request.setMimeType("text/plain");
	//request.setUri(myUrl);
	request.setData(myText.toLocal8Bit());
	invokeReply_ = invokeManager_.invoke(request);
	if (!invokeReply_) {
		fprintf(stderr, "Failed to invoke this card\n");
		return returnValue;
	}

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
	request.setUri(
			"file:" + QDir::currentPath() + "/app/native/assets/" + myUrl);
	invokeReply_ = invokeManager_.invoke(request);
	if (!invokeReply_) {
		fprintf(stderr, "Failed to invoke this card\n");
		return returnValue;
	}

	returnValue.setBool(true);
	return returnValue;
}

Ti::TiValue ExampleProxy::openMapMethod(Ti::TiValue type) {
	Ti::TiValue returnValue;
	returnValue.toBool();

	// convert variable to QString
	QString myType = type.toString();

	if (myType == "pin") {
		LocationMapInvoker lmi;

		// Sample location set as Toronto
		// Latitude and Longitude values are expressed
		// in WGS 84 datum standard
		lmi.setLocationLatitude(25.1980730);
		lmi.setLocationLongitude(55.2728830);
		lmi.setLocationName("Burj Khalifa");
		lmi.setLocationDescription("The tallest building in the world.");

		//set "geocode" : false
		lmi.setGeocodeLocationEnabled(true);

		//set "geolocation" : false
		lmi.setCurrentLocationEnabled(true);
		lmi.go();
	} else {
		RouteMapInvoker rmi;

		// Latitude and Longitude values are expressed
		// in WGS 84 datum standard
		rmi.setEndLatitude(25.1412000);
		rmi.setEndLongitude(55.1854000);
		rmi.setEndName("Burj Al-Arab");
		rmi.setEndDescription("The royal suite");
		rmi.setEndAddress("Burj Al-Arab, Dubai");
		rmi.setNavigationMode(bb::platform::MapNavigationMode::FastestRoute);
		rmi.setTransportationMode(bb::platform::MapTransportationMode::Car);
		rmi.go();
	}

	returnValue.setBool(true);
	return returnValue;
}

Ti::TiValue ExampleProxy::openContactsMethod(Ti::TiValue text) {
	Ti::TiValue returnValue;
	returnValue.toBool();
	ContactPicker *contactPicker = new ContactPicker();
	contactPicker->setMode(ContactSelectionMode::Single);
	contactPicker->setKindFilters(
			QSet<bb::pim::contacts::AttributeKind::Type>()
					<< bb::pim::contacts::AttributeKind::Phone);
	contactPicker->open();

	returnValue.setBool(true);
	return returnValue;
}
