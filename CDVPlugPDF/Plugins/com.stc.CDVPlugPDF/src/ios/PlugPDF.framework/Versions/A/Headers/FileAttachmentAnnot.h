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
 * FileAttachmentAnnot
 *
 * @file PlugPDF/FileAttachmentAnnot.h
 *
 * A FileAttachmentAnnot object represents file attachment annotation data in the PDF file and defines methods.
 *
 */
@interface FileAttachmentAnnot : BaseAnnot <UIDocumentInteractionControllerDelegate>

/**
 * Initializes a FileAttachmentAnnot object.
 *
 * @param rect
 *          The rect of this annotation on the page.
 * @param image
 *          The icon image to draw.
 * @param fileName
 *          The name of the attached file.
 * @param fileData
 *          The NSData object of the attached file data.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A FileAttachmentAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithRect: (CGRect)rect
             image: (UIImage*)image
          fileName: (NSString*)fileName
          fileData: (NSData*)fileData
           pageIdx: (NSInteger)pageIdx;

@end
