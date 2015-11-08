/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import <UIKit/UIKit.h>

#import "FieldDefine.h"
#import "CheckBoxFieldDrawDelegate.h"

@class BaseAnnot;
@class SignatureField;
@class PlugPDFOutlineItem;
@class PlugPDFDocumentView;

/**
 * PlugPDFDocument
 *
 * @file PlugPDF/Document.h
 * 
 * A PlugPDFDocument object represents PDF data or a PDF file and defines methods for drawing, searching, and getting PDF data.
 *
 * You initialize a PlugPDFDocument object with PDF data or with a path string to a PDF file. You can then access document information.
 *
 */
@interface PlugPDFDocument : NSObject

/**
 * The value whether this document if modified or not.
 *
 */
@property (nonatomic) BOOL modified;

/**
 * The value whether this document on stream mode or not.
 *
 */
@property (nonatomic) BOOL onStream;

/**
 * A PlugPDFDocumentView.
 *
 */
@property (nonatomic, strong) PlugPDFDocumentView* documentView;

/**
 * Initializes a PlugPDFDocument object with the passed-in data.
 *
 * @param data
 *          The PDF data encapsulated in an NSData object.
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
- (id)initWithData: (NSData*)data password: (NSString*)password;


/**
 * Initializes a PlugPDFDocument object with the url.
 *
 * @param url
 *          The url of PDF in Internet.
 * @param password
 *          The pasword to unlock an encrypted document.
 *
 * @throw Failed to download
 *          Thrown when download is failed.
 * @return
 *          A PlugPDFDocument instance initialized with url, or nil if the object could not be initialized.
 *
 */
- (id)initWithUrl: (NSURL*)url password:(NSString*)password;

/**
 * Initializes a PlugPDFDocument object with the passed-in inputstream.
 *
 * @param data
 *          The PDF data encapsulated in an NSInputStream object.
 * @param length
 *          The length of Inputstream.
 * @param password
 *          The pasword to unlock an encrypted document.
 *
 * @return
 *          A PlugPDFDocument instance initialized with passed-in inputstream, or nil if the object could not be initialized.
 *
 * @throw CorruptedPDF
 *          Thrown when a pass-in inputstream or file is not PDF document or corrupted.
 * @throw PasswordMismatch
 *          Thrown when a PDF document password does not match.
 *
 */
- (id)initwithInputStream: (NSInputStream*)inputStream length: (NSUInteger)length password:(NSString*)password;

/**
 * Initializes a PlugPDFDocument object with the contents at the specified path.
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
- (id)initWithPath: (NSString*)path password: (NSString*)password;

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
 *
 * @return
 *          A PlugPDFDocument instance initialized with passed-in data, or nil if the object could not be initialized.
 *
 * @throw ConnectionFailed
 *          Thrown when a connection failure has occured.
 * @throw CorruptedPDF
 *          Thrown when a pass-in data or file is not PDF document or corrupted.
 * @throw PasswordMismatch
 *          Thrown when a PDF document password does not match.
 *
 */
- (id)initWithJetStreamUrl: (NSURL*)url
                      port: (NSInteger)port
                  filename: (NSString*)filename
                  password: (NSString*)password;

#pragma mark - document

/**
 * Returns the number of pages in the document.
 *
 */
- (NSInteger)pageCount;

/**
 * Returns the size of the page at a given page index.
 *
 * @param pageIdx
 *          The page index of the page you want to get size. The index is zero-based.
 *
 * @return
 *          The size of the page, or 72 x 72 if the page index is invalid.
 *
 */
- (CGSize)pageSize: (NSInteger)pageIdx;

/**
 * Creates and Returns a new UIImage object initialized with page contents fit to given size for the given page index.
 *
 * @param pageIdx
 *          The index of the page you want to draw. The index is zero-based.
 * @param size
 *          The size of the page you want to draw.
 *
 * @return 
 *          A new UIImage object, or nil if page index is invalid.
 *
 */
- (UIImage *)drawPage: (NSInteger)pageIdx size: (CGSize)size;

/**
 * Creates and Returns a new UIImage object initialized with thumbnail_page contents fit to given size for the given thumbnail_page index.
 *
 * @param pageIdx
 *          The index of the thumbnail_page you want to draw. The index is zero-based.
 * @param size
 *          The size of the thumbnail_page you want to draw.
 *
 * @return
 *          A new UIImage object, or nil if thumbnail_page index is invalid.
 *
 */
