/****************************************************************************
 **
 ** Copyright (C) 2013 ePapyrus, Inc.
 ** All rights reserved.
 **
 ** This file is part of PlugPDF for iOS project.
 **
 ****************************************************************************/

#import <Foundation/Foundation.h>

/**
 * Version
 *
 * @file PlugPDF/Version.h
 *
 */
@interface PlugPDFVersion : NSObject

/**
 * Returns the version full string. ex) 2.5.1.51 (92213b0.dirty)
 *
 */
+ (NSString *)getVersionName;

/**
 * Returns the major version value. ex) 2
 *
 */
+ (NSInteger)getMajorVersion;

@end
