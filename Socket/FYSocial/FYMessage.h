//
//  FYSocketMessage.h
//  Socket
//
//  Created by fan on 17/3/29.
//  Copyright © 2017年 fan. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef  NS_ENUM(NSInteger, MessageType) {
    MessageType_System,                      // 系统消息
    MessageType_Command,                     // 命令消息，不会显示
    MessageType_Text,                        // 文本消息
    MessageType_Image,                       // 图片消息
    MessageType_Video,                       // 短视频
    MessageType_RedPacket,                   // 红包消息
    MessageType_CallVideo,                   // 视频通话
    MessageType_CallSound,                   // 语音通话
};

typedef NS_ENUM(NSInteger, MessageReceiveStatus) {
    MessageReceiveStatus_Unread,                // 未读
    MessageReceiveStatus_Read,                  // 已读
};

typedef NS_ENUM(NSInteger, MessageSendStatus) {
    MessageSendStatus_Sending,                  // 发送中
    MessageSendStatus_Send,                     // 发送成功
    MessageSendStatus_Failure,                  // 发送失败
    MessageSendStatus_Receiver,                 // 对方已经接受
};

@interface FYMessage : NSObject {
    
}

/**
 消息类型
 */
@property (nonatomic) MessageType type;

/**
 消息ID
 */
@property (nonatomic, copy) NSString* messageID;

/**
 消息接受者ID
 */
@property (nonatomic, strong) NSString* receiverID;

/**
 消息发送者ID
 */
@property (nonatomic, strong) NSString* senderID;

/**
 消息所属的会话ID
 */
@property (nonatomic, strong, readonly) NSString* conversationID;

/**
 消息的发送时间（本地时间，服务器时间待定）
 */
@property (nonatomic, readonly) long long sendTime;

/**
 消息接受到的时间
 */
@property (nonatomic, readonly) long long receiverTime;


- (instancetype)initWithReceiverID:(NSString*)reciverID
                           content:(NSString*)content;

@end


/**************************************************************
 *  子类
 **************************************************************/

typedef NS_ENUM(NSInteger, SystemMessageType) {
    SystemMessageType_AddFriend,            // 加好友申请
    SystemMessageType_AddGroup,             // 加群申请
    SystemMessageType_FriendLogin,          // 好友上线
};

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

typedef NS_ENUM(NSInteger, CommandMessageType) {
    CommandMessageType_Logout,                  // 退出登录
    CommandMessageType_Prompt,                  // 弹窗提示
};

/**
 命令消息
 */
@interface FYMessageCommand : FYMessage

@end
