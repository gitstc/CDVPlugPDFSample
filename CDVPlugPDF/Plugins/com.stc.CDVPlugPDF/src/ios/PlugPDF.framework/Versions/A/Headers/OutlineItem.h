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
 * PlugPDFOutlineItem
 *
 * @file PlugPDF/OutlineItem.h
 *
 * A PlugPDFOutlineItem object is an element in a tree-structured hierarchy that can represent the structure of a PDF document.
 *
 */
@interface PlugPDFOutlineItem : NSObject

@property (nonatomic, strong) PlugPDFOutlineItem *parent;

@property (nonatomic, strong) NSMutableArray *children;

@property (nonatomic) NSInteger idx;

/**
 * The title string of the outline.
 *
 */
@property (nonatomic, strong) NSString *title;

/**
 * The index of the destination page. The index is zero-based.
 *
 */
@property (nonatomic) NSInteger pageIdx;

/**
 * The depth level of the outline element in the outline tree structure.
 *
 */
@property (nonatomic) NSInteger depth;

/**
 * Initializes an outline with initialization value.
 *
 * @param title 
 *          The title string of the outline element.
 * @param pageIdx
 *          The index of destination page. The index is zero-based.
 * @param depth
 *          The depth level of the element in the outline tree structure.
 *
 */
- (id)initWithParent: (PlugPDFOutlineItem*)parent
                 idx: (NSInteger)idx
               title: (NSString*)title
             pageIdx: (NSInteger)pageIdx
               depth: (NSInteger)depth;

- (NSArray*)outlines;

- (BOOL)removeItem: (PlugPDFOutlineItem*)item;

- (void)addItem: (PlugPDFOutlineItem*)item
          after: (PlugPDFOutlineItem*)after;

@end

@interface PlugPDFOutlineTree : NSObject

@property (nonatomic) BOOL modified;

@property (nonatomic, strong) PlugPDFOutlineItem *root;

- (NSArray*)outlines;

- (void)removeItem: (PlugPDFOutlineItem*)item;

- (void)addItem: (PlugPDFOutlineItem*)item
         parent: (PlugPDFOutlineItem*)parent
          after: (PlugPDFOutlineItem*)after;

@end
