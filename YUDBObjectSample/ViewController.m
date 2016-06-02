//
//  ViewController.m
//  YUDBObject
//
//  Created by BruceYu on 15/8/12.
//  Copyright (c) 2015年 BruceYu. All rights reserved.
//

#import "ViewController.h"
#import "UserInfo.h"
#import "DBObj.h"
#import <YUDBFramework/DBObject.h>



#define YU_LOG_FILE_PATH [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)objectAtIndex:0]stringByAppendingPathComponent:@"ns.log"]

#define YU_NSLog(format, ...)   {fprintf(stderr, "<%s>     line:%d       %s        ",                \
[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], \
__LINE__, __func__);                                                       \
(NSLog)((format), ##__VA_ARGS__);                                          \
fprintf(stderr, "");                                              \
}


#warning 控制台日志
#define openDebugLog 0 //Default 1

/**
 *  DBOBject 使用runtime + fmdb 封装
 
 1.自动建表
 
 2.自动检查增删表字段
 
 3.自定义数据库名，文件路径
 
 4.支持一对一对象数据库存储，清缓存简单方便
 
 5.支持多路径，多数据库关联查询
 
 6.一键保存、修改、删除、查找、多级关联查询解析、反序列化
 
 7.支持数据解析序列化、反序列化、json -> model  and  model ->json
 
 */

@interface ViewController()
@property (weak, nonatomic) IBOutlet UITextView *textView;
@end


@implementation ViewController



- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
#pragma mark - textView日志显示
#if openDebugLog
    [self showDebug];
    //    int X = arc4random() % 100;
    //    if (X%2 == 1) {
    //        [self showDebug];
    //    }
#endif
    
    
    usleep(2000000);
    
    
    UserInfo *user = [[UserInfo alloc] init];
    user.name = @"test";
    user.phone = @"18521911111";
    [user save:@"name"];
    
    NSMutableArray *arr = [NSMutableArray array];
    for (int i = 0; i<15; i++) {
        UserInfo *user = [[UserInfo alloc] init];
        user.name = @"test";
        user.phone = ComboString(@"185219_%@", @(i));
        user.age = 1;
        user.dId = ComboString(@"%@", @(i));
        [arr addObject:user];
    }
    
    DBObj *obj = [[DBObj alloc] init];
    obj.name = @"test1";
    obj.phone = @"123456789";
    obj.info = user;
    obj.infoArry = arr;
    [obj save:@"name"];
    
#if 0
    [DBObj save:obj];
     [obj saveWtihConstraints:@[@"name"]];
    
    [obj deleteWithKey:@"name"];
    
    [obj deleteWtihConstraints:@[@"name"]];
#endif
    
    
#if 0
    NSDictionary *dic = [obj dictory];
    
    DBObj *objj = [[DBObj alloc] init];
    [objj Deserialize:dic];
    NSLog(@"_ms = %@",_ms);
    
    NSArray *userArry = [UserInfo getAll];
    
    NSArray *userArry = [UserInfo getWtihConstraints:@{@"phone":@"185219_1"}];
    
    NSArray *userArry = [UserInfo getList:@"phone" value:@"185219_1"];
    
    DBObj *userArry = [DBObj get:@"name" value:@"test1"];
    NSLog(@"userArry. name %@",userArry.infoArry);
    NSLog(@"info. name %@",userArry.info.phone);
    
    for (UserInfo *info in userArry) {
        
        DBLog(@"info  %@",[info dictory]);
    }
    NSLog(@"1");
#endif
    
    NSArray *userArry = [DBObj getAll];
    for (DBObj *info in userArry) {
        
        DBLog(@"info  %@",[info dictory]);
        
        for (UserInfo *obj in info.infoArry) {
            
            DBLog(@"obj  %@",[obj dictory]);
        }
    }
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark -
#pragma mark -  showDebug
-(void)showDebug{
    [self redirectSTD:STDOUT_FILENO];
    [self redirectSTD:STDERR_FILENO];
}

- (void)redirectSTD:(int )fd{
    NSPipe * pipe = [NSPipe pipe] ;
    NSFileHandle *pipeReadHandle = [pipe fileHandleForReading] ;
    dup2([[pipe fileHandleForWriting] fileDescriptor], fd) ;
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(redirectNotificationHandle:)
                                                 name:NSFileHandleReadCompletionNotification
                                               object:pipeReadHandle] ;
    [pipeReadHandle readInBackgroundAndNotify];
}

- (void)redirectNotificationHandle:(NSNotification *)notification {
    
    NSData *data = notification.userInfo[NSFileHandleNotificationDataItem];
    if (data.length) {
        NSString *string = [NSString.alloc initWithData:data encoding:NSUTF8StringEncoding];
        self.textView.text = [self.textView.text stringByAppendingString:string];
        double delayInSeconds = 0.1;
        
        dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
        dispatch_after(popTime, dispatch_get_main_queue(), ^(void) {
            NSRange txtOutputRange;
            txtOutputRange.location = self.textView.text.length;
            txtOutputRange.length = 0;
            [self.textView scrollRangeToVisible:txtOutputRange];
            [self.textView setSelectedRange:txtOutputRange];
        });
        [notification.object readInBackgroundAndNotify];
        
    }else {
        [self performSelector:@selector(refreshLog:) withObject:notification afterDelay:1.0];
    }
}

- (void)refreshLog:(NSNotification *)notification {
    
    [notification.object readInBackgroundAndNotify];
}

@end
