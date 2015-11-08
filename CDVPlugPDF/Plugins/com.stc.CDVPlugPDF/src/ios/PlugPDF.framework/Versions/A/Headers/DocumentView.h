/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import "PageView.h"
#import "BaseField.h"
#import "AnnotEventDelegate.h"
#import "TextSelectionEventDelegate.h"
#import "DocumentViewEventDelegate.h"
#import "DocumentViewDelegate.h"
#import "CheckBoxFieldDrawDelegate.h"
#import "NoteAnnot.h"
/**
 * PlugPDFDocumentDisplayMode
 *
 */
typedef NS_OPTIONS(NSUInteger, PlugPDFDocumentDisplayMode) {
    PlugPDFDocumentDisplayModeHorizontal     = 0,    //Displays one page per screen at the center of the screen on the horizontal scroll view.
    PlugPDFDocumentDisplayModeVertical       = 1,    //Displays pages continuously on the non-paging vertical scroll view.
    PlugPDFDocumentDisplayModeThumbnail      = 2,    //Displays thumbnail image on the table view.
    PlugPDFDocumentDisplayModeEBook          = 3,    //Displays two pages per screen and it scrolles horizontally.
    PlugPDFDocumentDisplayModeEBookVertical  = 4,    //Displays two pages per screen and it scrolles verically.
    PlugPDFDocumentDisplayModeEBookCover     = 5     //Displays two pages per screen but first page(cover) is displayed as one page.
};


@class PlugPDFDocumentViewController;
@class PlugPDFDocument;
@class PlugPDFPageView;

/**
 * PlugPDFDocumentView
 *
 * @file PlugPDF/DocumentView.h
 *
 * The PlugPDFDocumentView class provides the fundamental PDF view for iOS platform.
 *
 */
@interface PlugPDFDocumentView : UIScrollView <UITableViewDataSource, UIPageViewControllerDelegate, UIPageViewControllerDataSource>

/**
 * A PlugPDFAnnotEventDelegate.
 *
 */
@property (nonatomic, weak) id <PlugPDFAnnotEventDelegate> annotEventDelegate;

/**
 * A PlugPDFTextSelectionEventDelegate.
 *
 */
@property (nonatomic, strong) id<PlugPDFTextSelectionEventDelegate> textSelectionEventDelegate;

/**
 * A PlugPDFDocumentViewEventDelegate.
 *
 */
@property (nonatomic, weak) id <PlugPDFDocumentViewEventDelegate> documentViewEventDelegate;

/**
 * A PlugPDFDocumentViewController.
 *
 */
@property (nonatomic, weak) PlugPDFDocumentViewController *documentViewController;

/**
 * A PlugPDFDocument.
 *
 */
@property (nonatomic, strong) PlugPDFDocument *document;

/**
 * The index of the page which is displayed.
 *
 */
@property (nonatomic) NSInteger pageIdx;

/**
 * The type how to fit the page on the scrren.
 *
 */
@property (nonatomic) PlugPDFPageFitType fitType;

/**
 * The flag of the page whether zoomed or not.
 *
 */
@property (nonatomic) BOOL zoomFlag;

/**
 *
 * The array of the pages that documentView has.
 *
 */
@property (nonatomic) NSMutableArray* pages;

/**
 *
 * The flag of the releasePage is called or not.
 *
 */
@property (nonatomic) BOOL releasePageisCalled;

/**
 * Initializes a PlugPDFDocumentView object with the passed-in data.
 *
 * @param frame
 *          The frame rectangle for the view.
 * @param document
 *          A PlugPDFDocument instance.
 * @param delegate
 *          A PlufPDFDocumentViewDelegate
 *
 * @return
 *          A PlugPDFDocumentView instance initialized with passed-in data, or nil if the object could not be initialized.
 *
 */
- (id)initWithFrame: (CGRect)frame
           document: (PlugPDFDocument*)document
           delegate: (PlugPDFDocumentViewDelegateBase*) delegate;

/**
 * Sets PlugPDFDocumentViewDelegate instance.
 *
 * @param delegate
 *          A PlugPDFDocumentViewDelegateBase class instance.
 *
 */
- (void)setDocumentViewDelegate: (PlugPDFDocumentViewDelegateBase*)delegate;

#pragma mark - content

/**
 * Sets UIScrollview content inset, size and offset.
 *
 * @param frame
 *          The frame rectangle for the view.
 *
 */
