//
//  JCMDragGestureRecognizer.h
//  JCMDragging
//
//  Created by James Moschou on 15/05/12.
//  Copyright (c) 2012 James Moschou <james.moschou@gmail.com>
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to
//  deal in the Software without restriction, including without limitation the
//  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
//  sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//   
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//  


#import <UIKit/UIKit.h>


@protocol JCMDragGestureRecognizerDelegate;


@interface JCMDragGestureRecognizer : UILongPressGestureRecognizer

@property (nonatomic, readonly, strong) UIView *sourceView;             // The original view the gesture was attached to
@property (nonatomic, readonly, strong) UIView *destinationView;        // The view the drag is positioned over
@property (nonatomic, readonly, strong) UIView *draggingView;           // The view being moved while a drag is occuring

@property (nonatomic, weak) id <JCMDragGestureRecognizerDelegate> delegate;

- (void)deleteSourceView;
- (void)restoreSourceView:(UIView *)newSourceView;

@end


@protocol JCMDragGestureRecognizerDelegate <UIGestureRecognizerDelegate, NSObject>
@optional

- (UIView *)draggingViewForDragGestureRecognizer:(JCMDragGestureRecognizer *)dragGestureRecognizer;

@end
