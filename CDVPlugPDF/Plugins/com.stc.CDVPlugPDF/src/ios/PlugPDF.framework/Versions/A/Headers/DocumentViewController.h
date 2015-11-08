/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import "DocumentView.h"
#import "DocumentViewControllerDelegate.h"
#import "AnnotEventDelegate.h"
#import "TextSelectionEventDelegate.h"

/**
 * PlugPDFDocumentNavigationBarMode
 *
 */
typedef NS_OPTIONS(NSUInteger, PlugPDFDocumentNavigationBarMode) {
    PlugPDFDocumentNavigationBarModeView         = 0,    //Specifies that the navigation bar displays title view and bar button items for view controller.
    //PlugPDFDocumentNavigationBarModeTitleView
    PlugPDFDocumentNavigationBarModeSearch       = 1,    //Specifies that the navigation bar displays search bar and bar button items for view controller.
    //PlugPDFDocumentNavigationBarModeSearchBar
    PlugPDFDocumentNavigationBarModeEdit         = 2     //Specifies that the navigation bar displays bar button items for edit controller.
};

/**
 * PlugPDFDocumentSearchDirection
 *
 */
typedef NS_OPTIONS(NSUInteger, PlugPDFDocumentSearchDirection) {
    PlugPDFDocumentSearchDirectionPageOnly       = 0,    //Sets to search the current page only.
    //PlugPDFDocumentSearchDirectionCurrentPageOnly
    PlugPDFDocumentSearchDirectionAllPage        = 1,    //Sets to search the all pages.
    PlugPDFDocumentSearchDirectionForwardOnly    = 2,    //Sets to search the following pages.
    //PlugPDFDocumentSearchDirectionForward
    PlugPDFDocumentSearchDirectionBackwardOnly   = 3     //Sets to search the previous pages.
    //PlugPDFDocumentSearchDirectionBackword
};

/**
 * PlugPDFDocumentMenuItem
 *
 */
typedef NS_OPTIONS(NSUInteger, PlugPDFDocumentMenuItem) {
    //PlugPDFDocumentNavigationBarModeView
    PlugPDFDocumentMenuItemClose                    = 100,    //Close
    PlugPDFDocumentMenuItemRotateView               = 101,    //Rotate or Lock View
    PlugPDFDocumentMenuItemDisplayMode              = 102,    //Display Mode
    PlugPDFDocumentMenuItemBrightness               = 103,    //Brightness
    PlugPDFDocumentMenuItemOutline                  = 104,    //Show outline table
    PlugPDFDocumentMenuItemSearch                   = 105,    //Search keyword
    PlugPDFDocumentMenuItemEdit                     = 106,    //Edit
    PlugPDFDocumentMenuItemSelectText               = 107,    //Select text
    PlugPDFDocumentMenuItemOK                       = 108,    //Check
    
    //PlugPDFDocumentNavigationBarModeSearch
    PlugPDFDocumentMenuItemBack                     = 200,    //Back to normal
    PlugPDFDocumentMenuItemSearchBackward           = 201,    //search backward
    PlugPDFDocumentMenuItemSearchForward            = 202,    //search forward
    
    //PlugPDFDocumentNavigationBarModeEdit
    PlugPDFDocumentMenuItemNote                     = 301,    //Note annotaion
    PlugPDFDocumentMenuItemInk                      = 302,    //Ink annotation
    PlugPDFDocumentMenuItemEraser                   = 303,    //Eraser tool
    PlugPDFDocumentMenuItemTextHighlight            = 304,    //Text lighlight
    PlugPDFDocumentMenuItemTextUnderline            = 305,    //Text underline
    PlugPDFDocumentMenuItemTextStrikeOut            = 306,    //Text strikeout
    
    //PlugPDFDocumentOutlineBarModeEdit
    PlugPDFDocumentMenuitemAdd                      = 401,    //add
    PlugPDFDocumentMenuItemDelete                   = 402,    //delete
    PlugPDFDocumentMenuItemDone                     = 403     //done
};

@class PlugPDFDocument;
@class NoteAnnot;
@class PlugPDFOutlineItem;

