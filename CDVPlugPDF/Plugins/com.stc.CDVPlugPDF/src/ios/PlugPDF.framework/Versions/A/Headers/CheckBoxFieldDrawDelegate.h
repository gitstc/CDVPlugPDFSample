/****************************************************************************
 **
 ** Copyright (C) 2014 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import <Foundation/Foundation.h>

@class PlugPDFCheckBoxField;

/**
 * PlugPDFCheckBoxFieldDrawDelegate
 *
 * @file PlugPDF/CheckBoxFieldDrawDelegate.h
 *
 */
@protocol PlugPDFCheckBoxFieldDrawDelegate <NSObject>
@optional

/**
 * Called when an annotation is tapped up.
 *
 * @param rect
 *
 * @param field
 *          The CheckBoxField which is to draw.
 *
 */
- (void)drawRect: (CGRect)rect field: (PlugPDFCheckBoxField*)field;

@end
