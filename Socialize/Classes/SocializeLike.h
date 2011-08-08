//
//  SocializeLike.h
//  SocializeSDK
//
//  Created by Fawad Haider on 6/22/11.
//  Copyright 2011 Socialize, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SocializeActivity.h"
#import "SocializeApplication.h"
#import "SocializeUser.h"
#import "SocializeEntity.h"

/**
 In progress
 */
@protocol SocializeLike <SocializeActivity>
@end

@interface SocializeLike : SocializeActivity <SocializeLike>
{
}

@end