/**
 * PlugPDFDocumentViewController
 *
 * @file PlugPDF/DocumentViewController.h
 *
 * The PlugPDFDocumentViewController class provides the fundamental PDF viewer model for iOS platform.
 * You can create a custom PDF viewer class by using the PlugPDFDocument class directly and not using PlugPDFDocumentViewController at all.
 *
 */
@interface PlugPDFDocumentViewController : UIViewController

/**
 * A PlugPDFDocumentView
 *
 */
@property (nonatomic, strong) PlugPDFDocumentView *documentView;

/**
 * A PlugPDFDocument
 *
 */
@property (nonatomic, strong) PlugPDFDocument *document;

/**
 * A PlugPDFDocumentViewControllerDelegate
 *
 */
@property (nonatomic, weak) id <PlugPDFDocumentViewControllerDelegate> documentViewControllerDelegate;

/**
 * A PlugPDFAnnotEventDelegate
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
 * Enable / Disable Annotation Menu From NavigationBar.
 * YES is show the Annotation Menu, NO is hide the Annotation Menu.
 * The default value is YES;
 *
 */
@property (nonatomic) BOOL enableAnnotationMenu;

/**
 * Enable / Disable Search Menu From NavigationBar.
 * YES shows the Search Menu, NO hides the Search Menu.
 * The default value is YES;
 *
 */
@property (nonatomic) BOOL enableSearchMenu;

/**
 * Enable / Disable Note Annotation.
 * The default value is YES;
 *
 */
@property (nonatomic) BOOL enableAnnotNote;

/**
 * Enable / Disable Ink Annotation.
 * The default value is YES;
 *
 */
@property (nonatomic) BOOL enableAnnotInk;

/**
 * Enable / Disable Tool Bar. (Buttom Bar)
 * The default value is YES
 *
 */
@property (nonatomic) BOOL enableBottomBar;

/**
 * Enable / Disable Too Bar. (Top bar)
 * The degault value is YES
 *
 */
@property (nonatomic) BOOL enableTopBar;

/**
 * Enable / Disable using default back button in the navigation bar.
 * YES shows the default back button with title text of the previous view controller, 
 * NO use the image back button of the PlugPDF SDK.
 * The default value is NO;
 *
 */
@property (nonatomic) BOOL enableDefaultBackButton;

/**
 * Enable / Disable thumbnailPageNumber indicator.
 *
 */
@property (nonatomic) BOOL enableThumbnailPageNumberIndicator;

/**
 * Enable / Disable thumbnail image indicator.
 *
 */
@property (nonatomic) BOOL enableThumbnailPageIndicator;

/**
 * Enable / Disable page index indicator.
 *
 */
@property (nonatomic) BOOL enablePageIndicator;

/**
 * The type how to fit the page on the scrren.
 *
 */
@property (nonatomic) PlugPDFPageFitType fitType;

/**
 * Enable / Disable navigationToolbar always visible.
 * The default value is NO;
 *
 */
@property (nonatomic) BOOL enableAlwaysVisible;

#pragma mark - navigation & tool bar

/**
 * Enable / Disable Statusbar always visible.
 * The default value is NO;
 *
 */
@property (nonatomic) BOOL enableStatusBar;

/**
 * return true when document view's dealloc is called
 *
 */
@property (nonatomic) BOOL deallocIsCalled;

/**
 * Enable / Disable ResetZoom after end of search.
 *
 */
@property (nonatomic) BOOL enableResetZoomAfterSearching;

/**
 * The Title Label of PlugPDFDocumentViewController.

 ex) You can change the title of navigationController using these sample code,
 
    viewController.menuItemTitle = [[UILabel alloc] initWithFrame: CGRectMake(0, 0, 100, 15)];
    [viewController.menuItemTitle setBackgroundColor: [UIColor greenColor]];
    [viewController.menuItemTitle setTextColor: [UIColor whiteColor]];
    [viewController.menuItemTitle setFont: [UIFont systemFontOfSize: 14.0]];
    [viewController.menuItemTitle setUserInteractionEnabled: NO];
 */
@property (nonatomic) UILabel *menuItemTitle;

/**
 * Sets the navigation bar mode value and contents of navigation bar items.
 *
 * @param mode
 *          The mode value is one of the values available in the "PlugPDFDocumentNavigationBarMode" enumeration.
 *
 */
