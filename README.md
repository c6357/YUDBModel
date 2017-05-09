YUDBModel
=========
-
[![Travis branch](https://img.shields.io/travis/rust-lang/rust/master.svg)](https://github.com/c6357/YUDBModel)
[![CocoaPods](https://img.shields.io/cocoapods/v/YUDBModel.svg)](https://github.com/c6357/YUDBModel)


### 一、YUDBModel 介绍
* 

### 二、YUDBModel 集成
* 手动复制YUDBModel到工程
* 使用Cocoapods管理


### 三、YUDBModel 使用

#### YUDBModel配置
	///设置数据库路径
	extern void YUDBModel_SetupDBPath(NSString *path);
	
	///设置对象归档路径
	extern void YUDBModel_SetupObjectPath(NSString *path);
	
	///设置数据库版本号
	extern void YUDBModel_SetupDBVersion(NSString *version);
	
	///打开日志输出
	extern void YUDBModel_SetDBLog(BOOL on);
	
	///删除数据库文件
	extern BOOL YUDBModel_ClearDBFile();
	
#### 反序列化 

```oc
///把json转换成对象	
DBObj *dbObj = [DBObj modelWithDictionary:json];
```
	
```oc
/**
 反序列化JSON需要替换的KEY
 
 @return @{@"mode key":@"json key"}
 */
+(NSDictionary <NSString *, NSString*> *)YUDBModel_ReplacePropertyKey;

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


/**
 反序列化json自定义操作（通常用于NSArray和特殊处理）
 
 @param key key值
 @param value value值
 @return 根据key和value返回相应的对象
 
 e.g.
 -(void)deserialize:(NSDictionary *)dictionary
 {
	 [super deserialize:dictionary arrayParser:^id(NSString *key,id value) {
	 
		 if ([key isEqualToString:@"list"]) {
		 
			 return [UserInfo class];
		 }
		 
		 else if ([key isEqualToString:@"array"]) {
		 
			 return @[@"1",@"2",@"3"];//自定义数组
		 }
		 
		 else if ([key isEqualToString:@"name"]) {
		 
		 	return @"自定义名字";
		 }
		 
 		return nil;
 		
	 }];
	 
 }
```


#### 序列化
	///把对象转换成json
	NSDictionary * json = [dbObj dictionary];
	
#### 数据存储 增、删、改、查


	
	