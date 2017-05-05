//
//  AppDelegate.m
//  YUDBModel
//
//  Created by BruceYu on 2017/5/5.
//  Copyright © 2017年 BruceYu. All rights reserved.
//

#import "AppDelegate.h"
#import "UserInfo.h"
#import "DBObj.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [self test];
    
    return YES;
}


- (void)test{
    
#pragma mark -
#pragma mark - 使用示例
    NSDictionary *baseJson = @{
                               @"id":@"666",
                               @"countS":@(100),
                               @"countUS":@(99),
                               @"countB":@"1",
                               @"integer":@"1",
                               @"uinteger":@"1",
                               @"countC":@'c',
                               @"countUC":@'c',
                               @"name":@"BruceYu",
                               @"url":@"www/baidu.com",
                               @"dict":@{
                                       @"name":@"(null)",
                                       @"phone":@"18512345678",
                                       @"age":@(66),
                                       @"sex":@(1),
                                       },
                               
                               
                               @"info":@{
                                       @"name":@"bruce",
                                       @"phone":@"(null)",
                                       @"age":@(66),
                                       @"sex":@(1),
                                       @"infoLevel1" :         @{
                                               @"infoLevel2" :             @{
                                                       @"infoLevel3" :                 @{
                                                               @"infoLevel4" :                     @{
                                                                       @"infoLevel5" :                         @{
                                                                               @"infoLevel6" :                             @{
                                                                                       @"name6" : @"level6",
                                                                                       },
                                                                               @"name5" : @"level5",
                                                                               },
                                                                       @"name4" : @"level4",
                                                                       },
                                                               @"name3" : @"level3",
                                                               },
                                                       @"name2" : @"level2",
                                                       },
                                               @"name1" : @"level1",
                                               @"phone1" : @"phone1",
                                               },
                                       },
                               
                               @"list":@[
                                       @{
                                           @"name":@"name1",
                                           @"phone":@"18500000001",
                                           @"age":@(11),
                                           @"sex":@(2),
                                           },
                                       @{
                                           @"name":@"(null)",
                                           @"phone":@"18500000002",
                                           @"age":@(22),
                                           @"sex":@(2),
                                           },
                                       
                                       @{
                                           @"name":@"name3",
                                           @"phone":@"18500000003",
                                           @"age":@(33),
                                           @"sex":@(3),
                                           },
                                       ],
                               };
    
    NSMutableArray *list = [NSMutableArray new];
    
    for (int i = 0; i<2000; i++) {
        [list addObject:@{
                          @"name":@"name1",
                          @"phone":@"18500000001",
                          @"age":@(i),
                          @"sex":@(2),
                          }];
    }
    
    NSMutableDictionary *json = [NSMutableDictionary dictionaryWithDictionary:baseJson];
    //    json[@"list"] = list;
    
    ///自定义数据库路径
    YUDBModel_SetupDBPath(NSHomeDirectory());
    
    ///
    YUDBModel_SetupDBVersion(@"1.0");
    
    ///删除数据库文件
    YUDBModel_ClearDBFile();
    
    YUDBModel_SetDBLog(YES);
    
    NSLog(@"dbPath: %@",NSObject.dbPath);
    
    //-----------------------------------------------------------------------
    //反序列化 把json转换成对象
    //-----------------------------------------------------------------------
    DBObj *dbObj = [DBObj modelWithDictionary:json];
    
    
    
    //    NSLog(@"dictionary %@",[dbObj dictionary]);
    
    dbObj.color = [UIColor redColor];
    dbObj.url = [NSURL URLWithString:@"www.baidu.com"];
    dbObj.image = [UIImage imageNamed:@"img"];
    //    dbObj.data = UIImagePNGRepresentation([UIImage imageNamed:@"img"]);
    dbObj.name = @"bruce";
    dbObj.integer = 100;
    dbObj.countF = 1.6f;
    dbObj.countD = 1.6f;
    dbObj.countL = 100;
    dbObj.countLL = 100;
    dbObj.countUL = 100;
    dbObj.countULL = 100;
    dbObj.countC = 'c';
    dbObj.countUC = 'c';
    
    
    dbObj.number = [NSNumber numberWithFloat:1.5];
    
    NSLog(@"dbObj allKeys %@",[dbObj allKeys]);
    
    NSLog(@"dbObj allValues %@",[dbObj allValues]);
    
    NSLog(@"dictionary %@",[dbObj dictionary]);
    
    
    [DBObj delete:[DBObj class]];
    //-----------------------------------------------------------------------
    //序列化 把对象转换成json
    //-----------------------------------------------------------------------
    [DBObj save:dbObj];
    
    
    
    DBObj *obj = [DBObj queryWithkey:@"name" value:@"BruceYu"];
    
    obj = [[DBObj query:[DBObj class] where:@"info.infoLevel1.infoLevel2.infoLevel3.infoLevel4.name4 = 'level4'"] firstObject];
    
    if (nil == obj) {
        obj = [[DBObj query:[DBObj class]] firstObject];
    }
    obj.integer = 100;
    
    
    [obj delete];
    
    
    
    [DBObj save:obj];
    
    NSLog(@"dictionary %@",[obj dictionary]);
    
    
    [obj enumerateObjectsKeysAndValues:^(NSString *key, id value, BOOL *stop) {
        
        NSLog(@"%@ = %@",key,value);
    }];
    
    obj.name = @"hello";
    [obj update];
    NSLog(@"obj %@",[obj dictionary]);
    
    
    UIImageView *imageView = [[UIImageView alloc] initWithFrame:self.window.frame];
    imageView.image = [UIImage imageWithData:obj.data];
    [self.window insertSubview:imageView atIndex:1];
    
    //-----------------------------------------------------------------------
    //数据存储 增、删、改、查
    //-----------------------------------------------------------------------
    [NSObject insert:dbObj];
    [NSObject insertObjs:@[dbObj]];
    [NSObject update:dbObj where:@"name = 'BruceYu'"];
    [NSObject save:dbObj];
    [NSObject save:dbObj withKey:@"name"];
    [NSObject save:dbObj withKeys:@[@"name"]];
    
    
    [NSObject saveObjs:@[dbObj]];
    
    [NSObject delete:[dbObj class]];
    
    [NSObject delete:dbObj WithKey:@"name"];
    
    NSArray * arry =  [NSObject query];
    NSLog(@"arry %@",arry);
    
    
    UserInfo *user = [UserInfo newModel];
    user.name = @"BruceYu";
    user.email = @"c6357@outlook.com";
    [UserInfo save:user];
    NSLog(@"user %@",[user dictionary]);
    
    DBObj *objModel = [DBObj newModel];
    NSLog(@"objModel %@",[objModel dictionary]);
    
    [DBObj save:obj];
    
    
    //归档 NSCoding
    NSString *path=[NSString stringWithFormat:@"%@/archive.archive",NSHomeDirectory()];
    [NSKeyedArchiver archiveRootObject:dbObj toFile:path];
    
    
    [NSKeyedArchiver archiveRootObject:user toFile:path];
    
    
    path=[NSString stringWithFormat:@"%@/archive1",NSHomeDirectory()];
    [NSKeyedArchiver archiveRootObject:user toFile:path];
    
    // 解档
    DBObj *person=[NSKeyedUnarchiver unarchiveObjectWithFile:path];
    NSLog(@"归档－－－%@\n解档－－－%@",path,(DBObj*)person.name);
}

@end
