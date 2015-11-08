/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import "BaseTool.h"

/**
 * PlugPDFPageFitType
 *
 */
typedef NS_OPTIONS(NSUInteger, PlugPDFPageFitType) {
    PlugPDFPageFitMinimum       = 0,    //Fits to minimum scale, but maximum is 1.0.
    PlugPDFPageFitWidth         = 1,    //Fits to width.
    PlugPDFPageFitHeight        = 2     //Fits to height.
};

@protocol PlugPDFAnnotEventDelegate;
@class PlugPDFPageViewDelegate;
@class PlugPDFDocumentView;
@class BaseAnnot;

/**
 * PlugPDFPageView
 *
 * @file PlugPDF/PageView.h
 *
 * The PlugPDFPageView class provides the fundamental PDF view for iOS platform.
 *
 */
@interface PlugPDFPageView : UIScrollView

/**
 * A PlugPDFAnnotEventDelegate.
 *
 */
@property (nonatomic, weak) id <PlugPDFAnnotEventDelegate> annotEventDelegate;

/**
 * A PlugPDFPageViewDelegate.
 *
 */
@property (nonatomic, strong) PlugPDFPageViewDelegate *pageViewDelegate;

/**
 * A PlugPDFDocumentView.
 *
 */
@property (nonatomic, weak) PlugPDFDocumentView *documentView;

/**
 * The index of the page. The index is zero-based.
 *
 */
@property (nonatomic) NSInteger pageIdx;

/**
 * The type how to fit the page on the scrren.
 *
 */
@property (nonatomic) PlugPDFPageFitType fitType;

/**
 * The image view of page.
 *
 */
@property (nonatomic, strong) UIImageView *imageView;

/**
 * The image view of the part page.
 *
 */
@property (nonatomic, strong) UIImageView *tileView;

/**
 *
 * The minimum scale of page.
 *
 */
@property (nonatomic) CGFloat minScale;

/**
 * This is tap gesture of page.
 *
 */
@property (nonatomic, strong) UITapGestureRecognizer *doubleTap;
@property (nonatomic, strong) UITapGestureRecognizer *singleTap;

/**
 * This is press gesture of page.
 *
 */
@property (nonatomic, strong) UILongPressGestureRecognizer *longPress;

/**
 * This is swipe gesture of page.
 *
 */
@property (nonatomic, strong) UISwipeGestureRecognizer *swipeLeft;
@property (nonatomic, strong) UISwipeGestureRecognizer *swipeRight;
@property (nonatomic, strong) UISwipeGestureRecognizer *swipeUp;
@property (nonatomic, strong) UISwipeGestureRecognizer *swipeDown;

/**
 * Initializes a PlugPDFDocumentView object with the passed-in data.
 *
 * @param frame
 *          The frame rectangle for the view.
 * @param documentView
 *          A PlugPDFDocumentView instance.
 * @param pageIdx
 *          The index of the page. The index is zero-based.
 * @param fitType
 *          The type how to fit the page on the scrren.
 *
 * @return
 *          A PlugPDFPageView instance initialized with passed-in data, or nil if the object could not be initialized.
 *
 */
- (id)initWithFrame: (CGRect)frame
       documentView: (PlugPDFDocumentView*)documentView
            pageIdx: (NSInteger)pageIdx
            fitType: (PlugPDFPageFitType)fitType
              scale: (CGFloat)scale
           zoomFlag:(BOOL)zoomFlag;


#pragma mark - view

/**
 * Shows the image view or the tile view.
 *
 */
- (void)showView;

/**
 * Hides the tile view on the image view.
 *
 */
- (void)setTileViewHidden;

/**
 * knows whether page's image is loaded or not.
 *
 */
- (BOOL)imageViewDidLoad;

- (void)setMImageView: (BOOL)imageView;

/**
 * knows whether page's image is loaded or not.
 *
 */
- (BOOL)tileImageViewDidLoad;

#pragma mark - zoom

/**
 * Sets the current page view at the scale fit to screen.
 *
 * @param animated
 *          YES if the scrolling should be animated. No if it should be immediate.
 *
 */
- (void)resetZoom: (BOOL)animated;

