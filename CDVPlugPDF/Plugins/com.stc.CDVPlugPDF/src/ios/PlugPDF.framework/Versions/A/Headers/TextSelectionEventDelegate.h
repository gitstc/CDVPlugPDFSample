/****************************************************************************
 **
 ** Copyright (C) 2014 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import <UIKit/UIKit.h>

/**
 * PlugPDFTextSelectionEventDelegate
 *
 * @file PlugPDF/TextSelectionEventDelegate.h
 *
 */
@protocol PlugPDFTextSelectionEventDelegate <NSObject>
@optional

/**
 * Called when the 'copy' item on the context menu is tapped.
 *
 * @param id
 *          the UIMenuController instance.
 * @param text
 *          The selected text.
 *
 * @return
 *          YES if the PlugPDFTextSelectionEventDelegate to execute custom action only; otherwise NO with the default tap action.
 *
 */
- (BOOL)onContextMenuCopy: (id)sender withText: (NSString*)text;

/**
 * Called when the 'search' item on the context menu is tapped.
 *
 * @param id
 *          the UIMenuController instance.
 * @param text
 *          The selected text.
 *
 * @return
 *          YES if the PlugPDFTextSelectionEventDelegate to execute custom action only; otherwise NO with the default tap action.
 *
 */
- (BOOL)onContextMenuSearch: (id)sender withText: (NSString*)text;


/**
 *
 * Called when Text Select Context is showed.
 *
 * @param view
 *            the Select Context instance.
 *
 * @param rect
 *            the rect of Select Context.
 *
 */
- (void)showContextMenu: (UIView *)view rect: (CGRect)rext;

@end
