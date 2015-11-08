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
 * NoteAnnot
 *
 * @file PlugPDF/NoteAnnot.h
 *
 * A NoteAnnot object represents note annotation data in the PDF file and defines methods.
 *
 */
@interface NoteAnnot : BaseAnnot

/**
 * The title string.
 *
 */
@property (nonatomic, copy) NSString *title;

/**
 * The contents string.
 *
 */
@property (nonatomic, copy) NSString *contents;

/**
 * The date string of last modified.
 *
 */
@property (nonatomic, copy) NSString *date;

/**
 * The icon image.
 *
 */
@property (nonatomic, copy) UIImage *icon;

/**
 * Initializes a NoteAnnot object.
 *
 * @param title
 *          The title string.
 * @param contents
 *          The contents string.
 * @param date
 *          The date string of last modified.
 * @param icon
 *          The icon image.
 * @param rect
 *          The rect of the note annotation on the page.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A NoteAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithTitle: (NSString*)title
           contents: (NSString*)contents
               date: (NSString*)date
               icon: (UIImage*)icon
               rect: (CGRect)rect
            pageIdx: (NSInteger)pageIdx;

@end
