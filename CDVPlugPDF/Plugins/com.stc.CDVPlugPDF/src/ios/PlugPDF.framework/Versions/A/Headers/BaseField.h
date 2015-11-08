/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import "BaseAnnot.h"
#import "FieldDefine.h"

/**
 * PlugPDFBaseField
 *
 * @file PlugPDF/BaseField.h
 *
 * A BaseField object represents form field data in the PDF file and defines methods.
 *
 */
@interface PlugPDFBaseField : BaseAnnot

/**
 * The title of this field.
 *
 */
@property (nonatomic, strong) NSString *title;

/**
 * The string value of this field.
 *
 */
@property (nonatomic, strong) NSString *value;

/**
 * Show / Hidden border.
 *
 */
@property (nonatomic) BOOL borderHidden;

/**
 * The color of the field border.
 *
 */
@property (nonatomic, strong) UIColor *borderColor;

/**
 * The color of the field mask.
 *
 */
@property (nonatomic, strong) UIColor *maskColor;

/**
 * Initializes a BaseField object.
 *
 * @param title
 *          The title of this field.
 * @param rect
 *          The rect of this field on the page.
 * @param value
 *          The string value of this field.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A BaseField instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithTitle: (NSString*)title
               rect: (CGRect)rect
              value: (NSString*)value
            pageIdx: (NSInteger)pageIdx;

/**
 * Draws mask and border with field state.
 *
 * @param rect
 *          CGRect to draw
 * @param state
 *          The field state
 *
 */
- (void)drawRect: (CGRect)rect fieldState: (PlugPDFFieldState)state;

/**
 * Clear field value.
 *
 */
- (void)clearValue;

/**
 * Returns field state.
 *
 */
- (PlugPDFFieldState)fieldState;

/**
 * Sets field state.
 *
 */
- (void)setFieldState: (PlugPDFFieldState)state;

@end
