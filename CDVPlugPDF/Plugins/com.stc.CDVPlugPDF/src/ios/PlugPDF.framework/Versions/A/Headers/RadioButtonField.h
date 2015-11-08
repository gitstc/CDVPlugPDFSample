/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import "CheckBoxField.h"

/**
 * PlugPDFRadioButtonField
 *
 * @file PlugPDF/RadioButtonField.h
 *
 * A RadioButtonField object represents button field data in the PDF file and defines methods.
 *
 */
@interface PlugPDFRadioButtonField : PlugPDFCheckBoxField

/**
 * The name of this radiobutton field.
 *
 */
@property (nonatomic, strong) NSString *name;

/**
 * Initializes a RadioButtonField object.
 *
 * @param title
 *          The title of this field.
 * @param name
 *          The name of this field.
 * @param rect
 *          The rect of this field on the page.
 * @param checked
 *          The boolean value whether this field is checked.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A RadioButtonField instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithTitle: (NSString*)title
               name: (NSString*)name
               rect: (CGRect)rect
            checked: (BOOL)checked
            pageIdx: (NSInteger)pageIdx;

/**
 * Adds sibling RadioButtonField.
 *
 * @param sibling
 *          A RadioButtonField instance.
 *
 */
- (void)addSibling: (PlugPDFRadioButtonField*)sibling;

/**
 * Returns a NSArray object contains the sibling RadioButtonField objects of this annotation.
 *
 */
- (NSArray*)siblings;

@end
