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
 * SignatureField
 *
 * @file PlugPDF/SignatureField.h
 *
 * A SignatureField object represents Signature Annotation data in the PDF file.
 *
 */
@interface SignatureField : NSObject

/**
 * The title of this field.
 *
 */
@property (nonatomic, strong) NSString *title;

/**
 * The index of page this field is.
 *
 */
@property (nonatomic) NSInteger pageIdx;

/**
 * The file offset where the digest data starts in the file.
 *
 */
@property (nonatomic, strong) NSNumber* offset;

/**
 * Initializes a SignatureField object.
 *
 * @param title
 *          The title of this field.
 * @param pageIdx
 *          The index of page this field is. The index is zero-based.
 * @param offset
 *          The file offset where the digest data starts in the file.
 *
 * @return
 *          A SignatureField instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithTitle: (NSString*)title
            pageIdx: (NSInteger)pageIdx
             offset: (NSNumber*)offset;

@end
