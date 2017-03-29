//
//  FYSocketMessage.h
//  Socket
//
//  Created by fan on 17/3/29.
//  Copyright © 2017年 fan. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef  NS_ENUM(NSInteger, MessageType) {
    MessageSystem,                      // 系统消息
    MessageNewfriend,                   // 申请加好友消息
    MessageFriendLogin,                 // 有好友上线
    
};

@interface FYSocketMessage : NSObject

@end
