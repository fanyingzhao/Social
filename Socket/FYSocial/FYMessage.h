//
//  FYSocketMessage.h
//  Socket
//
//  Created by fan on 17/3/29.
//  Copyright © 2017年 fan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FYContact.h"

typedef  NS_ENUM(NSInteger, MessageType) {
    MessageSystem,                      // 系统消息
    MessageNewfriend,                   // 申请加好友消息
    MessageFriendLogin,                 // 有好友上线
    MessageText,                        // 文本消息
    MessageImage,                       // 图片消息
    MessageVideo,                       // 短视频
    MessageRedPacket,                   // 红包消息
    MessageCallVideo,                   // 视频通话
    MessageCallSound,                   // 语音通话
};

@interface FYMessage : NSObject {
    
}

/**
 消息类型
 */
@property (nonatomic) MessageType type;

/**
 消息接受者
 */
@property (nonatomic, strong) FYContact* receiver;

/**
 消息发送者
 */
@property (nonatomic, strong) FYContact* sender;


@end


/**************************************************************
 *  子类
 **************************************************************/

/**
 系统消息
 */
@interface FYMessageSystem : FYMessage

@end

/**
 普通文本对象
 */
@interface FYMessageText : FYMessage

@end

/**
 二进制对象，用于视频和图片消息
 */
@interface FYMessageBinary : FYMessage

@end

/**
 红包消息
 */
@interface FYMessageRedPacket : FYMessage

@end
