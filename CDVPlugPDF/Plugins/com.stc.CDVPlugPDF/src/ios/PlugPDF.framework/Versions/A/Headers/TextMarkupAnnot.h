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
 * TextMarkupAnnotType
 *
 */
typedef NS_OPTIONS(NSUInteger, TextMarkupAnnotType) {
    TextMarkupAnnotHighlight,
    TextMarkupAnnotUnderline,
    TextMarkupAnnotSquigglyUnderline,
    TextMarkupAnnotStrikeout
};

/**
 * TextMarkupAnnot
 *
 * @file PlugPDF/TextMarkupAnnot.h
 *
 * A TextMarkupAnnot object represents Text Markup Annotations data in the PDF file and defines methods.
 *
 */
@interface TextMarkupAnnot : BaseAnnot

/**
 * TextMarkupAnnotType
 *
 */
@property (nonatomic) TextMarkupAnnotType type;

/**
 * The stroke or rectangle color.
 *
 */
@property (nonatomic, strong) UIColor *color;

/**
 * Initializes a TextMarkupAnnot object.
 *
 * @param type
 *          The type of this annotation.
 * @param color
 *          The color of this annotation.
 * @param rect
 *          The rect of this field on the page.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A TextMarkupAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithType: (TextMarkupAnnotType)type
             color: (UIColor*)color
              rect: (CGRect)rect
           pageIdx: (NSInteger)pageIdx;

@end