- (void)setNavigationBar: (PlugPDFDocumentNavigationBarMode)mode;

/**
 * Sets whether the navigation bar is hidden.
 *
 * @param  hidden
 *          Specify YES to hide the navigation bar or NO to show it.
 *
 */
- (void)setNavigationToolBarHidden: (BOOL)hidden;

/**
 * Returns a boolean value that determines whether the navigation bar is hidden.
 *
 */
- (BOOL)isNavigationBarHidden;

/**
 * Returns a boolean value that whether navigation bar button items are for edit.
 *
 */
- (BOOL)isNavigationBarModeEdit;

/**
 * Sets navigation bar button items.
 *
 * @param items
 *          A NSArray object of the NSInteger value. Each value is one of the values available in the "PlugPDFDocumentNavigationBarMode" enumeration.
 */
- (void)setMenuItems: (NSArray*)items;

/**
 * Sets navigation bar button items. Especially Edit menu to normal menu.
 *
 *
 * @param items
 *          A NSArray object of the NSInteger value. Each value is one of the values available in the "PlugPDFDocumentNavigationBarMode" enumeration.
 */
- (void)setEditMenuItems: (NSArray*)items;

/**
 * Adds UIBarButtonItem to the right side of the default LeftBarButtonItems.
 *
 * @param item
 *          A UIBarButtonItem object to add.
 *
 */
- (void)addLeftBarButtonItem: (UIBarButtonItem*)item;

/**
 * Adds UIBarButtonItem to the left side of the default RightBarButtonItems.
 *
 * @param item
 *          A UIBarButtonItem object to add.
 *
 */
- (void)addRightBarButtonItem: (UIBarButtonItem*)item;

/**
 * Sets the navigation bar image
 *
 * @param path
 *          The path of the accessible image file for navigation bar.
 *
 */
- (void)setNavigationBarImage: (NSString*)path;

/**
 * Sets the background image of the bar button items on the navigation bar.
 *
 * @param path
 *          The path of the accessible image file for background.
 *
 */
- (void)setBarButtonItemBackgroundImage: (NSString*)path;

/**
 * Sets the image on normal and highlight state of the bar button items on the navigation bar.
 *
 * @param item
 *          The item is one of the values available in the "PlugPDFDocumentMenuItem" enumeration.
 *          All values except 'PlugPDFDocumentMenuItemRotateView' and 'PlugPDFDocumentMenuItemDisplayMode' are available in this method.
 * @param normal
 *          The path of the accessible image file for normal state.
 * @param highlight
 *          The path of the accessible image file for highlighted and selected state.
 *
 */
- (void)setBarButtonItemImage: (PlugPDFDocumentMenuItem) item
                       normal: (NSString*)normal
                    highlight: (NSString*)highlight;

/**
 * Sets the normal and highlight state images and images for popover list items of the 'PlugPDFDocumentMenuItemRotateView' and 'PlugPDFDocumentMenuItemDisplayMode' bar button items on the navigation bar.
 *
 * @param item
 *          The item is one of the values available in the "PlugPDFDocumentMenuItem" enumeration.
 *          Only 'PlugPDFDocumentMenuItemRotateView' and 'PlugPDFDocumentMenuItemDisplayMode' are available in this method.
 * @param normals
 *          A NSArray object contains the path of the accessible image file for normal state.
 *          PlugPDFDocumentMenuItemRotateView item needs 2 images for 'rotate' and 'rotate lock'.
 *          PlugPDFDocumentMenuItemDisplayMode item needs 3 images for 'horizontal', 'vertical', and 'thumbnail'.
 * @param highlights
 *          A NSArray object contains the path of the accessible image file for highlighted and selected state.
 *          PlugPDFDocumentMenuItemRotateView item needs 2 images for 'rotate' and 'rotate lock'.
 *          PlugPDFDocumentMenuItemDisplayMode item needs 3 images for 'horizontal', 'vertical', and 'thumbnail'.
 * @param items
 *          A NSArray object contains the path of the accessible image file for the images on the popover list.
 *          PlugPDFDocumentMenuItemRotateView item needs no items, nil is good for it.
 *          PlugPDFDocumentMenuItemDisplayMode item needs 3 images for 'horizontal', 'vertical', and 'thumbnail'.
 *
 */
