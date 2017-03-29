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
 初始化

 @param delegate 代理
 @param queue 队列，如果不传，则为主队列
 @return 实例
 */
- (instancetype)initWithDelegate:(id)delegate delegateQueue:(dispatch_queue_t)queue;

/**
 连接主机

 @param host 主机IP
 @param port 端口
 @param error 错误信息
 @return 是否连接成功
 */
- (BOOL)connectToHost:(NSString*)host port:(NSInteger)port error:(NSError**)error;

/**
 发送消息给某个联系对象

 @param message 消息
 @param contact 联系对象
 @return 是否发送成功
 */
- (BOOL)setMessage:(FYMessage*)message toContact:(FYContact*)contact;

/**
 注册用户

 @param contact 用户对象
 */
- (void)registerUser:(FYContact*)contact;

/**
 获取联系人对象列表

 @param completeBlock 完成回调
 */
- (void)getContacts:(void (^)(NSArray* contacts))completeBlock;


@end
