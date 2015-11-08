/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import <UIKit/UIKit.h>

#import "AnnotEventDelegate.h"

@class PlugPDFDocumentView;
@class PlugPDFDocument;

typedef NS_OPTIONS(NSUInteger, ANNOT_BORDER_SYTLE) {
    ANNOT_BORDER_SYTLE_SOLID = 0,
    ANNOT_BORDER_SYTLE_DASHED,
    ANNOT_BORDER_SYTLE_BEVELED,
    ANNOT_BORDER_SYTLE_INSET,
    ANNOT_BORDER_SYTLE_UNDERLINE
};

/**
 * BaseAnnot
 *
 * @file PlugPDF/BaseAnnot.h
 *
 * A BaseAnnot object represents annotation data in the PDF file and defines methods.
 *
 */
@interface BaseAnnot : UIControl

/**
 *  The BaseAnnot event's delegate.
 *
 */
@property (nonatomic, weak) id <PlugPDFAnnotEventDelegate> delegate;

/**
 *  A PlugPDFDocumentView object.
 *
 */
@property (nonatomic, weak) PlugPDFDocumentView *documentView;

/**
 *  A PlugPDFDocument object.
 *
 */
@property (nonatomic, weak) PlugPDFDocument *document;

/**
 * The object id of this annotation.
 *
 */
@property (nonatomic) NSInteger objID;

/**
 * The rect of annotation.
 *
 */
@property (nonatomic) CGRect rect;

/**
 * The index of page this annotation is.
 *
 */
@property (nonatomic, readwrite) NSInteger pageIdx;

/**
 * The scale of annotation drawing.
 *
 */
@property (nonatomic) CGFloat scale;

/**
 * Initializes a BaseAnnot object and sets delete context menu.
 *
 * @param rect
 *          The rect of annotation.
 * @param pageIdx
 *          The index of page this annotation is. The index is zero-based.
 *
 * @return
 *          A BaseAnnot instance, or nil if the object could not be initialized.
 *
 */
- (id)initWithRect: (CGRect)rect pageIdx: (NSInteger)pageIdx;

/**
 * Returns the scale of annotation drawing.
 *
 * @param frame
 *          A CGRect value of the superview frame.
 *
 * @return 
 *          A CGFloat value, or 0.0 if documentView is not set
 *
 */
- (CGFloat)getScale: (CGRect)frame;

/**
 * Called when an annotation is tapped up.
 *
 * @param sender
 *          A UITapGestureRecognizer instance.
 *
 * @return 
 *          YES if the PlugPDFAnnotEventDelegate returns YES; otherwise NO to do the default tap action.
 *
 */
- (BOOL)onTapUp: (id)sender;

/**
 * Called when an annotation is long pressed.
 *
 * @param sender
 *          A UILongPressGestureRecognizer instance.
 *
 * @return
 *          YES if the PlugPDFAnnotEventDelegate returns YES; otherwise NO to do the default long pressed action.
 *
 */
- (BOOL)onLongPress: (id)sender;

/**
 * Shows delete context menu.
 *
 */
- (void)showContextMenu;

/**
 * Cloase context menu.
 *
 */
- (void)onCloseContextMenu: (id)sender;

/**
 * Deletes this annotation.
 *
 */
- (void)onContextMenuDelete: (id)sender;

/**
 * Removes annotation from pdf document and page view.
 *
 */
- (void)removeAnnot;

/**
 * Saves annotation.
 *
 */
- (void)saveAnnot;

- (CGRect) annotFrameRect: (CGRect) superViewFrame;
@end