- (void)setBarButtonItemImages: (PlugPDFDocumentMenuItem) item
                       normals: (NSArray*)normals
                    highlights: (NSArray*)highlights
                         items: (NSArray*)items;

#pragma mark - rotation

/**
 * Sets whether the view controller's contents should rotate.
 *
 * @param lock
 *          YES if the content should rotate, otherwise NO. Default value is NO.
 *
 */
- (void)setRotationLock: (BOOL)lock;

#pragma mark - brightness

/**
 * Sets the brightness level of the document page view.
 *
 * @param brightness
 *          The value should be a number between 0 and 100, inclusive.
 *
 */
- (void)setDisplayBrightness: (NSInteger)brightness;

#pragma mark - zoom

/**
 * Returns the floating-point of the current scale factor applied to the scroll view's content. The minimum value is 1.0 and maximum is 6.0.
 *
 */
- (CGFloat)zoomScale;

/**
 * Returns the minimun zoom scale factor of the scroll view.
 *
 */
- (CGFloat)minZoomScale;

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

/**
 *
 * Sets a option to prevent a zoom or not
 *
 * @param enableZoom
 *          YES if zoom is prevented, No if zoom is permited.
 *
 */
- (void)setDisableZoom: (BOOL)disableZoom;

#pragma mark - page

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
 * Sets the page number indicator label text to "page index / page count" format.
 * 
 * @param pageIdx
 *          The index of the page you want to set. The index is zero-based.
 *
 */
- (void)setPageIndicatorText: (NSInteger)pageIdx;

/**
 * Sets visibility of the thmubnail view on the page slider.
 *
 * @param hidden
 *          Specify YES to hide the thumbnail view or NO to show it.
 *
 */
- (void)setThumbnailHidden: (BOOL)hidden;

/**
 * Sets the thumbnail image of the thmubnail view on the page slider.
 *
 * @param pageIdx
 *          The index of the page you want to set. The index is zero-based.
 *
 */
- (void)setThumbnailPage: (NSInteger)pageIdx;

/**
 * @retruns BOOL whther thumbnial image is loaded or not.
 *
 */
- (BOOL)thumbnailImageViewDidLoad;

/**
 * Moves slider at the pageIdx position.
 *
 * @param pageIdx
 *          The index of the page you want to set. The index is zero-based.
 *
 */
- (void)setPageSliderValue: (NSInteger)pageIdx;

/**
 * Returns the number of pages in entire document.
 *
 */
- (NSInteger)pageCount;

/**
 * Returns The index of current display page. The index is zero-based.
 *
 */
- (NSInteger)pageIdx;

/**
 *
 * Sets a opton to shows the image inversed.
 *
 * @param enableNightMdoe
 *          YES if image is inversed, NO if image is common.
 *
 */
- (void)setEnableNightMode: (BOOL)enableNightMode;

#pragma mark - mode

/**
 * Sets document display mode value.
 *
 * @param mode
 *          The mode value is one of the values available in the "PlugPDFDocumentDisplayMode" enumeration.
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
 * Searches string and displays the hit view on the page if there is a matching element.
 *
 * @param keyword
 *          The string you want to find.
 * @param pageIdx
 *          The index of the page you want to search. The index is zero-based.
 * @param direction
 *          The direction is one of the values available in the "PlugPDFDocumentSearchDirection" enumeration.
 *
 */
- (void)search: (NSString*)keyword
       pageIdx: (NSInteger)pageIdx
     direction: (PlugPDFDocumentSearchDirection)direction;

/**
 * Stops the current searching and deletes the hit views on any page view.
 *
 */
- (void)stopSearch;

/**
 * Returns the current or starting search text of UISearchBar.
 *
 */
- (NSString*)searchBarText;

#pragma mark - tool & edit

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
 * note icon image
 *
 */
@property (nonatomic) UIImage* noteIcon;

/**
 * Shows text highlight tool edit view.
 *
 */
- (void)showTextHighlightToolEditView;

/**
 * Sets the color of text highlight tool.
 *
 * @param color
 *          The UIColor object of the line you want to draw.
 *
 */
