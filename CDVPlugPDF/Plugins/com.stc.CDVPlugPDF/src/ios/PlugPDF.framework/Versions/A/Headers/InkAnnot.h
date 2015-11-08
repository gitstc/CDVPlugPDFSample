/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import "BaseAnnot.h"

/**
 * InkAnnot
 *
 * @file PlugPDF/InkAnnot.h
 *
 * A InkAnnot object represents ink annotation data in the PDF file and defines methods.
 *
 */
@interface InkAnnot : BaseAnnot

/**
 * The stroke color.
 *
 */
@property (nonatomic, strong) UIColor *color;

/**
 * The line width.
 *
 */
@property (nonatomic) CGFloat width;

/**
 * A NSArray of the CGPoint NSArray.
 *
 */
@property (nonatomic, strong) NSArray *lines;

/**
 * Initializes a InkAnnot object.
 *
 * @param color
 *          The stroke color `(red, green, blue, alpha)'.
 * @param width
 *          The line width.
 * @param lines
 *          A NSArray of the CGPoint NSArray.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A InkAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithColor: (UIColor*)color
              width: (CGFloat)width
              lines: (NSArray*)lines
            pageIdx: (NSInteger)pageIdx;

@end
