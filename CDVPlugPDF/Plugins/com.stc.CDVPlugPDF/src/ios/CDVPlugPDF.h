//
//  CDVPlugPDF.h
//  CDVPlugPDF
//
//  Created by Shnoudi on 11/5/15.
//
//

#import <Cordova/CDVPlugin.h>

#import "PlugPDF/PlugPDF.h"
#import "PlugPDF/Document.h"
#import "PlugPDF/DocumentViewController.h"

#import "CDVPlugPDFViewController.h"

@interface CDVPlugPDF : CDVPlugin

@property NSString* callbackID;

- (void)init:(CDVInvokedUrlCommand *)command;
- (void)openPDF:(CDVInvokedUrlCommand *)command;

@end