- (void)setTextHighlightToolColor: (UIColor*)color;

/**
 * Shows text underline tool edit view.
 *
 */
- (void)showTextUnderlineToolEditView;

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
 * Shows text strikeout tool edit view.
 *
 */
- (void)showTextStrikeoutToolEditView;

/**
 * Sets the color of text strikeout tool.
 *
 * @param color
 *          The UIColor object of the line you want to draw.
 *
 */
- (void)setTextStrikeoutToolColor: (UIColor*)color;



/**
 * Shows note tool edit view. You can set title and contents.
 *
 * @param annot
 *          The NoteAnnot instance you want to edit.
 *
 */
- (void)showNoteAnnotEditView: (NoteAnnot*)annot;

/**
 *
 * Shows bright sldier view.
 *
 */
- (void)showBrightSldierView: (id)sender;

/**
 *
 * Shows Display select view.
 *
 */
- (void)showDisplaySelectView:(id)sender;

/**
 * Shows ink tool settings view. You can set line color, clarity, width and to a straight.
 *
 */
- (void)showInkToolSettingsView;

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
 * Sets line color of ink tool.
 *
 * @param straight
 *          YES if it should be straight line. No if it should be scribbles.
 *
 */
- (void)setInkToolLineStraight: (BOOL)straight;

/**
 * Shows eraser tool settings view. You can set width and to a partial deletion.
 *
 */
- (void)showEraserToolSettingsView;

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

#pragma mark - outline

/**
 * Displays the outline table view using animation.
 *
 */
- (void)showOutlinesView;

/**
 * Sets the outline table view is hidden, optionally animating the transition.
 *
 */
- (void)hideOutlinesView;

/**
 * Removes the passed outline item in the table view and PDF document.
 *
 * @param item
 *          The outline item you want to remome.
 *
 */
- (void)removeOutlineItem: (PlugPDFOutlineItem*)item;

/**
 * Edits the title and pageIdx of the passed outline item.
 *
 * @param item
 *          The outline item you want to edit.
 * @param title
 *          The new title string.
 * @param pageIdx
 *          The new destination page index. The index is zero-based.
 *
 */
- (void)editOutlineItem: (PlugPDFOutlineItem*)item
                  title: (NSString*)title
                pageIdx: (NSInteger)pageIdx;

/**
 * Adds new PlugPDFOutlineItem object with the title and pageIdx under the parent after the after.
 *
 * @param title
 *          The new title string.
 * @param pageIdx
 *          The new destination page index. The index is zero-based.
 * @param parent
 *          The parent object of the new PlugPDFOutlineItem object.
 * @param after
 *          The before object of the new PlugPDFOutlineItem object.
 *
 */
- (void)addOutlineItemWithTitle: (NSString*)title
                        pageIdx: (NSInteger)pageIdx
                         parent: (PlugPDFOutlineItem*)parent
                          after: (PlugPDFOutlineItem*)after;


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
 * Sets the border color of the link annotation.
 *
 * @param color
 *          The border color of the link annotation. The default is clear color.
 *
 */
- (void)setAnnotLinkBorderColor: (UIColor*)color;

/**
 * Sets the background color of the link annotation.
 *
 * @param color
 *          The background color of the link annotaion. The default is clear color.
 * 
 * @param opacity
 *          The opacity of background color;
 */
- (void)setAnnotLinkBackgroundColor: (UIColor*)color opacity:(CGFloat)opacity;

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

#pragma mark - annotation customize

/**
 * Circle annotation's color.
 */
@property (nonatomic) UIColor* circleAnnotColor;

 /**
 * Circle annotation's border color.
 *
 */
@property (nonatomic) UIColor* circleAnnotBorderColor;

/**
 * Circle annotation's width.
 */
@property (nonatomic) CGFloat circleAnnotwidth;

/**
 * Square annotation's color.
 *
 */
@property (nonatomic) UIColor* squareAnnotColor;

/**
 * Square annotation's border color.
 *
 */
@property (nonatomic) UIColor* squareAnnotBorderColor;

/**
 * Square annotation's width.
 *
 */
@property (nonatomic) CGFloat squareAnnotwidth;