- (UIImage *)drawPage2: (NSInteger)pageIdx size: (CGSize)size;

/**
 * Creates and Returns a new UIImage object initialized with page contents in the specified rectangle and scale fit to screen size.
 *
 * @param pageIdx
 *          The index of the page you want to draw. The index is zero-based.
 * @param size
 *          The size of the page you want to draw.
 * @param tileRect
 *          The rectangle in which to draw.
 * @param zoom
 *          The scale factor to assume when interpreting the image data.
 *
 * @return 
 *          A new UIImage object, or nil if page index is invalid.
 *
 */
- (UIImage *)drawTile: (NSInteger)pageIdx
                 size: (CGSize)size
             tileRect: (CGRect)tileRect
                 zoom: (CGFloat)zoom;

/**
 * Releases the page contents of the given page index.
 *
 * @param pageIdx
 *          The index of the page you want to release contents. The index is zero-based.
 *
 */
- (void)releasePage: (NSInteger)pageIdx;

#pragma mark - watermark


/**
 * Insers a text watermark at PDF file.
 *
 * @param pages
 *          The array of pages. This contains a pagenumber to draw.
 * @param pageLen
 *          The number of pages you want to draw.
 * @param point
 *          The point where you want to draw.
 * @param zoom
 *          The Text you want to write.
 * @param size
 *          The size of text.
 * @param rotate
 *          The angle you want to rotate.
 * @param opacity
 *          The opacity of text. (if opacity is 0, text is transparent)
 */
- (void)insertTextWaterMark: (NSInteger)pages
                    pageLen:(NSInteger)pageLen
                      point:(CGPoint)point
                       text:(NSString *)text
                       size:(NSInteger)size
                     rotate:(double)rotate
                    opacity:(double)opacity;

#pragma mark - richmedia

- (void)insertVideo: (NSInteger)page
            imgPath: (NSURL*)imgPath
            imgRect: (CGRect)imgRect
          mediaPath: (NSURL*)mediaPath
          mediaSize: (CGSize)mediaSize
    videoPlayerPath: (NSURL*)videoPlayerPath;

#pragma mark - text

/**
 * Finds all instances of the specified string int the page of given page index.
 *
 * @param string
 *          The string you want to find.
 * @param pageIdx
 *          The index of the page you wnat to find specified string. The index is zero-based.
 *
 * @return 
 *          A new NSArray object. Each hit gets added to an NSArray object as a CGRect object. If there are no hits, this method returns an empty array.
 *
 */
- (NSArray*)findString: (NSString*)string page: (NSInteger)pageIdx;

/**
 * Remove all accents which is in PDF file to search.
 *
 *
 * @param int
 *         The ASCII number.
 *
 * @return
 *         A ASCII Number that Accent is removed.
 */
- (int)removeAccent: (int)asciiNum;

#pragma mark - outline

/**
 * Returns a Boolean value that indicates whether the PlugPDFDocument object contains outline data.
 *
 * @return 
 *          YES if the PlugPDFDocument object contains a outline data, otherwise NO.
 *
 */
- (BOOL)containsOutline;

/**
 * Returns a new NSArray object containing the PlugPDFOutlineItem objects. The order is in the ascending order of page indexes of outlien data.
 *
 * @return 
 *          A new NSArray object. Each outline element gets added to an NSArray object as a PlugPDFOutlineItem object. If there are no element, this method returns an empty array.
 *
 */
- (NSArray*)outlines;

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

/**
 * Adds a PlugPDFOutlineItem Tree using a PlugPDFOutlineItem Item array.
 * 
 *   @param itemArray
 *             The array of PlugPDFOutlineItem. element must be PlugPDFOutlineItem.
 *
 */
- (void)updatePdfOutlineTree: (NSArray*)itemArray;

#pragma mark - search

/**
 *
 * A option Property to exclude a Accent when search.
 *
 */
@property (nonatomic) bool enableExcludeAccentWhenSearch;

#pragma mark - annotation

/**
 * Loads annotation on the page of the page index.
 * You have to call this before you call 'annots:'
 *
 * @param pageIdx
 *          The index of page you want to load. The index is zero-based.
 *
 */
