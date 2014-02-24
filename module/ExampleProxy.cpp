/*
 * TestProxy.cpp
 *
 *  Created on: Sep 6, 2013
 *      Author: penrique
 */

#include "ExampleProxy.h"

ExampleProxy::ExampleProxy(const char* name) :
		Ti::TiProxy(name) {

	// Create a method, it also has to start with `_`
	createPropertyFunction("example", _exampleMethod);

}

ExampleProxy::~ExampleProxy() {
	// delete instatiated pointers
}

/*void ExampleProxy::initStart() {
	// Called when proxy created from JS and
	// not properties have been applied
}

void ExampleProxy::initEnd() {
	// Called when proxy created from JS and
	// properties have been applied
}*/

Ti::TiValue ExampleProxy::exampleMethod(Ti::TiValue value) {
	// Now you can call functions in this class
	// Get the value from `value`
	QString str = value.toString();
	str.prepend("Something added to ");

	// Call local function
	// doSomethingWith(str) <---- this would be a local function to this class

	// Create a return value
	Ti::TiValue returnValue;
	returnValue.setString(str);

	// Can also be null or undefined
	returnValue.setUndefined();
	// or
	returnValue.setNull();

	return returnValue;
}
