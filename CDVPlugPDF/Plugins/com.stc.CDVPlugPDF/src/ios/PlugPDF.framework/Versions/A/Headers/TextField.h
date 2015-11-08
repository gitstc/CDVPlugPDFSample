/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import "BaseField.h"

/**
 * PlugPDFTextField
 *
 * @file PlugPDF/TextField.h
 *
 * A TextField object represents button field data in the PDF file and defines methods.
 *
 */
@interface PlugPDFTextField : PlugPDFBaseField <UITextFieldDelegate, UITextViewDelegate>

/**
 * The font data of this field.
 *
 */
@property (nonatomic, strong) UIFont *font;

/**
 * The text color.
 *
 */
@property (nonatomic, strong) UIColor *color;

/**
 * The keyboard type of this field.
 *
 */
@property (nonatomic) UIKeyboardType keyboardType;

/**
 * The padding value of the field.
 *
 */
@property (nonatomic) CGFloat padding;

/**
 * The text edit control for single line.
 *
 */
@property (nonatomic, strong) UITextField *textField;

/**
 * The text edit control for multi line.
 *
 */
@property (nonatomic, strong) UITextView *textView;

/**
 * The text field comes next in the object list.
 *
 */
@property (nonatomic, weak) PlugPDFTextField *nextOrder;

/**
 * Initializes a TextField object.
 *
 * @param title
 *          The title of this field.
 * @param rect
 *          The rect of this field on the page.
 * @param value
 *          The string value of this field.
 * @param font
 *          The font data of this field.
 * @param color
 *          The text color.
 * @param align
 *          NSTextAlignment value.
 * @param multiLine
 *          This property is set to NO by default. Setting this property to YES enable a multi-line text object.
 * @param secureText
 *          This property is set to NO by default. Setting this property to YES creates a password-style text object, which hides the text being entered.
 * @param keyboardType
 *          The keyboard type of this field.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A TextField instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithTitle: (NSString*)title
               rect: (CGRect)rect
              value: (NSString*)value
               font: (UIFont*)font
              color: (UIColor*)color
          alignment: (NSTextAlignment)align
          multiLine: (BOOL)multiLine
         secureText: (BOOL)secureText
       keyboardType: (UIKeyboardType)keyboardType
            pageIdx: (NSInteger)pageIdx;

/**
 * Sets TextField value.
 *
 */
- (void)setTextFieldValue: (NSString*)value;

@end
