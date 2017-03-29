//
//  FYSocketManager.h
//  Socket
//
//  Created by fan on 17/3/29.
//  Copyright © 2017年 fan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GCDAsyncSocket.h"
#import "FYSocketManager.h"

@protocol FYSocketManagerDelegate <NSObject>
@optional


@end

@interface FYSocketManager : NSObject {
    
}
@property (nonatomic, weak) id delegate;
@property (nonatomic, weak) dispatch_queue_t queue;
@property (nonatomic, strong) GCDAsyncSocket* tcpSocket;


- (instancetype)initWithDelegate:(id)delegate delegateQueue:(dispatch_queue_t)queue;

- (BOOL)connectToHost:(NSString*)host port:(NSInteger)port error:(NSError**)error;

@end
