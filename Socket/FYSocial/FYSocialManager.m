//
//  FYSocketManager.m
//  Socket
//
//  Created by fan on 17/3/29.
//  Copyright © 2017年 fan. All rights reserved.
//

#import "FYSocialManager.h"

@interface FYSocialManager ()<GCDAsyncSocketDelegate> {
    
}

@end

@implementation FYSocialManager

- (instancetype)initWithDelegate:(id)delegate delegateQueue:(dispatch_queue_t)queue {
    if (self = [super init]) {
        if (!queue) {
            queue = dispatch_get_main_queue();
        }
        
        _delegate = delegate;
        _queue = queue;
        
        _tcpSocket = [[GCDAsyncSocket alloc] initWithDelegate:self delegateQueue:queue];
        
    }
    return self;
}

- (BOOL)connectToHost:(NSString *)host port:(NSInteger )port error:(NSError *__autoreleasing *)error {
    return [self.tcpSocket connectToHost:host onPort:port error:error];
}

#pragma mark - GCDAsyncSocketDelegate
- (void)socket:(GCDAsyncSocket *)sock didConnectToHost:(NSString *)host port:(uint16_t)port {
    NSLog(@"连接成功 %@  %d", host, port);
}

- (void)socketDidDisconnect:(GCDAsyncSocket *)sock withError:(NSError *)err {
    NSLog(@"断开连接");
}

- (void)socket:(GCDAsyncSocket *)sock didReadData:(NSData *)data withTag:(long)tag {
    NSString* str = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    NSLog(@"%@", str);
}

- (void)socket:(GCDAsyncSocket *)sock didWritePartialDataOfLength:(NSUInteger)partialLength tag:(long)tag {
    
}

@end
