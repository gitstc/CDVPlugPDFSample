//
//  CDVPlugPDFViewController.h
//  CDVPlugPDF
//
//  Created by Shnoudi on 11/5/15.
//
//

#import <UIKit/UIKit.h>
#import "PlugPDF/PlugPDF.h"
#import "PlugPDF/DocumentViewController.h"

@interface CDVPlugPDFViewController : UIViewController

@property (strong,nonatomic) PlugPDFDocumentViewController *pdfViewer;

@end
