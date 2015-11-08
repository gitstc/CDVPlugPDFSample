/****************************************************************************
 **
 ** Copyright (C) 2014 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import <Foundation/Foundation.h>

@class PlugPDFDocumentView;

/**
 * PlugPDFDocumentViewEventDelegate
 *
 * @file PlugPDF/DocumentViewEventDelegate.h
 *
 */
@protocol PlugPDFDocumentViewEventDelegate <NSObject>
@optional

/**
 * Called when the page is about to made visible.
 *
 * @param documentView
 *          The PlugPDFDocumentView currently displayed.
 * @param pageIdx
 *          The page index will be changed. The index is zero-based.
 *
 * @return
 *          YES if the PlugPDFDocumentViewEventDelegate to execute custom action only; otherwise NO with the default action.
 *
 */
- (BOOL)pageWillChange: (PlugPDFDocumentView*)documentView pageIdx: (NSInteger)pageIdx;

/**
 * Called when the page has been changed.
 *
 * @param documentView
 *          The PlugPDFDocumentView currently displayed.
 * @param pageIdx
 *          The page index was changed. The index is zero-based.
 *
 */
- (void)pageDidChange: (PlugPDFDocumentView*)documentView pageIdx: (NSInteger)pageIdx;

/**
 * Called when the table cell of the thumbnail view has been at the specified index path.
 *
 */
- (void)thumbnailViewDidScroll: (PlugPDFDocumentView*)documentView tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

/**
 * Called when an document view is single tapped up.
 *
 * @param singleTap
 *      A UITapGestureRecognizer instance.
 *
 * if you retrun NO, default action is activated. but if you return YES, default action is ignored.
 *
 */
- (BOOL)onSingleTap: (UITapGestureRecognizer*)singleTap view:(UIView*)view;

/**
 * Called when an document view is double tapped up.
 *
 * @param doubleTap
 *      A UITapGestureRecognizer instance.
 *
 * if you retrun NO, default action is activated. but if you return YES, default action is ignored.
 *
 */
- (BOOL)onDoubleTap: (UITapGestureRecognizer*)doubleTap view:(UIView*)view;

/**
 * Called when an document view is long pressed.
 *
 * @param longPress
 *      A UILongPressGestureRecognizer instance.
 *
 * if you retrun NO, default action is activated. but if you return YES, default action is ignored.
 *
 */
- (BOOL)onLongPress: (UILongPressGestureRecognizer*)longPress view:(UIView*)view;

/**
 * Called when an document view is swiped
 *
 * @param swipe
 *      A UISwipeGestureRecognizer instance.
 *
 * if you retrun NO, default action is activated. but if you return YES, default action is ignored.
 *
 */
- (BOOL)onSwipe: (UISwipeGestureRecognizer*)swipe;

/**
 *
 * Called when an annotation is added.
 *
 * @param annot
 *      A BaseAnnot instance
 */

- (void)AnnotisAdded: (UIControl*)annot;

/**
 *
 * Called when an annotation is Removed.
 *
 * @param annot
 *      A BaseAnnot instance
 */

- (void)AnnotisRemoved: (UIControl*)annot;

@end
