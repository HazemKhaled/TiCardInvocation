var win = Ti.UI.createWindow({
    backgroundColor: 'white'
  }),
  videoButton = Ti.UI.creteButton({
    title: 'Open YouTube video'
  });

videoButton.addEventListener('click', function() {
  var invocationManager = require('net.digipresence.cardinvocation').createInvocationManager();
  invocationManager.openURL('https://www.youtube.com/watch?v=49KQXTZ8NRk');
});

win.add(videoButton);
win.open();
