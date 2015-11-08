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
 * PlugPDFButtonField
 *
 * @file PlugPDF/ButtonField.h
 *
 * A ButtonField object represents button field data in the PDF file and defines methods.
 *
 */
@interface PlugPDFButtonField : PlugPDFBaseField

/**
 * Initializes a ButtonField object.
 *
 * @param title
 *          The title of this field.
 * @param rect
 *          The rect of this field on the page.
 * @param image
 *          The image to draw.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A ButtonField instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithTitle: (NSString*)title
               rect: (CGRect)rect
              image: (UIImage*)image
            pageIdx: (NSInteger)pageIdx;

/**
 * default is UIViewContentModeScaleToFill
 */
- (void)setContentMode: (UIViewContentMode)contentMode;

/**
 * Sets button image.
 *
 * @param image
 *          The UIImage value.
 *
 */
- (void)setImage:(UIImage *)image;

/**
 * Returns image value.
 *
 */
- (UIImage*)image;

@end
