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
 * SquareAnnot
 *
 * @file PlugPDF/SquareAnnot.h
 *
 * A SquareAnnot object represents square annotation data in the PDF file.
 *
 */
@interface SquareAnnot : BaseAnnot

/**
 * The color that is used to fill the square.
 *
 */
@property (nonatomic, strong) UIColor *fillColor;

/**
 * The color of the square’s border. 
 *
 */
@property (nonatomic, strong) UIColor *borderColor;

/**
 * The width of the square’s border.
 *
 */
@property (nonatomic) CGFloat borderWidth;

/**
 * The style of the square’s border.
 *
 */
@property (nonatomic) ANNOT_BORDER_SYTLE borderStyle;

/**
 * The dash pattern of the square’s border.
 *
 */
@property (nonatomic, strong) NSArray *dashPattern;

/**
 * Initializes a InkAnnot object.
 *
 * @param rect
 *          The rect of the square on the page.
 * @param fillColor
 *          The color that is used to fill the square.
 * @param borderColor
 *          The color of the square’s border.
 * @param borderWidth
 *          The width of the square’s border.
 * @param borderStyle
 *          The style of the square’s border.
 * @param dashPattern
 *          The dash pattern of the square’s border.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A SquareAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithRect: (CGRect)rect
         fillColor: (UIColor*)fillColor
       borderColor: (UIColor*)borderColor
       borderWidth: (CGFloat)borderWidth
       borderStyle: (ANNOT_BORDER_SYTLE)borderStyle
       dashPattern: (NSArray*)dashPattern
           pageIdx: (NSInteger)pageIdx;

@end
