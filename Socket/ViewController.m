//
//  ViewController.m
//  Socket
//
//  Created by fan on 17/3/29.
//  Copyright © 2017年 fan. All rights reserved.
//

#import "ViewController.h"
#import "FYSocketManager.h"

@interface ViewController () {
    
}
@property (nonatomic, strong) FYSocketManager* manager;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
    self.manager = [[FYSocketManager alloc] initWithDelegate:self delegateQueue:nil];
    
    NSError* error = nil;
    [self.manager connectToHost:@"www.baidu.com" port:80 error:&error];
    if (error) {
        NSLog(@"%@",error);
    }
    
    [self.manager.tcpSocket readDataWithTimeout:3 tag:1];
    [self.manager.tcpSocket writeData:[@"GET / HTTP/1.1\n\n" dataUsingEncoding:NSUTF8StringEncoding] withTimeout:3 tag:1];
    
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
