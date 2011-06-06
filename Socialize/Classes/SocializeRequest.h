//
//  SocializeRequest.h
//  SocializeSDK
//
//  Created by William Johnson on 6/1/11.
//  Copyright 2011 Socialize, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum 
{
    SocializeRequestMethodGET = 0,
    SocializeRequestMethodPUT = 1,
    SocializeRequestMethodPOST = 2
    
} SocializeRequestMethod;

/*
 *Your application should implement this delegate
 */


@protocol SocializeRequestDelegate;

@interface SocializeRequest : NSObject 
{
    id<SocializeRequestDelegate> _delegate;
    NSString*                   _url;
    NSString*                   _httpMethod;
    NSMutableDictionary*        _params;
    NSURLConnection*            _connection;
    NSMutableData*              _responseText;
}

@property(nonatomic,assign) id<SocializeRequestDelegate> delegate;
@property(nonatomic,copy)   NSString                    *url;
@property(nonatomic,copy)   NSString                    *httpMethod;
@property(nonatomic,retain) NSMutableDictionary         *params;
@property(nonatomic,assign) NSURLConnection             *connection;
@property(nonatomic,assign) NSMutableData               *responseText;

+ (NSString*)serializeURL:(NSString *)baseUrl
                   params:(NSDictionary *)params;

+ (NSString*)serializeURL:(NSString *)baseUrl
                   params:(NSDictionary *)params
               httpMethod:(NSString *)httpMethod;

+ (SocializeRequest*)getRequestWithParams:(NSMutableDictionary *) params
                        httpMethod:(NSString *) httpMethod
                          delegate:(id<SocializeRequestDelegate>)delegate
                        requestURL:(NSString *) url;
- (BOOL) loading;

- (void) connect;

@end

///////////////////////////////////////////////////////////////////////////////////////////////////

/*
 *Your application should implement this delegate
 */
@protocol SocializeRequestDelegate <NSObject>

@optional

/**
 * Called just before the request is sent to the server.
 */
- (void)requestLoading:(SocializeRequest *)request;

/**
 * Called when the server responds and begins to send back data.
 */
- (void)request:(SocializeRequest *)request didReceiveResponse:(NSURLResponse *)response;

/**
 * Called when an error prevents the request from completing successfully.
 */
- (void)request:(SocializeRequest *)request didFailWithError:(NSError *)error;

/**
 * Called when a request returns and its response has been parsed into an object.
 *
 * The resulting object may be a dictionary, an array, a string, or a number, depending
 * on thee format of the API response.
 */
- (void)request:(SocializeRequest *)request didLoad:(id)result;

/**
 * Called when a request returns a response.
 *
 * The result object is the raw response from the server of type NSData
 */
- (void)request:(SocializeRequest *)request didLoadRawResponse:(NSData *)data;

@end
