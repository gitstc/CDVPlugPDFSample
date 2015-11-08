/****************************************************************************
 **
 ** Copyright (C) 2014 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import "BaseAnnot.h"

/**
 * LinkAnnot
 *
 * @file PlugPDF/LinkAnnot.h
 *
 * A BaseAnnot object represents annotation data in the PDF file and defines methods.
 *
 */
@interface LinkAnnot : BaseAnnot

/**
 * The Destination string is defined as below <ACTION>:[PATH]:[PAGE_NUMBER] Supported ACTION types are URI, GoTo, Launch and GoToR.
 * For GoTo action, [PATH] is not used. In the case of GoTo and GoToR, PAGE_NUMBER is specified.
 * URI: Resolve a uniform resource identifier at PATH. GoTo: Go to PAGE_NUMBER in the current document. 
 * Launch: Launch an application, usually to open a file at PATH. GoToR: (“Go-to remote”) Go to PAGE_NUMBER in another document at PATH. Named: Named actions(PDF 1.2).
 * For detailed information, please refer PDF Refernce documentation.
 *
 */
@property (nonatomic, copy) NSString *destination;

/**
 * Initializes a LinkAnnot object.
 *
 * @param destination
 *          The destination string.
 * @param rect
 *          The rect of the link annotation on the page.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A LinkAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithDest: (NSString*)destination
              rect: (CGRect)rect
           pageIdx: (NSInteger)pageIdx;

@end