- (void)loadAnnots: (NSInteger)pageIdx;

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
 * Imports annotations data from an XFDF file, merges them info the src PDF file, and saves as dest PDF file.
 *
 * @param xfdf
 *          The NSURL object representing an XFDF file path.
 * @param src
 *          The NSURL object representing an PDF file path to merge.
 * @param password
 *          The password of the source PDF file.
 * @param dest
 *          The NSURL object representing an PDF file path to save as.
 *
 */
+ (void)importAnnotFromXFDF: (NSURL*)xfdf
                    srcPath: (NSURL*)src
                   password: (NSString*)password
                   destPath: (NSURL*)dest;

/**
 * Exports annotations data to an XFDF file.
 *
 * @param xfdf
 *          The NSURL object representing an XFDF file output path.
 *
 */
- (void)exportAnnotToXFDF: (NSURL*)xfdf;

/**
 * Exports annotations data from an PDF file, and saves as dest XFDF file.
 *
 * @param xfdf
 *          The NSURL object representing an XFDF file output path.
 * @param src
 *          The NSURL object representing an PDF file path to export.
 * @param password
 *          The password of the source PDF file.
 *
 */
+ (void)exportAnnotToXFDF: (NSURL*)xfdf
                  srcPath: (NSURL*)src
                 password: (NSString*)password;

#pragma mark - form field

/**
 * Returns a new NSArray object containing the BaseField objects.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 *
 * @return
 *          A new NSArray object. Each annotation element gets added to an NSArray object as a BaseField object. If there are no element, this method returns an empty array.
 *
 */
- (NSArray*)fields: (NSInteger)pageIdx;

/**
 * Returns a new NSArray object containing the BaseField objects.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want.
 *
 * @return
 *          A new NSArray object. Each annotation element gets added to an NSArray object as a BaseField object. If there are no element, this method returns an empty array.
 *
 */
- (NSArray*)fields: (NSInteger)pageIdx title: (NSString*)title;

/**
 * Clear all field value.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 *
 */
- (void)clearAllField: (NSInteger)pageIdx;

/**
 * Clear field value with title.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to clear.
 *
 */
- (void)clearFieldWithPage: (NSInteger)pageIdx
                     title: (NSString*)title;

/**
 * Returns PlugPDFFieldState.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want.
 *
 * @return
 *          A PlugPDFFieldState value. The value is one of the values available in the "PlugPDFFieldState" enumeration.
 *
 */
- (PlugPDFFieldState)fieldStateWithPage: (NSInteger)pageIdx title: (NSString*)title;

/**
 * Returns PlugPDFFieldState.
 *
 * @param pageIdx
 *          The index of the page. The index is zero-based.
 * @param title
 *          The title of the field.
 * @param name
 *          The name of the field.
 *
 * @return
 *          A PlugPDFFieldState value. The value is one of the values available in the "PlugPDFFieldState" enumeration.
 *
 */
- (PlugPDFFieldState)fieldStateWithPage: (NSInteger)pageIdx title: (NSString*)title name: (NSString*)name;

/**
 * Sets the PlugPDFFieldState value of the field with title.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to set.
 * @param state
 *          The state value is one of the values available in the "PlugPDFFieldState" enumeration.
 *
 */
- (void)setFieldStateWithPage: (NSInteger)pageIdx title: (NSString*)title state: (PlugPDFFieldState)state;

/**
 * Sets the PlugPDFFieldState value of the field with title and name.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to set.
 * @param name
 *          The name of the field you want to set.
 * @param state
 *          The state value is one of the values available in the "PlugPDFFieldState" enumeration.
 *
 */
- (void)setFieldStateWithPage: (NSInteger)pageIdx title: (NSString*)title name: (NSString*)name state: (PlugPDFFieldState)state;

/**
 * Sets all fields state.
 *
 * @param state
 *          The state value is one of the values available in the "PlugPDFFieldState" enumeration.
 *
 */
- (void)setFieldGlobalState: (PlugPDFFieldState)state;

/**
 * Sets background color of all the text fields.
 *
 * @param color
 *          The UIColor instance what you want to set as background color.
 *
 */
- (void)setTextFieldBackgroundColor: (UIColor*)color;

/**
 * Sets background color of the field with title.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to set.
 * @param color
 *          The UIColor instance what you want to set as background color.
 *
 */
