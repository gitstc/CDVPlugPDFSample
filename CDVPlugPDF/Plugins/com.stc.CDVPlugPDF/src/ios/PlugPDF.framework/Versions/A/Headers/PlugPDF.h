/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

/**
 * @mainpage PlugPDF SDK
 *
 * @section Introduction
 * - PlugPDF SDK would help developers place PDF viewer in the iOS Platform.
 * @section Creation information
 * - author : PlugPDF Team
 * - homepage : http://www.plugpdf.com
 *
 * @file PlugPDF/PlugPDF.h
 *
 */

#ifndef __PLUG_PDF_H__
#define __PLUG_PDF_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initializes PlugPDF framework.
 * You have to call this before you call any PDF processing functions.
 *
 * To make your application come alive with PlugPDF, you will require a valid license.
 * - Free Trial : http://plugpdf.com/trial-license-req/
 * - Order : http://plugpdf.com/order/
 *
 * @param key
 *          A product license key of PlugPDF SDK for iOS.
 *
 * @throw LicenseInvalid
 *          Thrown when a product license key is not valid. It might be broken.
 * @throw LicenseWrongProductVersion
 *          Thrown when an attempt is made to use a product license key that is not of supported product version.
 * @throw LicenseTrialTimeOut
 *          Thrown when a trial license key has expired.
 * @throw LicenseUnusableSDKVersion
 *          Thrown when an attempt is made to use a product license key that is not of supported PlugPDF SDK version.
 * @throw LicenseUnusableOS
 *          Thrown when an attempt is made to use a product license key that is not of supported OS type.
 * @throw LicenseMismatchAppID
 *          Thrown when the product license key does not contain an application ID.
 *
 */
void PlugPDFInit(char *key);

/**
 * Enables the interface for handlers invoked when a abruptly terminates due to an uncaught exception.
 * When an uncaught exception occurs a log file created by PlugPDF SDK in the application sandbox. 
 *
 */
void enableUncaughtExceptionHandler();

/**
 * Sets enable to check for update. If it is not latest version, the popup message will be displayed when the view is loaded.
 *
 * @param enabled
 *          YES to check for update, NO to skip update checking.
 *
 */
//void setUpdateCheckEnabled(BOOL enabled);
    
/**
 * Sets a font file at the url to mapping fonts.
 *
 * @param url
 *          The NSURL object with true type font file path.
 *
 */
void setFontMappingPath(NSURL *url);
    
/**
 * Releases all resources allocated by PlugPDF framework.
 *
 */
void PlugPDFUninit();

#ifdef __cplusplus
}
#endif

#import <Foundation/Foundation.h>

/**
 * PlugPDF
 *
 * @file PlugPDF/PlugPDF.h
 *
 */
@interface PlugPDF : NSObject

/**
 * Initializes PlugPDF framework.
 * You have to call this before you call any PDF processing functions.
 *
 * @param key
 *          A product license key of PlugPDF SDK for iOS.
 *
 * @throw LicenseInvalid
 *          Thrown when a product license key is not valid. It might be broken.
 * @throw LicenseWrongProductVersion
 *          Thrown when an attempt is made to use a product license key that is not of supported product version.
 * @throw LicenseTrialTimeOut
 *          Thrown when a trial license key has expired.
 * @throw LicenseUnusableSDKVersion
 *          Thrown when an attempt is made to use a product license key that is not of supported PlugPDF SDK version.
 * @throw LicenseUnusableOS
 *          Thrown when an attempt is made to use a product license key that is not of supported OS type.
 * @throw LicenseMismatchAppID
 *          Thrown when the product license key does not contain an application ID.
 *
 */
+ (void)init: (NSString*)key;

/**
 * Enables the interface for handlers invoked when a abruptly terminates due to an uncaught exception.
 * When an uncaught exception occurs a log file created by PlugPDF SDK in the application sandbox.
 *
 */
+ (void)setEnableUncaughtExceptionHandler;

/**
 * Sets enable to check for update. If it is not latest version, the popup message will be displayed when the view is loaded.
 *
 * @param enabled
 *          YES to check for update, NO to skip update checking.
 *
 */
//+ (void)setUpdateCheckEnabled: (BOOL)enabled;

/**
 * Sets a font file at the url to mapping fonts.
 *
 * @param url
 *          The NSURL object with true type font file path.
 *
 */
+ (void)setFontMappingPath: (NSURL*)url;

/**
 * Releases all resources allocated by PlugPDF framework.
 *
 */
+ (void)uninit;

@end

#endif //__PLUG_PDF_H__
