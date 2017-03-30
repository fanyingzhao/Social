//
//  FYContact.h
//  Socket
//
//  Created by fan on 17/3/29.
//  Copyright © 2017年 fan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FYContact : NSObject

@end

/**
 群
 */
@interface FYContactGroup : FYContact

@end

/**
 用户
 */
@interface FYContactUser : FYContact

@end

/**
 讨论组
 */
@interface FYContactDiscuss : FYContact

@end

/**
 客服
 */
@interface FYContactService : FYContact

@end

