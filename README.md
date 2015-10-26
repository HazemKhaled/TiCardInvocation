# TiCardInvocation Module
## Description
BlackBerry 10 SDK allow you to call specific Window into another app as a child Window in your app, maybe like Android Intent or iOS URL Scheme! no more :)

It's allowing apps to share the UI and the app logic with other apps. You send a request to invoke a card in the same way as an invocation request for an app, which means that everything that applies to sending an invocation request applies to cards as well.

### From BlackBerry documentation
- [Invoking cards](https://developer.blackberry.com/native/documentation/device_platform/invocation/card_invocation.html)
- [Creating your own cards](https://developer.blackberry.com/native/documentation/device_platform/invocation/creating_cards.html)

## Accessing the TiCardInvocation Module
To access this module from JavaScript, you would do the following:

```javascript
var TiCardInvocation = require("net.digipresence.cardinvocation");
```

The TiCardInvocation variable is a reference to the Module object.

## Reference
### TiCardInvocation.createInvocationManager
The [InvokeManager](http://developer.blackberry.com/native/reference/cascades/bb__system__invokemanager.html?f=manager) supports sending and receiving invoke messages thus allowing an application to act as a client, a target, or both.

```javascript
var invocationManager = require('net.digipresence.cardinvocation').createInvocationManager();
```

### TiCardInvocation.openContacts
Open [ContactPicker](http://developer.blackberry.com/native/reference/cascades/bb__cascades__pickers__contactpicker.html?f=ContactPicker), ContactPicker is a full screen control that allows the user to select a contact, multiple contacts, or an attribute of a contact.

```javascript
var invocationManager = require('net.digipresence.cardinvocation').createInvocationManager();
invocationManager.openContacts(true);
```

### TiCardInvocation.openURL
Open the url in system browser.

```javascript
var invocationManager = require('net.digipresence.cardinvocation').createInvocationManager();
invocationManager.openURL('http://yahoo.com');
```

### TiCardInvocation.callPhoneNumber
Open phone caller, ready to call this number.

```javascript
var invocationManager = require('net.digipresence.cardinvocation').createInvocationManager();
invocationManager.callPhoneNumber('01234567890');
```

### TiCardInvocation.openPdf
Open given pdf file into Adobe Reader.

```javascript
var invocationManager = require('net.digipresence.cardinvocation').createInvocationManager();
invocationManager.openPdf('file.pdf');
```

### TiCardInvocation.openMap
Open [LocationMapInvoker](http://developer.blackberry.com/native/reference/cascades/bb__platform__locationmapinvoker.html?f=LocationMapInvoker) with pin to specific coordinates.

```javascript
var invocationManager = require('net.digipresence.cardinvocation').createInvocationManager();
invocationManager.openMap('pin', {
            annotations : [{
                name : "Burj Khalifa",
                description : "The tallest building in the world.",
                latitude : 25.1980730,
                longitude : 55.2728830
            }]
        });
```

### TiCardInvocation.openSettings
Open given screen in system settings by calling sys.settings.card.

```javascript
var invocationManager = require('net.digipresence.cardinvocation').createInvocationManager();
invocationManager.openSettings('settings://display');
```

### TiCardInvocation.facebookShare
Open Facebook update status screen.

```javascript
var invocationManager = require('net.digipresence.cardinvocation').createInvocationManager();
invocationManager.facebookShare('Hello, World');
```

## Usage
Example
```javascript
var win = Ti.UI.createWindow(),
  videoButton = Ti.UI.creteButton({
    title: 'Open YouTube video'
  });

videoButton.addEventListener('click', function() {
  var invocationManager = require('net.digipresence.cardinvocation').createInvocationManager();
  invocationManager.openURL('https://www.youtube.com/watch?v=49KQXTZ8NRk');
});

win.add(videoButton);
win.open();
```

## Author
- Hazem Khaled @HazemKhaled
- Big support from @pec1985

## License
I built this code as a full-time @ [Digipresence](http://digiprecense.net), code open source by Digipresence under MIT.