- (void)setFieldBackgroundColorWithPage: (NSInteger)pageIdx
                                  title: (NSString*)title
                                  color: (UIColor*)color;
/**
 * Sets mask color.
 *
 * @param color
 *          The UIColor instance what you want to set as mask color.
 *
 */
- (void)setFieldMaskColor: (UIColor*)color;

/**
 * Sets field border color.
 *
 * @param color
 *          The UIColor instance what you want to set as border color.
 *
 */
- (void)setFieldBorderColor: (UIColor*)color;

/**
 * Sets whether the field border line is hidden.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to set.
 * @param  hidden
 *          Specify YES to hide the field border or NO to show it.
 *
 */
- (void)setFieldBorderWithPage: (NSInteger)pageIdx
                         title: (NSString*)title
                        hidden: (BOOL)hidden;

/**
 * Returns a new NSArray object containing the TextField value.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to set.
 *
 * @return
 *          A new NSArray object. Each annotation element gets added to an NSString object. If there are no element, this method returns an empty array.
 *
 */
- (NSString*)textFieldValueWithPage: (NSInteger)pageIdx title: (NSString*)title;

/**
 * Sets the TextField value of the field with title.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to set.
 * @param text
 *          The TextField value.
 *
 */
- (void)setTextFieldWithPage: (NSInteger)pageIdx title: (NSString*)title text: (NSString*)text;

/**
 * Sets CheckBoxFieldDrawDelegate for custom draw.
 *
 * @param delegate
 *          A PlugPDFCheckBoxFieldDrawDelegate object.
 *
 */
- (void)setCheckBoxFieldDrawDelegate: (id <PlugPDFCheckBoxFieldDrawDelegate>) delegate;

/**
 * Returns a new NSArray object containing the CheckBoxField checked value.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want.
 *
 * @return
 *          A new NSArray object. Each annotation element gets added to an NSNumber object with BOOL. If there are no element, this method returns an empty array.
 *
 */
- (BOOL)checkBoxFieldValueWithPage: (NSInteger)pageIdx title: (NSString*)title;

/**
 * Sets the CheckBoxField value of the field with title.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to set.
 * @param checked
 *          The CheckBoxField value.
 *
 */
- (void)setCheckBoxFieldWithPage: (NSInteger)pageIdx title: (NSString*)title checked: (BOOL)checked;

/**
 * Returns a new NSArray object containing the RadioButtonField checked value.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to get.
 * @param name
 *          The name of the field you want to get.
 *
 * @return
 *
 *
 */
- (BOOL)radioButtonFieldValueWithPage: (NSInteger)pageIdx title: (NSString*)title name: (NSString*)name;

/**
 * Sets the RadioButtonField value of the field with title.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to set.
 * @param name
 *          The name of the field you want to set.
 * @param checked
 *          The CheckBoxField value.
 *
 */
- (void)setRadioButtonFieldWithPage: (NSInteger)pageIdx title: (NSString*)title name: (NSString*)name checked: (BOOL)checked;

/**
 * Returns a new NSArray object containing the ButtonField image value.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to get.
 *
 * @return
 *          A new NSArray object. Each annotation element gets added to an UIImage object. If there are no element, this method returns an empty array.
 *
 */
- (UIImage*)buttonFieldValueWithPage: (NSInteger)pageIdx title: (NSString*)title;

/**
 * Sets the ButtonField image value of the field with title.
 *
 * @param pageIdx
 *          The index of the page which is field to add. The index is zero-based.
 * @param title
 *          The title of the field you want to set.
 * @param image
 *          The ButtonField image value.
 *
 */
- (void)setButtonFieldWithPage: (NSInteger)pageIdx title: (NSString*)title image: (UIImage*)image;

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
 * @parma useCustomAppearance
 *          YES if you want to flatten with custom appearance, otherwise NO.
 *
 */
- (void)flattenFormFields: (BOOL)includeButtonField : (BOOL)useCustomAppearance;

#pragma mark - encrypt

/**
 * Returns user access permissions.
 *
 * @param print
 *          Print the document.
 * @param modifyContent
 *          Modify the contents of the document.
 * @param copyContent
 *          Copy or otherwise extract text and graphics form the document.
 * @param modifyAnnot
 *          Add or modify text annotations, fill in interactive form fields.
 * @param fillFiled
 *          Fill in existing interactive form fields.
 * @param extract
 *          Extract text and graphics.
 * @param documentAssembly
 *          Assemble the document.
 *
 * @return
 *          User access permissions value.
 *
 */