#pragma mark - option
/**
 * Sets recently opened page as initial page of PlugPDFDocumentViewController view.
 *
 * @param enable
 *          YES if initial page is the recently opened page. No if it should be the first page.
 *
 */
- (void)setEnableUseRecentPage: (BOOL)enable;

#pragma mark - title

/**
 * Returns the navigation item's title displayed in the center of the navigation bar.
 *
 */
- (NSString*)title;

#pragma mark - flatten

/**
 * Flatten annotations.
 *
 */
- (void)flattenAnnotations;

/**
 * Flatten form fields.
 *
 * @param includeButtonField
 *          YES if you want to flatten a ButtenField, otherwise NO.
 * @param useCustomAppearance
 *          YES if you want to flatten with custom appearance, otherwise NO.
 *
 */
- (void)flattenFormFields: (BOOL)includeButtonField useCustomAppearance: (BOOL)useCustomAppearance;

#pragma mark - encrypt

/**
 * encrypts document.
 *
 * @param userPass
 *          User password you want to set.
 * @parma ownerPass
 *          Owner password you want to set.
 * @param perm
 *          User access permissions value. You can get it by 'getUserAccessPermissionsWithPrint:...' method.
 *
 * @return
 *          YES if success, otherwise NO.
 *
 */
- (BOOL)encryptUserPassword: (NSString*)userPass
              OwnerPassword: (NSString*)ownerPass
                 permission: (NSInteger)perm;

/**
 * Returns a Boolean value that indicates whether the PlugPDFDocument object is opened with the owner password.
 *
 */
- (BOOL)openWithOwnerPassword;

/**
 * Returns a Boolean value that indicates whether the PlugPDFDocument object has the print permission.
 * (Revision 2) Print the document.
 * (Revision 3) Print the document (possibly not at the highest quality level, depending on whether bit 12 is also set).
 *
 */
- (BOOL)printPermission;

/**
 * Returns a Boolean value that indicates whether the PlugPDFDocument object has the modify content permission.
 * Modify the contents of the document by operations other than modify annot, fill field, and document assembly permissions.
 *
 */
- (BOOL)modifyContentPermission;

/**
 * Returns a Boolean value that indicates whether the PlugPDFDocument object has the modify content permission.
 * (Revision 2) Copy or otherwise extract text and graphics from the document, including extracting text and graphics (in support of accessibility to disabled users or for other purposes).
 * (Revision 3) Copy or otherwise extract text and graphics from the document by operations other than the extract permission.
 *
 */
- (BOOL)copyContentPermission;

/**
 * Returns a Boolean value that indicates whether the PlugPDFDocument object has the modify annotation permission.
 * Add or modify text annotations, fill in interactive form fields, and, if bit 4 is also set, create or modify interactive form fields (including signature fields).
 *
 */
- (BOOL)modifyAnnotPermission;

/**
 * Returns a Boolean value that indicates whether the PlugPDFDocument object has the fill interactive form field permission.
 * (Revision 3 only) Fill in existing interactive form fields (including signature fields).
 *
 */
- (BOOL)fillFiledPermission;

/**
 * Returns a Boolean value that indicates whether the PlugPDFDocument object has the extract permission.
 * (Revision 3 only) Extract text and graphics (in support of accessibility to disabled users or for other purposes).
 *
 */
- (BOOL)extractPermission;

/**
 * Returns a Boolean value that indicates whether the PlugPDFDocument object has the document assembly permission.
 * (Revision 3 only) Assemble the document (insert, rotate, or delete pages and create bookmarks or thumbnail images).
 *
 */
- (BOOL)documentAssemblyPermission;

#pragma mark - save

/**
 * Saves document data to the specified location in the application sandbox.
 * The URL path to write document data to obtained from the initWithPath: method.
 * If you initialize PlugPDFDocument with initWithData: method, please save the PDF file by saveAsFile: method.
 *
 * @return
 *          YES if the save operation succeeds, otherwise NO.
 *
 * @throw IncorrectPath
 *          Thrown when the file path is not available and cannot be used.
 * @throw NoContentsModificationPermission
 *          Thrown when the modified contents of the PDF document is saved without permission to modify contents.
 * @throw NoAnnotationsModificationPermission
 *          Thrown when the modified annotations of the PDF document are saved without permission to modify annotations.
 * @throw NoFillFieldPermission
 *          Thrown when the modified fields of the PDF document are saved without permission to fill fields.
 * @throw NoDocumentAssemblyPermission
 *          Thrown when the assembled PDF document is saved without permission to document assembly.
 *
 */
