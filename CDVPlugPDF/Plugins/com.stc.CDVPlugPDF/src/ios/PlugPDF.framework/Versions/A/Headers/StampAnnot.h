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
 * StampAnnot
 *
 * @file PlugPDF/StampAnnot.h
 *
 * A StampAnnot object represents stamp annotation data in the PDF file and defines methods.
 *
 */
@interface StampAnnot : BaseAnnot

/**
 * Initializes a StampAnnot object.
 *
 * @param rect
 *          The rect of this annotation on the page.
 * @param image
 *          The stamp image to draw.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A StampAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithRect: (CGRect)rect
             image: (UIImage*)image
           pageIdx: (NSInteger)pageIdx;

/**
 * Returns stamp image of this annotation/
 *
 */
- (UIImage*)image;

@end
