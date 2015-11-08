//
//  CDVPlugPDF.m
//  CDVPlugPDF
//
//  Created by Shnoudi on 11/5/15.
//
//

#import "CDVPlugPDF.h"

@implementation CDVPlugPDF {
    BOOL didInitPDF;
    CDVPlugPDFViewController *pdfViewController;
    UINavigationController *pdfNavViewController;
}

- (void)init:(CDVInvokedUrlCommand *)command {
    self.callbackID = command.callbackId;

    @try {
        NSString *key = command.arguments[0];
        
        if(!didInitPDF){
            //PlugPDFInit((char*)[key UTF8String]);
            PlugPDFInit("8DF52E387GCCE53EEDB5F34H97D6B528G7478CG5B6GAEFCBE422FBF5");
            
            pdfViewController = [[CDVPlugPDFViewController alloc] init];
            pdfNavViewController = [[UINavigationController alloc] initWithRootViewController:pdfViewController];
            pdfNavViewController.modalPresentationStyle = UIModalTransitionStyleCoverVertical;
            
            didInitPDF = YES;
        }
        
        [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_OK] callbackId:self.callbackID];
    }
    @catch (NSException *ex) {
        [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:ex.description] callbackId:self.callbackID];
    }
}

- (void)openPDF:(CDVInvokedUrlCommand *)command {
    @try {
        /*NSDictionary *params = (NSDictionary *)command.arguments[0];
        NSString *path = params[@"path"];
        NSString *password = params[@"password"];
        NSString *title = params[@"title"];*/
        
        NSString *path = [[NSBundle mainBundle] pathForResource:@"readme" ofType:@"pdf"];
        NSString *password = @"";
        NSString *title = [[path lastPathComponent] stringByDeletingPathExtension];
        
        PlugPDFDocumentViewController *plugPDFViewController = [PlugPDFDocumentViewController initWithPath:path password:password title:title];
        
        if(plugPDFViewController == nil){
            [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Viewer Unavailable"] callbackId:self.callbackID];
            return;
        }
        
        pdfViewController.pdfViewer = plugPDFViewController;
        pdfNavViewController.modalPresentationStyle = UIModalPresentationFullScreen;
        [self.viewController presentViewController:pdfNavViewController animated:YES completion:nil];
    }
    @catch (NSException *ex) {
        [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:ex.description] callbackId:self.callbackID];
    }
}

@end
