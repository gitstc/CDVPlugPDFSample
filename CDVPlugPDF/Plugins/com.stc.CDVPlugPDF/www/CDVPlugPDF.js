var CDVPlugPDF = exports;

var exec    = require('cordova/exec');
var utils   = require('cordova/utils');

CDVPlugPDF.init = function (successCB,errorCB,key) {
    exec(successCB,errorCB,"CDVPlugPDF","init",[key]);
};

CDVPlugPDF.openPDF = function(successCB,errorCB,options) {
    exec(successCB,errorCB,"CDVPlugPDF","openPDF",[options]);
};