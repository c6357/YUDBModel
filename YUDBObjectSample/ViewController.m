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

@implementation ViewController



- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
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
        [arr addObject:user];
    }
    
    DBObj *obj = [[DBObj alloc] init];
    obj.name = @"test1";
    obj.phone = @"123456789";
    obj.info = user;
    obj.infoArry = arr;
    [obj save:@"name1"];
    
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

@end
