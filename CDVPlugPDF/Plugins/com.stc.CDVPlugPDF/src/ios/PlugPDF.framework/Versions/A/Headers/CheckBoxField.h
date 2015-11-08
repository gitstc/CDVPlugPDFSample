/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import "BaseField.h"

#import "CheckBoxFieldDrawDelegate.h"

/**
 * PlugPDFCheckBoxField
 *
 * @file PlugPDF/CheckBoxField.h
 *
 * A CheckBoxField object represents button field data in the PDF file and defines methods.
 *
 */
@interface PlugPDFCheckBoxField : PlugPDFBaseField

/**
 * CheckBox draw delegate.
 *
 */
@property (nonatomic, weak) id <PlugPDFCheckBoxFieldDrawDelegate> drawDelegate;

/**
 * Initializes a CheckBoxField object.
 *
 * @param title
 *          The title of this field.
 * @param rect
 *          The rect of this field on the page.
 * @param checked
 *          The boolean value whether this field is checked.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A CheckBoxField instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithTitle: (NSString*)title
               rect: (CGRect)rect
            checked: (BOOL)checked
            pageIdx: (NSInteger)pageIdx;

/**
 * Sets CheckBoxField value.
 *
 * @param checked
 *          The boolean value whether this field is checked.
 *
 */
- (void)setChecked: (BOOL)checked;

/**
 * Returns the boolean value whether this field is checked.
 *
 */
- (BOOL)checked;

@end