+ (NSInteger)getUserAccessPermissionsWithPrint: (BOOL)print
                                 modifyContent: (BOOL)modifyContent
                                   copyContent: (BOOL)copyContent
                                   modifyAnnot: (BOOL)modifyAnnot
                                     fillFiled: (BOOL)fillFiled
                                       extract: (BOOL)extract
                              documentAssembly: (BOOL)documentAssembly;

/**
 * encrypts document.
 *
 * @param userPass
 *          User password you want to set.
 * @param ownerPass
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

/**
 * Returns if a document at the specified path has user password.
 *
 * @param path
 *          The path and name of the accessible PDF file.
 *
 * @returns 
 *          YES if has, otherwise NO.
 */
+ (BOOL)hasUserPasswordAtPath: (NSString*)path;

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

#pragma mark - create

/**
 * Creates a empty PDF document with the specified size at the specified path.
 *
 * @param dest
 *          The PDF file path.
 * @param size
 *          The size of a PDF document.
 *
 */
+ (void)createEmptyDocument: (NSURL*)path size: (CGSize)size;

#pragma mark - merger

/**
 * Merges with given pdf documents and saves as url path.
 *
 * @param srcfiles
 *          A NSArray contains a NSURL object with pdf file path to merge.
 * @param outUrl
 *          The output file URL identifying the location in the application sandbox.
 *
 * @return
 *          '0' if the merge operation succeeds, non-zero value otherwise.
 *          MERGE_CORRUPTED_PDF			-1
 *          MERGE_PASSWORD              -2
 *          MERGE_FAIL_TO_BUILD			-3
 *
 */
+ (NSInteger)mergeFiles: (NSArray*)srcfiles
               password: (NSString*)password
                outFile: (NSURL*)outUrl;

- (void)transplantPage: (PlugPDFDocument*)srcDocument pageIdx:(NSInteger)pageIdx;

#pragma mark - signer

/**
 * Inserts an image object to the source PDF file and create destination PDF file.
 *
 * @param srcPath
 *          The source PDF file path.
 * @param destPath
 *          The destination PDF file path.
 * @param imagePath
 *          The image file path.
 * @param password
 *          The password of the source PDF file.
 * @param point
 *          The position of the image.
 * @param height
 *          The image height. The width will be scaled automatically keeping the aspact ratio.
 * @param pageIdx
 *          The zero-based page index where the image will be placed on. The index is zero-based.
 *
 * @return
 *          '0' if the insert operation succeeds, non-zero value otherwise.
 *          ERROR_NOT_OPEN					-1001
 *          ERROR_NOT_ADD_IMAGESTAMP		-1005
 *          ERROR_NOT_SAVE_INCREMENTAL		-1010
 *          ERROR_LOAD_IMAGE				-1100
 *          ERROR_NULL_PAGE                 -1101
 *
 */
+ (NSInteger) insertImage: (NSURL*)srcPath
                 destPath: (NSURL*)destPath
                imagePath: (NSURL*)imagePath
                 password: (NSString*)password
                    point: (CGPoint)point
                   height: (CGFloat)height
                  pageIdx: (NSInteger)pageIdx;

/**
 * Creates a signature field as a place holder and destination PDF file. Returns the SignatureFieldInfo object with a signature field name and the file offset where the digest data starts in the file.
 *
 * @param srcPath
 *          The source PDF file path.
 * @param destPath
 *          The destination PDF file path.
 * @param contentPath
 *          The content file path. This is the source data for computing the digest.
 * @param password
 *          The password of the source PDF file.
 * @param pageIdx
 *          The zero-based page index where the signature field will be placed on. The index is zero-based.
 * @param name
 *          The name for the signature field.
 * @param reason
 *          The reason for the signing.
 * @param location
 *          The location where the document is signed.
 *
 * @return
 *          The SignatureField object with a signature field title and the file offset where the digest data starts in the file if the operation succeeds, nil otherwise.
 *
 */
+ (SignatureField*) createSignatureField: (NSURL*)srcPath
                                destPath: (NSURL*)destPath
                             contentPath: (NSURL*)contentPath
                                password: (NSString*)password
                                 pageIdx: (NSInteger)pageIdx
                                    name: (NSString*)name
                                  reason: (NSString*)reason
                                location: (NSString*)location;

