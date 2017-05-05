//
//       \\     //    ========     \\    //
//        \\   //          ==       \\  //
//         \\ //         ==          \\//
//          ||          ==           //\\
//          ||        ==            //  \\
//          ||       ========      //    \\
//
//  NSObject+YUDBModel.h
//  https://github.com/c6357/YUDBModel
//
//  Created by BruceYu on 15/8/18.
//  Copyright (c) 2015年 BruceYu. All rights reserved.
//

#import <Foundation/Foundation.h>

///删除数据库文件
extern BOOL YUDBModel_ClearDBFile();

///设置数据库路径
extern void YUDBModel_SetupDBPath(NSString *path);

///设置数据库版本号
extern void YUDBModel_SetupDBVersion(NSString *version);

///打开日志输出
extern void YUDBModel_SetDBLog(BOOL on);


@protocol YUDBModelDataSource <NSObject>
@optional

/**
 反序列化JSON需要替换的KEY

 @return @{@"mode key":@"json key"}
 */
+(NSDictionary<NSString *, NSString*>*)YUDBModel_ReplacePropertyKey;

/**
 需要过滤在数据库表中的特殊字段 不储存的字段
 
 @return  e.g. return @[@"desrc"]
 */
+(NSArray<NSString*> *)YUDBModel_IgnoreFields;

/**
 设置主键
 
 @return 主键的 keyName
 */
+(NSString*)YUDBModel_PrimaryKey;

@end



#pragma mark -
#pragma mark - 数据模型
@interface NSObject(YUDBModel)<YUDBModelDataSource>

/**
 初始化模型对象
 
 @param dictionary <#dictionary description#>
 @return 返回一个模型对象 初始化失败返回空
 */
+ (instancetype)modelWithDictionary:(NSDictionary *)dictionary;

/**
 初始化模型对象
 
 @param dictionary <#dictionary description#>
 @return 返回一个模型对象 初始化失败返回空
 */
- (instancetype)initModelWithDictionary:(NSDictionary *)dictionary;


/**
 初始化一个NSObject对象 优化[NSObject new]
 初始化成员👉再也不用担心APP界面上有null
 
 @return NSObject对象
 */
+ (instancetype)newModel;

#pragma mark -
#pragma mark - 数据存储

/**
 更新当前对象在数据库的数据
 
  @return 更新结果
 */
- (BOOL)update;

/**
 储存当前对象到数据库

 @param key 对象的keyName
 @return 储存结果
 */
- (BOOL)save:(NSString*)key;

/**
 删除当前对象数据在数据库的数据

 @return 删除结果
 */
- (BOOL)delete;

@end


@interface NSObject (DB)

/**
 数据库路径

 @return 路径
 */
+(NSString *)dbPath;


/**
 数据库版本

 @return 版本号
 */
+(NSString *)dbVersion;

#pragma mark -
#pragma mark - 增删改查

#pragma mark -增 改
/**
 直接插入数据
 */

+ (BOOL)insert:(NSObject*)object;
/**
 直接插入多条数据
 */

+ (BOOL)insertObjs:(NSArray*)objects;

/**
 更新一条数据（只执行更新语句）
 */

+ (BOOL)update:(NSObject*)object where:(NSString *)where;

/**
 保存一条数据（if数据存在更新else插入 仅限于YUDBModel对象）

 @param object 数据模型对象
 @return 操作结果
 */
+ (BOOL)save:(NSObject*)object;


/**
  保存多条数据（if数据存在更新else插入 仅限于YUDBModel对象）

 @param objects 数据模型对象
 @return 操作结果
 */
+ (BOOL)saveObjs:(NSArray *)objects;

/**
  保存一条数据（if数据存在更新else插入）

 @param object 数据模型对象
 @param key （以object对象的某个属性和属性值作为WHERE查询条件，该key的value值必须为唯一值）
 @return 操作结果
 */
+ (BOOL)save:(NSObject*)object withKey:(NSString*)key;

/**
 保存一条数据（if数据存在更新else插入）
 
 @param object 数据模型对象
 @param keys （以object对象的多个属性和属性值作为WHERE查询条件，该key的value值必须为唯一值）
 @return 操作结果
 */
