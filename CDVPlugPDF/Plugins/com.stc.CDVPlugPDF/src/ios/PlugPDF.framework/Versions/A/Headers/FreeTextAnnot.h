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
 * FreeTextAnnot
 *
 * @file PlugPDF/FreeTextAnnot.h
 *
 * A FreeTextAnnot object represents free text annotation data in the PDF file and defines methods.
 *
 */
@interface FreeTextAnnot : BaseAnnot

/**
 * The title of this annotation.
 *
 */
@property (nonatomic, strong) NSString *title;

/**
 * The contents of this annotation.
 *
 */
@property (nonatomic, strong) NSString *contents;

/**
 * Initializes a FreeTextAnnot object for readonly.
 *
 * @param rect
 *          The rect of this annotation on the page.
 * @param title
 *          The title of this annotation.
 * @param image
 *          The image to draw.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A FreeTextAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithRect: (CGRect)rect
             title: (NSString*)title
             image: (UIImage*)image
           pageIdx: (NSInteger)pageIdx;

@end