/**
 * Injects the computed byte range digest data into the PDF file.
 *
 * @param srcPath
 *          The source PDF file path.
 * @param token
 *          The token data to be injected.
 * @param offset
 *          The file offset where the digest data starts in the file.
 *
 * @return
 *          '0' if the inject operation succeeds, non-zero value otherwise.
 *          ERROR_WRITE_SIGNTOKEN			-2021
 *
 */
+ (NSInteger) injectDigestToken: (NSURL*)srcPath
                          token: (NSData*)token
                         offset: (NSNumber*)offset;

/**
 * Returns the NSArray object contains SignatureField objects in the PDF file.
 *
 * @param srcPath
 *          The source PDF file path.
 * @param password
 *          The password of the source PDF file.
 *
 * @return
 *          The NSArray object contains SignatureField objects in the PDF file if the operation succeeds, empty NSArray object otherwise.
 *
 */
+ (NSArray*) signatureFields: (NSURL*)srcPath
                    password: (NSString*)password;

/**
 * Returns the computed byte range digest data in the signature field of the field name and create content file that is the source data for computing the digest.
 *
 * @param srcPath
 *          The source PDF file path.
 * @param contentPath
 *          The content file path.
 * @param password
 *          The password of the source PDF file.
 * @param pageIdx
 *          The zero-based page index where the signature field will be placed on. The index is zero-based.
 * @param fieldTitle
 *          The signature field title you want to read.
 *
 * @return
 *          The computed byte range digest data in the signature field if the operation succeeds, nil value otherwise.
 *
 */
+ (NSData*) readDigestToken: (NSURL*)srcPath
                contentPath: (NSURL*)contentPath
                   password: (NSString*)password
                    pageIdx: (NSInteger)pageIdx
                 fieldTitle: (NSString*)fieldTitle;

#pragma mark - extract text

/**
 * Extracts and returns NSDictionary object contatins extraction results text and rect.
 *
 * @param pageIdx
 *          The index of the page you want to extract text. The index is zero-based.
 * @param rect
 *          The rect of the page you want to extract text; if CGRectZero extract all of the text on the page.
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
- (NSDictionary*)extractTextAndRects: (NSInteger)pageIdx inRect: (CGRect)rect;

/**
 * Extracts text and returns NSString object contatins extraction results.
 *
 * @param pageIdx
 *          The index of the page you want to extract text. The index is zero-based.
 * @param rect
 *          The rect of the page you want to extract text; if CGRectZero extract all of the text on the page.
 *
 * @return
 *          The NSString object contains extraction results, nil value otherwise.
 *
 * @throw NoCopyContentsPermission
 *          Thrown when the copy or otherwise extraction is occurred without permission to copy contents.
 *
 */
- (NSString*)extractText: (NSInteger)pageIdx inRect: (CGRect)rect;

/**
 * Extracts text from pdf file at the src url and returns NSDictionary object contatins the pageIdx/text pair.
 *
 * @param src
 *          The source file url.
 * @param password
 *          The pasword to unlock an encrypted document.
 *
 * @return
 *          The NSDictionary object contains extraction results, nil value otherwise.
 *
 * @throw NoCopyContentsPermission
 *          Thrown when the copy or otherwise extraction is occurred without permission to copy contents.
 *
 */
+ (NSDictionary*)extractTextSrc: (NSURL*)src password: (NSString*)password;

/**
 * Extracts text from pdf file at the src url and returns NSString object contatins extraction results.
 *
 * @param src
 *          The source file url.
 * @param password
 *          The pasword to unlock an encrypted document.
 * @param pageIdx
 *          The index of the page you want to extract text. The index is zero-based.
 * @param rect
 *          The rect of the page you want to extract text; if CGRectZero extract all of the text on the page.
 *
 * @return
 *          The NSString object contains extraction results, nil value otherwise.
 *
 * @throw NoCopyContentsPermission
 *          Thrown when the copy or otherwise extraction is occurred without permission to copy contents.
 *
 */
+ (NSString*)extractTextSrc: (NSURL*)src password: (NSString*)password pageIdx: (NSInteger)pageIdx rect: (CGRect)rect;

- (void) closeDoc;

- (BOOL) isOpen;
@end
