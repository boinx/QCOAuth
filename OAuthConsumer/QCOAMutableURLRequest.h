//
//  OAMutableURLRequest.h
//  OAuthConsumer
//
//  Created by Jon Crosby on 10/19/07.
//  Copyright 2007 Kaboomerang LLC. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.


#import <Foundation/Foundation.h>
#import "QCOAConsumer.h"
#import "QCOAToken.h"
#import "QCOAHMAC_SHA1SignatureProvider.h"
#import "QCOASignatureProviding.h"
#import "NSMutableURLRequest+Parameters.h"
#import "NSURL+Base.h"


@interface QCOAMutableURLRequest : NSMutableURLRequest {
@protected
    QCOAConsumer *consumer;
    QCOAToken *token;
    NSString *realm;
    NSString *signature;
    id<QCOASignatureProviding> signatureProvider;
    NSString *nonce;
    NSString *timestamp;
	NSMutableDictionary *extraOAuthParameters;
}
@property(readonly) NSString *signature;
@property(readonly) NSString *nonce;

- (id)initWithURL:(NSURL *)aUrl
		 consumer:(QCOAConsumer *)aConsumer
			token:(QCOAToken *)aToken
            realm:(NSString *)aRealm
signatureProvider:(id<QCOASignatureProviding, NSObject>)aProvider;

- (id)initWithURL:(NSURL *)aUrl
		 consumer:(QCOAConsumer *)aConsumer
			token:(QCOAToken *)aToken
            realm:(NSString *)aRealm
signatureProvider:(id<QCOASignatureProviding, NSObject>)aProvider
            nonce:(NSString *)aNonce
        timestamp:(NSString *)aTimestamp;

- (void)prepare;

- (void)setOAuthParameterName:(NSString*)parameterName withValue:(NSString*)parameterValue;

@end
