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
 * SoundAnnot
 *
 * @file PlugPDF/SoundAnnot.h
 *
 * A SoundAnnot object represents annotation data in the PDF file and defines methods.
 *
 */
@interface SoundAnnot : BaseAnnot

/**
 * The title of this annotation.
 *
 */
@property (nonatomic, strong) NSString* title;

/**
 * The sound data of this annotation. It is stored with AIFF file format.
 *
 */
@property (nonatomic, strong) NSData* data;

/**
 * Initializes a SoundAnnot object.
 *
 * @param rect
 *          The rect of this annotation on the page.
 * @param title
 *          The title of this annotation.
 * @param image
 *          The icon image of this annotation.
 * @param data
 *          The sound data value of this annotation. It is stored with AIFF file format.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A SoundAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithRect: (CGRect)rect
             title: (NSString*)title
             image: (UIImage*)image
              data: (NSData*)data
           pageIdx: (NSInteger)pageIdx;

@end