+ (BOOL)save:(NSObject*)object withKeys:(NSArray*)keys;


#pragma mark - 删

/**
 删除默认数据文件

 @return 操作结果
 */
+ (BOOL)clearDB;


/**
 删除表[obj Class]

 @param objClass 数据模型
 @return 操作结果
 */
+ (BOOL)delete:(Class)objClass;

/**
 根据条件删除表[object class]数据

 @param object 数据模型对象
 @param key （以object对象的某个属性和属性值作为WHERE查询条件，该key的value值必须为唯一值）
 @return 操作结果
 */
+ (BOOL)delete:(NSObject*)object WithKey:(NSString *)key;

/**
 根据条件删除表[object class]数据
 
 @param object 数据模型对象
 @param keys （以object对象的多个属性和属性值作为WHERE查询条件，该key的value值必须为唯一值）
 @return 操作结果
 */
+ (BOOL)delete:(NSObject*)object withKeys:(NSArray*)keys;

/**
 根据条件删除表[obj Class]数据
 
 @param objClass 数据模型
 @param where 删除条件
 @return 操作结果
 */
+ (BOOL)delete:(Class)objClass where:(NSString *)where;


#pragma mark - 简单查询
/**
 查询表[self class]所有数据

 @return array
 */
+ (NSArray *)query;

/**
  查询表[obj Class]所有数据

 @param objClass 数据模型
 @return array
 */
+ (NSArray *)query:(Class)objClass;

/**
  查询表[self class]数据

 @param key 查询条件键key
 @param value 查询条件键valus
 @return 符合条件的第一条数据
 */
+ (id)queryWithkey:(NSString*)key value:(NSString*)value;

/**
   查询表[self class]数据

 @param key 查询条件键key
 @param value 查询条件键valus
 @return array
 */
+ (NSArray *)query:(NSString*)key value:(NSString*)value;

/**
    查询表[self class]数据

 @param keyValues 查询条件键的{key:valus}
 @return array
 */
+ (NSArray *)queryWithkeyValues:(NSDictionary*)keyValues;


#pragma mark - 高级查询

/**
 查询表[obj Class]数据

 @param objClass 数据模型
 @param where where条件
 @return array
 */
+ (NSArray *)query:(Class)objClass where:(NSString *)where;


/**
  查询表[obj Class]数据

 @param objClass 数据模型
 @param order order by 条件
 @return array
 */
+ (NSArray *)query:(Class)objClass order:(NSString *)order;


/**
  查询表[obj Class]数据

 @param objClass 数据模型
 @param limit LIMIT 语句
 @return array
 */
+ (NSArray *)query:(Class)objClass limit:(NSString *)limit;


/**
 查询表[obj Class]数据
 
 @param objClass 数据模型
 @param where where条件
 @param order order by
 @return array
 */
+ (NSArray *)query:(Class)objClass where:(NSString *)where order:(NSString *)order;

/**
 查询表[obj Class]数据
 
 @param objClass 数据模型
 @param where where条件
 @param limit limit
 @return array
 */
+ (NSArray *)query:(Class)objClass where:(NSString *)where limit:(NSString *)limit;


/**
 查询表[obj Class]数据
 
 @param objClass 数据模型
 @param order order by
 @param limit limit
 @return array
 */
+ (NSArray *)query:(Class)objClass order:(NSString *)order limit:(NSString *)limit;


/**
 查询表[obj Class]数据

 @param objClass 数据模型
 @param where where条件
 @param order order by
 @param limit limit
 @return array
 */
+ (NSArray *)query:(Class)objClass where:(NSString *)where order:(NSString *)order limit:(NSString *)limit;


#pragma mark - 自助高级查询
/**
  查询数据
 @param objClass 需要反序列化的数据模型objClass
 @param sql 纯sql语句
 @return array @[objClass,objClass,objClass.....]
 */
+ (NSArray *)query:(Class)objClass sql:(NSString *)sql;


/**
 执行一条sql更新语句

 @param sql 纯sql语句
 @return 执行结果
 */
+ (BOOL)executeUpdateWithSql:(NSString *)sql;

@end

