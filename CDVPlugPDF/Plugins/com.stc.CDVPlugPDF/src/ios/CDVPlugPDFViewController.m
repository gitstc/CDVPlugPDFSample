//
//  CDVPlugPDFViewController.m
//  CDVPlugPDF
//
//  Created by Shnoudi on 11/5/15.
//
//

#import "CDVPlugPDFViewController.h"

@implementation CDVPlugPDFViewController {
    BOOL shouldClose;
}

- (id)init {
    if(self == nil){
        self = [super init];
    }
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    return self;
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    if(shouldClose) {
        shouldClose = NO;
       [self dismissViewControllerAnimated:YES completion:nil];
       return;
    }
    
    shouldClose = YES;

    [self.navigationController pushViewController:_pdfViewer animated:NO];
    if ([[UIDevice currentDevice].systemVersion hasPrefix:@"7"] ||
        [[UIDevice currentDevice].systemVersion hasPrefix:@"8"] ||
        [[UIDevice currentDevice].systemVersion hasPrefix:@"9"]) {
        [_pdfViewer setAutomaticallyAdjustsScrollViewInsets: NO];
    }
}

@end
