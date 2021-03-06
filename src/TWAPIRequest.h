//
//  TWAPI.h
//  SDK
//
//  Created by Andrew McSherry on 3/27/13.
//  Copyright (c) 2013 TuneWiki, Inc.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
//  documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
//  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
//  persons to whom the Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
//  Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
//  OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import "TWAPIDelegate.h"

@interface TWAPIRequest : NSObject

@property (nonatomic, retain) NSURLConnection *connection;
@property (nonatomic, assign) id<TWAPIDelegate> delegate;
@property (nonatomic, retain) NSMutableData *data;

- (id) initWithDelegate:(id<TWAPIDelegate>)delegate;

- (void) start;

- (void) cancel;

#pragma mark -
#pragma mark Methods for Subclasss to implement

// Required
- (NSString*) httpMethod;
- (NSString*) resourcePath;

// Required for POST
- (NSData*) postBody;

// Optional
- (NSDictionary*) getParams;
- (NSDictionary*) postParams;
- (NSDictionary*) httpHeaders;

@end