- (void)setContentWithFrame: (CGRect)frame;

/**
 * Returns the page index on PlugPDFDocumentDisplayModeHorizontal or PlugPDFDocumentDisplayModeVertical mode.
 *
 */
- (NSInteger)pageIdxWithContentOffset;

#pragma mark - zoom

/**
 *
 * @param scale
 *          the scale of the view.
 */
- (void) setZoom: (CGFloat)scale;

/**
 * Returns the current scale factor applied to the scroll view's content.
 *
 */
- (CGFloat)zoomScale;

/**
 * Returns the scale factor applied to the scroll view's content at the point.
 *
 */
- (CGFloat)zoomScale: (CGPoint)point;

/**
 * Returns the minimun zoom scale factor of the scroll view.
 *
 */
- (CGFloat)minZoomScale;

/**
 * Returns the minimun zoom scale factor of the scroll view at the point.
 *
 */
- (CGFloat)minZoomScale: (CGPoint)point;

/**
 * Returns the maximun zoom scale factor of the scroll view.
 *
 */
- (CGFloat)maxZoomScale;

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

#pragma mark - page

/**
 * Returns the number of pages in the document.
 *
 */
- (NSInteger)pageCount;

/**
 * Sets the page of given index to current page and displays at the scale fit to screen or current scale.
 *
 * @param pageIdx
 *          The index of the page you want to display. The index is zero-based.
 * @param fitToScreen
 *          YES to animate the page transition to the scale of screen, No to make the transition to the current scale.
 *
 */
- (void)gotoPage: (NSInteger)pageIdx fitToScreen: (BOOL)fitToScreen;

/**
 * Retuens the page view of given page index.
 *
 * @param pageIdx
 *          The index of the page you want to get. The index is zero-based.
 *
 * @return
 *          A PlugPDFPageView instance if pageIdx is in subviews. otherwise Nil.
 *
 */
- (PlugPDFPageView*)pageView: (NSInteger)pageIdx;

/**
 * Releases all the page view in the subview array.
 *
 */
- (void)releasePages;

- (void)releaseInvisiblePage: (NSInteger)pIdx;

/**
 *
 * Sets a opton to shows the image inversed.
 *
 * @param enableNightMdoe
 *          YES if image is inversed, NO if image is common.
 *
 */
- (void)setEnableNightMode: (BOOL)enableNightMode;

/**
 *
 * Sets a PDF's resoultion.
 *
 * @param resolution
 *         Value of PDF's resolution MAX is 3 and value must be positive. (default is 2)
 */
- (void)setResolutionQuality: (float)resolution;

- (float)getResolution;

#pragma mark - mode

/**
 * Sets the mode of the document view.
 *
 * @param mode
 *          The PlugPDFDocumentDisplayMode value.
 *
 */
- (void)setDisplayMode: (PlugPDFDocumentDisplayMode)mode;

/**
 * Returns the current page display mode value that is one of the values available in the "PlugPDFDocumentDisplayMode" enumeration.
 *
 * @return
 *          The mode value is one of the values available in the "PlugPDFDocumentDisplayMode" enumeration.
 *
 */
- (PlugPDFDocumentDisplayMode)displayMode;

/**
 * Returns the last page display mode value that is one of the values available in the "PlugPDFDocumentDisplayMode" enumeration.
 *
 */
- (PlugPDFDocumentDisplayMode)lastDisplayMode;

/**
 * Sets enable the page flip effect in the PlugPDFDocumentDisplayModeHorizontal mode.
 *
 * @param enable
 *          YES to show the page flip effect, NO to hide the page flip effect.
 *
 */
- (void)setEnablePageFlipEffect: (BOOL)enable;

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

#pragma mark - edit

- (PlugPDFTool)tool;

/**
 * Save a data about Editing.
 *
 */
- (void)saveNote: (NoteAnnot*) note;

/**
 * Release all annotation tools.
 *
 */
- (void)releaseTools;

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

/**
 * Sets the color of text highlight tool.
 *
 * @param color
 *          The UIColor object of the line you want to draw.
 *
 */
- (void)setTextHighlightToolColor: (UIColor*)color;

/**
 * Sets the color of text underline tool.
 *
 * @param color
 *          The UIColor object of the line you want to draw.
 *
 */