/**
 * Sets a value that specifies the current scale factor applied to the scroll view's content and scrolls a specific area of the content so that it is visible.
 *
 * @param point
 *          A point value defining an area of the content view. The point should be in the coordinatespace of the scroll view.
 * @param scale
 *          This value determines how much the content is currently scaled.
 * @param animated
 *          YES if the scrolling should be animated. No if it should be immediate.
 *
 */
- (void)zoomToPoint: (CGPoint)point scale: (CGFloat)scale animated: (BOOL)animated;

- (CGFloat)pageScale;

#pragma mark - search

/**
 * Displays the hit view.
 *
 * @param hits
 *          A NSArray object. Each hit gets added to an NSArray object as a CGRect object.
 */
- (void)showHitView: (NSArray*)hits;

/**
 * Deletes the hit views on any page view.
 *
 */
- (void)deleteHitView;

/**
 * Sets whether the hit view is hidden.
 *
 * @param hidden
 *          Specify YES to hide the hit view or NO to show it.
 *
 */
- (void)setHitViewHidden: (BOOL)hidden;

#pragma mark - edit

/**
 * Release annotation tool.
 *
 * @param tool
 *          The annotation tool you want to release on the view. The value is available in the "PlugPDFTool" enumeration.
 *
 */
- (void)releaseTool: (PlugPDFTool)tool;

/**
 * Sets annotation tool.
 *
 * @param tool
 *          The annotation tool you want to set on the view. The value is available in the "PlugPDFTool" enumeration.
 *
 */
- (void)setTool: (PlugPDFTool)tool;

/**
 * Sets annotation tool with extra value.
 *
 * @param tool
 *          The annotation tool you want to set on the view. The value is available in the "PlugPDFTool" enumeration.
 * @param value
 *          The value to initialze annotation tools.
 *
 */
- (void)setTool: (PlugPDFTool)tool withExtraValue: (NSValue*)value;

#pragma mark - annotation

/**
 * Loads annotation and adds subview  on the page of the page index.
 * You have to call this before you call 'annots:'
 *
 * @param pageIdx
 *          The index of page you want to load. The index is zero-based.
 *
 */
- (void)loadAnnots;

/**
 * Removes annotation of id on the page of the page index.
 *
 * @param annot
 *          The annotation object id you want to remove.
 *
 */
- (void)removeAnnot: (BaseAnnot*)annot;

/**
 * Adds annotation on the page.
 *
 * @param annot
 *          The annotation object id you want to add.
 *
 */
- (void)addAnnot: (BaseAnnot*)annot;

/**
 * Sets whether the annotation is hidden.
 *
 * @param  hidden
 *          Specify YES to hide the annotation or NO to show it.
 *
 */
- (void)setAnnotHidden: (BOOL)hidden;

#pragma mark - extract text

/**
 * Extracts and returns NSDictionary object contatins extraction results text and rect.
 *
 * @param rect
 *          The rect of the page you want to extract text on view; if CGRectZero extract all of the text on the page.
 * @param offset
 *          The offset point of the PlugPDFDocumentView; CGPointZero when you use the PlugPDFDocumentViewController class.
 *
 * @return
 *          The NSDictionary object contains extraction results, nil value otherwise.
 *          @"Text"; the key for getting NSString object.
 *          @"Rects"; the key for getting NSArray object contatins CGRectValue of the each character.
 *
 * @throw NoCopyContentsPermission
 *          Thrown when the copy or otherwise extraction is occurred without permission to copy contents.
 *
 */
- (NSDictionary*)extractTextAndRectsInRect: (CGRect)rect withOffset: (CGPoint)offset;

/**
 * Extracts text and returns NSString object contatins extraction results.
 *
 * @param rect
 *          The rect of the page you want to extract text on view; if CGRectZero extract all of the text on the page.
 * @param offset
 *          The offset point of the PlugPDFDocumentView; CGPointZero when you use the PlugPDFDocumentViewController class.
 *
 * @return
 *          The NSString object contains extraction results, nil value otherwise.
 *
 * @throw NoCopyContentsPermission
 *          Thrown when the copy or otherwise extraction is occurred without permission to copy contents.
 *
 */
- (NSString*)extractTextInRect: (CGRect)rect withOffset: (CGPoint)offset;

@end