- (BOOL)saveFile:(BOOL) reload;

/**
 * Encrypts and saves document data to the specified location in the application sandbox.
 * The URL path to write document data to obtained from the initWithPath: method.
 *
 * @param userPass
 *          User password you want to set.
 * @parma ownerPass
 *          Owner password you want to set.
 * @param perm
 *          User access permissions value. You can get it by 'getUserAccessPermissionsWithPrint:...' method in the PlugPDFDocument class.
 *
 * @return
 *          YES if the operation succeeds, otherwise NO.
 *
 * @throw IncorrectPath
 *          Thrown when the file path is not available and cannot be used.
 * @throw NoContentsModificationPermission
 *          Thrown when the modified contents of the PDF document is saved without permission to modify contents.
 * @throw NoAnnotationsModificationPermission
 *          Thrown when the modified annotations of the PDF document are saved without permission to modify annotations.
 * @throw NoFillFieldPermission
 *          Thrown when the modified fields of the PDF document are saved without permission to fill fields.
 * @throw NoDocumentAssemblyPermission
 *          Thrown when the assembled PDF document is saved without permission to document assembly.
 *
 */
- (BOOL)saveEncryptedFileWithUserPassword: (NSString*)userPass
                            OwnerPassword: (NSString*)ownerPass
                               permission: (NSInteger)perm;

/**
 * Saves document data to the specified location in the application sandbox.
 *
 * @param url
 *          The file URL identifying the location in the application sandbox to write the document data to.
 *
 * @return
 *          YES if the save operation succeeds, otherwise NO.
 *
 * @throw IncorrectPath
 *          Thrown when the file path is not available and cannot be used.
 * @throw NoContentsModificationPermission
 *          Thrown when the modified contents of the PDF document is saved without permission to modify contents.
 * @throw NoAnnotationsModificationPermission
 *          Thrown when the modified annotations of the PDF document are saved without permission to modify annotations.
 * @throw NoFillFieldPermission
 *          Thrown when the modified fields of the PDF document are saved without permission to fill fields.
 * @throw NoDocumentAssemblyPermission
 *          Thrown when the assembled PDF document is saved without permission to document assembly.
 *
 */
- (BOOL)saveAsFile: (NSURL*)url;

/**
 * Encrypts and saves document data to the specified location in the application sandbox.
 *
 * @param url
 *          The file URL identifying the location in the application sandbox to write the document data to.
 * @param userPass
 *          User password you want to set.
 * @parma ownerPass
 *          Owner password you want to set.
 * @param perm
 *          User access permissions value. You can get it by 'getUserAccessPermissionsWithPrint:...' method in the PlugPDFDocument class.
 *
 * @return
 *          YES if the operation succeeds, otherwise NO.
 *
 * @throw IncorrectPath
 *          Thrown when the file path is not available and cannot be used.
 * @throw NoContentsModificationPermission
 *          Thrown when the modified contents of the PDF document is saved without permission to modify contents.
 * @throw NoAnnotationsModificationPermission
 *          Thrown when the modified annotations of the PDF document are saved without permission to modify annotations.
 * @throw NoFillFieldPermission
 *          Thrown when the modified fields of the PDF document are saved without permission to fill fields.
 * @throw NoDocumentAssemblyPermission
 *          Thrown when the assembled PDF document is saved without permission to document assembly.
 *
 */
- (BOOL)saveAsEncryptedFile: (NSURL*)url
               UserPassword: (NSString*)userPass
              OwnerPassword: (NSString*)ownerPass
                 permission: (NSInteger)perm;

/**
 * Returns the specified location in the application sandbox.
 *
 */
- (NSURL*)saveFileURL;

#pragma mark - PlugPDFDocumentViewController

