//
//  FYSocketManager.h
//  Socket
//
//  Created by fan on 17/3/29.
//  Copyright © 2017年 fan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GCDAsyncSocket.h"
#import "FYMessage.h"
#import "FYContact.h"
#import "FYError.h"

typedef void (^FailureBlock)(FYError* error);
typedef void (^EmptyBlock)();

@protocol FYSocketManagerDelegate <NSObject>
@optional
/**
 接受到消息

 @param message 消息
 */
- (void)receiveMessage:(FYMessage*)message;

@end

@interface FYSocialManager : NSObject {
    
}
@property (nonatomic, weak) id delegate;
@property (nonatomic, weak, readonly) dispatch_queue_t queue;
@property (nonatomic, strong, readonly) GCDAsyncSocket* tcpSocket;

/**
 是否是debug模式，当debug模式会显示错误信息
 */
@property (nonatomic) BOOL debug;

+ (instancetype)sharedFYIM;

- (void)initWithKey:(NSString*)key secret:(NSString*)secret;


/**
 链接服务器

 @param token 身份令牌
 @param successBlock 成功回调
 @param failureBlock 失败回调
 */
- (void)connectWithToken:(NSString*)token
                 success:(EmptyBlock)successBlock
                 failure:(FailureBlock)failureBlock;

/**
 断开与服务器的连接
 */
- (void)disconnect;

/**
 发送消息给某个联系对象

 */
- (void)setMessage:(FYMessage*)message
          targetID:(NSString*)targetID
           success:(EmptyBlock)successBlock
           failure:(FailureBlock)failureBlock;

/**
 注册用户

 @param contact 用户对象
 用什么注册？
 待修改
 */
- (void)registerUser:(FYContact*)contact complete:(FYContactUser*)contact;

/**
 获取联系人对象列表

 @param completeBlock 完成回调
 */
- (void)getContacts:(void (^)(NSArray* contacts))completeBlock;


@end
