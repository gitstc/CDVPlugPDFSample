/****************************************************************************
 **
 ** Copyright (C) 2014 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import <UIKit/UIKit.h>

@class BaseAnnot;
@class PlugPDFTextField;

/**
 * PlugPDFAnnotEventDelegate
 *
 * @file PlugPDF/AnnotEventDelegate.h
 *
 */
@protocol PlugPDFAnnotEventDelegate <NSObject>
@optional

/**
 * Called when an annotation is tapped up.
 *
 * @param viewController
 *          A UIViewController instance.
 * @param annot
 *          The annotation which is tapped up.
 *
 * @return
 *          YES if the PlugPDFAnnotEventDelegate to execute custom action only; otherwise NO with the default tap action.
 *
 */
- (BOOL)viewController: (UIViewController*)viewController
               onTapUp: (BaseAnnot*)annot;

/**
 * Called when an annotation is long pressed.
 *
 * @param viewController
 *             A UIViewController instance.
 * @param annot
 *          The annotation which is long pressed.
 *
 * @return
 *          YES if the PlugPDFAnnotEventDelegate to execute custom action only; otherwise NO with the default long pressed action.
 *
 */
- (BOOL)viewController: (UIViewController*)viewController
           onLongPress: (BaseAnnot*)annot;

/**
 * Called when an textfield to resign focus.
 *
 * @param textfield
 *          The textfield to resign first responder status.
 *
 * @return
 *          YES if the PlugPDFAnnotEventDelegate to execute custom action only; otherwise NO with the default action.
 *
 */
- (BOOL)textFieldShouldEndEditing: (PlugPDFTextField*)textField;

/**
 * Called when an textfield to change text value.
 *
 * @param textfield
 *          The textfield containing the text.
 * @param range
 *          The range of characters to be replaced.
 * @param string
 *          The replacement string.
 *
 * @return
 *          YES if the PlugPDFAnnotEventDelegate to execute custom action only; otherwise NO with the default action.
 *
 */
- (BOOL)textField: (PlugPDFTextField*)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

/**
 * Called immediately prior to the display of the keyboard.
 *
 * @param textfield
 *          The textfield becomes first responder.
 * @param offset
 *          The height offset from PlugPDFDocumentView to textfield.
 * @param notification
 *          The NSNotification object from UIKeyboardWillShowNotification
 *
 */
- (void)keyboardWillShow: (PlugPDFTextField*)textField fieldOffset: (CGFloat)offset Notification: (NSNotification*)notification;

/**
 * Called immediately prior to the dismissal of the keyboard.
 *
 * @param textfield
 *          The textfield resigns first responder.
 * @param offset
 *          The height offset from PlugPDFDocumentView to textfield.
 * @param notification
 *          The NSNotification object from UIKeyboardWillHideNotification
 *
 */
- (void)keyboardWillHide: (PlugPDFTextField*)textField fieldOffset: (CGFloat)offset Notification: (NSNotification*)notification;

@end