/**
 * Initializes and returns a PlugPDFDocumentViewController object with the passed-in url.
 * Shows UIAlertView with UIAlertViewStyleSecureTextInput if the PDF document locked with password.
 *
 * @param data
 *          The PDF data encapsulated in an NSData object.
 * @param password
 *          The pasword to unlock an encrypted document.
 * @param title
 *          The navigation item's title displayed in the center of the navigation bar.
 *
 * @return
 *          A PlugPDFDocumentViewController instance initialized with passed-in data, or nil if the object could not be initialized.
 *
 * @throw CorruptedPDF
 *          Thrown when a pass-in data or file is not PDF document or corrupted.
 * @throw PasswordMismatch
 *          Thrown when a PDF document password does not match.
 *
 */
+ (PlugPDFDocumentViewController*)initWithData: (NSData*)data
                                      password: (NSString*)password
                                         title: (NSString*)title;
/**
 * Initializes and returns a PlugPDFDocumentViewController object with the passed-in url.
 *
 * @param url
 *          The PDF url in internet.
 * @param password
 *          The pasword to unlock an encrypted document.
 * @param viewController
 *          The viewcontroller of you used.
 *
 * @param documentViewControllerDelegate
 *          if you dont' uses a documentViewControllerDelegate, just set as a nill.
 *
 * @param annotEventDelegate
 *          if you dont' uses a annotEventDelegate, just set as a nill.
 *
 * @param textSelectionEventDelegate
 *          if you dont' uses a textSelectionEventDelegate, just set as a nill.
 *
 * @parm documentViewDelegate
 *          if you dont' uses a documentViewDelegate, just set as a nill.
 *
 * @throw Failed to download
 *          Thrown when a download is failed.
 *
 */
+ (void)initWithUrl: (NSURL*)url
           password: (NSString*)password
     viewController: (UIViewController*)viewController
documentViewControllerDelegate: (id<PlugPDFDocumentViewControllerDelegate>) documentViewControllerDelegate
annotEventDelegate: (id <PlugPDFAnnotEventDelegate>) annotEventDelegate
textSelectionEventDelegate:(id<PlugPDFTextSelectionEventDelegate>) textSelectionEventDelegate
documentViewDelegate: (id <PlugPDFDocumentViewEventDelegate>) documentViewEventDelegate;

/**
 * Initializes a PlugPDFDocumentViewController object with the passed-in data.
 * Shows UIAlertView with UIAlertViewStyleSecureTextInput if the PDF document locked with password.
 *
 * @param path
 *          The path and name of the accessible PDF file.
 * @param password
 *          The pasword to unlock an encrypted document.
 * @param title
 *          The navigation item's title displayed in the center of the navigation bar.
 *
 * @return
 *          A PlugPDFDocumentViewController instance initialized with passed-in data, or nil if the object could not be initialized.
 *
 * @throw CorruptedPDF
 *          Thrown when a pass-in data or file is not PDF document or corrupted.
 * @throw PasswordMismatch
 *          Thrown when a PDF document password does not match.
 *
 */
+ (PlugPDFDocumentViewController*)initWithPath: (NSString*)path
                                      password: (NSString*)password
                                         title: (NSString*)title;

/**
 * Initializes a PlugPDFDocument object with JetStream connection information.
 *
 * @param url
 *          The url data of JetStream server encapsulated in an NSURL object.
 * @param port
 *          The port number of JetStream server connection information.
 * @param filename
 *          The PDF file name to open on JetStream server.
 * @param password
 *          The pasword to unlock an encrypted document.
 * @param title
 *          The navigation item's title displayed in the center of the navigation bar.
 *
 * @return
 *          A PlugPDFDocumentViewController instance initialized with passed-in data, or nil if the object could not be initialized.
 *
 * @throw ConnectionFailed
 *          Thrown when a connection failure has occured.
 * @throw CorruptedPDF
 *          Thrown when a pass-in data or file is not PDF document or corrupted.
 * @throw PasswordMismatch
 *          Thrown when a PDF document password does not match.
 *
 */
+ (PlugPDFDocumentViewController*)initWithJetStreamUrl: (NSURL*)url
                                                  port: (int)port
                                              filename: (NSString*)filename
                                              password: (NSString*)password
                                                 title: (NSString*)title;


/**
 *
 * refresh a documentViewController.
 *
 */
- (void) refreshView;

- (void) closeDoc;

- (void) clear: (BOOL)reload;

@end
