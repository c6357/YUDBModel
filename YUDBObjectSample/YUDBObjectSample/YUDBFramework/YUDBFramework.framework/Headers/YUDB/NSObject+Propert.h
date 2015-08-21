//
//       \\     //    ========     \\    //
//        \\   //          ==       \\  //
//         \\ //         ==          \\//
//          ||          ==           //\\
//          ||        ==            //  \\
//          ||       ========      //    \\
//
//  NSObject+Propert.h
//  YUDBObject
//
//  Created by BruceYu on 15/8/18.
//  Copyright (c) 2015年 BruceYu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "DB+Constant.h"

@interface NSObject (Propert)

+ (void)enumerateObjectsKeys:(DB_Block_ParserForArrayVoidPlus)enumeration;

- (void)enumerateObjectsKeys:(DB_Block_ParserForArrayVoid)enumeration;

@end
