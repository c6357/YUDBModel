YUDBModel
=========
-
[![Travis branch](https://img.shields.io/travis/rust-lang/rust/master.svg)](https://github.com/c6357/YUDBModel)
[![CocoaPods](https://img.shields.io/cocoapods/v/YUDBModel.svg)](https://github.com/c6357/YUDBModel)


### 一、YUDBModel 介绍


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
	///把json转换成对象	
	DBObj *dbObj = [DBObj modelWithDictionary:json];


#### 序列化
	///把对象转换成json
	NSDictionary * json = [dbObj dictionary];
	
#### 数据存储 增、删、改、查
	
	