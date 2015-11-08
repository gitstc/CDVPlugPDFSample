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
 * RichMediaAnnot
 *
 * @file PlugPDF/RichMediaAnnot.h
 *
 * A RichMediaAnnot object represents annotation data in the PDF file and defines methods.
 *
 */
@interface RichMediaAnnot : BaseAnnot

/**
 * The source name of this annotation.
 *
 */
@property (nonatomic, strong) NSString* source;

/**
 * Initializes a RichMediaAnnot object.
 *
 * @param rect
 *          The rect of this annotation on the page.
 * @param image
 *          The icon image of this annotation.
 * @param source
 *          The source name of this annotation.
 * @param data
 *          The rich media data value of this annotation. It is stored with m4u file format in the temporary path.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A RichMediaAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithRect: (CGRect)rect
             image: (UIImage*)image
            source: (NSString*)source
              data: (NSData*)data
           pageIdx: (NSInteger)pageIdx;

@end