- (void)setTextUnderlineToolColor: (UIColor*)color;

/**
 * Sets line shape of text underline tool.
 *
 * @param squiggly
 *          YES if it should be squiggly line. No if it should be straight.
 *
 */
- (void)setTextUnderlineToolSquiggly: (BOOL)squiggly;

/**
 * Sets the color of text strikeout tool.
 *
 * @param color
 *          The UIColor object of the line you want to draw.
 *
 */
- (void)setTextStrikeoutToolColor: (UIColor*)color;

/**
 * Sets line color of ink tool.
 *
 * @param color
 *          The UIColor object of the line you want to draw.
 *
 */
- (void)setInkToolLineColor: (UIColor*)color;

/**
 * Sets line width of ink tool.
 *
 * @param width
 *          The width of the line you want to draw. The value should be a number between 1 and 50, inclusive.
 *
 */
- (void)setInkToolLineWidth: (CGFloat)width;

/**
 * Sets line shape of ink tool.
 *
 * @param straight
 *          YES if it should be straight line. No if it should be scribbles.
 *
 */
- (void)setInkToolLineStraight: (BOOL)straight;

/**
 * Sets the size of annotation eraser tool.
 *
 * @param size
 *          The size fo the area to erase. The value should be a number between 10 and 100, inclusive.
 *
 */
- (void)setEraserToolSize: (CGFloat)size;

/**
 * Sets the Inktool option's color.
 *
 *  @param Inks
 *          The Array of colors (Maximum size is 6.)
 *
 *          ex) NSArray* inks = [[NSArray alloc] initWithObjects:[UIColor blackColor], [UIColor whiteColor] [UIColor redColor], nil]; // if you want to use a only 2 colors.
 *
 */
- (void)setInkOptionToolColors: (NSArray*)inks;

/**
 * Sets the Inktool option's color image.
 *
 *  @param images
 *          The Array of colors image (Maximum size is 6.)
 */
- (void)setInkOptionToolColorImages: (NSArray*)images;

#pragma mark - annotation

/**
 * Removes annotation of id on the page of the page index.
 *
 * @param annot
 *          The annotation object id you want to remove.
 *
 */
- (void)removeAnnot: (BaseAnnot*)annot;

/**
 * Saves annotation of id on the page of the page index.
 *
 * @param annot
 *          The annotation object id you want to save.
 *
 */
- (void)saveAnnot: (BaseAnnot*)annot;

/**
 * Returns a new NSArray object containing the BaseAnnot objects.
 *
 * @param pageIdx
 *          The index of the page which is annotation to add. The index is zero-based.
 *
 * @return
 *          A new NSArray object. Each annotation element gets added to an NSArray object as a BaseAnnot object. If there are no element, this method returns an empty array.
 *
 */
- (NSArray*)annots: (NSInteger)pageIdx;

/**
 * Imports annotations data from an XFDF file, and merges them info a PDF file.
 *
 * @param xfdf
 *          The NSURL object representing an XFDF file path.
 *
 */
- (void)importAnnotFromXFDF: (NSURL*)xfdf;

/**
 * Exports annotations data to an XFDF file.
 *
 * @param xfdf
 *          The NSURL object representing an XFDF file output path.
 *
 */
- (void)exportAnnotToXFDF: (NSURL*)xfdf;

#pragma mark - option

/**
 * Sets recently opened page as initial page of PlugPDFDocumentViewController view.
 *
 * @param enable
 *          YES if initial page is the recently opened page. No if it should be the first page.
 *
 */
- (void)SetEnableUseRecentPage: (BOOL)enable;

#pragma mark - PlugPDFDocumentView

/**
 * Initializes a PlugPDFDocument object with the passed-in data.
 *
 * @param frame
 *
 * @param path
 *          The path and name of the accessible PDF file.
 * @param password
 *          The pasword to unlock an encrypted document.
 *
 * @return
 *          A PlugPDFDocument instance initialized with passed-in data, or nil if the object could not be initialized.
 *
 * @throw CorruptedPDF
 *          Thrown when a pass-in data or file is not PDF document or corrupted.
 * @throw PasswordMismatch
 *          Thrown when a PDF document password does not match.
 *
 */
+ (PlugPDFDocumentView*)initWithFrame: (CGRect)frame
                                 path: (NSString*)path
                             password: (NSString*)password;

@end
