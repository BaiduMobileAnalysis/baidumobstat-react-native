//
//  BaiduMobStat.h
//  BaiduMobStat
//
//  Created by Lidongdong on 15/7/22.
//  Copyright (c) 2015年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#ifdef __IPHONE_8_0
#import <WebKit/WebKit.h>
#endif

@class UIViewController;

/**
 日志发送策略
 */
typedef enum _BaiduMobStatLogStrategy {
    BaiduMobStatLogStrategyAppLaunch = 0,   //每次程序启动时发送（默认策略，推荐使用!）
} BaiduMobStatLogStrategy;

/**
 推送平台定义
 */
typedef enum _BaiduMobStatPushPlatform{
    BaiduMobStatPushPlatformBaiduCloud = 0, //百度云推送平台
    BaiduMobStatPushPlatformJiGuang = 1,    //极光推送平台
    BaiduMobStatPushPlatformGeTui = 2,      //个推推送平台
    BaiduMobStatPushPlatformUmeng = 5,      //友盟推送平台
    BaiduMobStatPushPlatformXinGe = 6,      //信鸽推送平台
    BaiduMobStatPushPlatformAliYun = 7,     //阿里云推送平台
} BaiduMobStatPushPlatform;

/**
 信息流监控策略
 */
typedef enum _BaiduMobStatFeedTrackStrategy {
    BaiduMobStatFeedTrackStrategyAll = 0,       //全部监控
    BaiduMobStatFeedTrackStrategySingle = 1,    //单个监控，需要监控的tableviw需要设置enableListTrack属性为YES
    BaiduMobStatFeedTrackStrategyNone = 2,      //关闭feed监控，不监控任何列表
} BaiduMobStatFeedTrackStrategy;

/**
 全局扩展信息
 */
@interface BaiduMobStatExtraInfo : NSObject
@property (nonatomic, copy) NSString* v1;
@property (nonatomic, copy) NSString* v2;
@property (nonatomic, copy) NSString* v3;
@property (nonatomic, copy) NSString* v4;
@property (nonatomic, copy) NSString* v5;
@property (nonatomic, copy) NSString* v6;
@property (nonatomic, copy) NSString* v7;
@property (nonatomic, copy) NSString* v8;
@property (nonatomic, copy) NSString* v9;
@property (nonatomic, copy) NSString* v10;
@end

/**
 百度移动应用统计接口
 当前版本 5.1.1_18
 */
@interface BaiduMobStat : NSObject
/**
 以下property属性，均为可选设置。
 如需设置，必须在startWithAppId:方法前调用才可生效。
 */

/**
 设置用户自定义的用户识别id，在startWithAppId之前调用
 设置一次UserId后，用户被永久标记。传入新的userId将替换老的userId。
 传入nil或空字符串@""，可清空标记。
 自定义规则的用户识别id（可以使登录用户账号、手机号等），长度限制256字节
 */
@property (nonatomic, copy) NSString *userId;

/**
 设置app的版本号
 从4.1版本开始，默认统计CFBundleShortVersionString中的版本号（即与AppStore上一致的版本号）
 如需统计自行设定的版本号，可由此传入
 */
@property (nonatomic, copy) NSString *shortAppVersion;

/**
 设置渠道Id
 默认值为 "AppStore"
 */
@property (nonatomic, copy) NSString *channelId;

/**
 是否启用Crash日志收集
 默认值 YES
 */
@property (nonatomic) BOOL enableExceptionLog;

/**
 是否仅在wifi网络状态下才发送日志
 默认值 NO
 */
@property (nonatomic) BOOL logSendWifiOnly;

/**
 设置应用进入后台再回到前台为同一次启动的最大间隔时间，有效值范围0～600s
 例如设置值30s，则应用进入后台后，30s内唤醒为同一次启动
 默认值 30s
 */
@property (nonatomic) int sessionResumeInterval;

/**
 设置日志发送策略
 默认值 BaiduMobStatLogStrategyAppLaunch
 */
@property (nonatomic) BaiduMobStatLogStrategy logStrategy;

/**
 设置是否打印SDK中的日志，用于调试
 默认值 NO
 */
@property (nonatomic) BOOL enableDebugOn;

/**
 设置设备adid
 若有需要，开发者可自行获取到adid后传入，使统计更精确
 默认值 空字符串:@""
 */
@property (nonatomic, copy) NSString *adid;

/**
 设置是否获取GPS信息（V4.1.1新增）
 默认为YES，获取GPS信息
 */
@property (nonatomic, assign) BOOL enableGps;

/**
 设置是否允许监控webview（V4.6.7新增）
 默认为YES
 */
@property (nonatomic, assign) BOOL enableWebViewAutoTrack;

/**
 当enableWebViewAutoTrack属性设置为NO时，该接口无效，可忽略。
 当多个webview的delegate类存在继承关系时，为了避免因调用super方法而导致的死循环风险，可以设置是否只统计子类Delegate（V4.9.5新增）
 备注：在webview的delegate方法中没有调用super方法的情况下，不受影响。此时为了保证数据完整，不建议设置为YES。
 默认为NO
 */
@property (nonatomic, assign) BOOL onlyTrackSubClassOfWebDelegate;

/**
 设置UIViewController是否监控（V4.6.7新增）
 默认为YES
 */
@property (nonatomic, assign) BOOL enableViewControllerAutoTrack;

/**
 设置是否优先使用“类名”进行UIViewController的页面统计（V5.0.0新增）
 默认为NO，即优先使用页面title进行统计，没有title情况下再使用类名统计
 （推荐）设置为YES，即使用类名进行页面统计，统计效果更准确、聚合度更高
 */
@property (nonatomic, assign) BOOL trackViewControllerWithClassName;

/**
 设置控件点击event事件是否监控（V4.8.3新增）
 默认为YES
 */
@property (nonatomic, assign) BOOL enableEventAutoTrack;

/**
 设置是否允许推送文案的采集，用于启动来源分析（V4.9.5新增）
 默认为YES
 */
@property (nonatomic, assign) BOOL enableGetPushContent;

/**
 设置TableView监控策略（V4.8.0新增）
 默认为BaiduMobStatFeedTrackStrategyAll，全部监控
 设置为BaiduMobStatFeedTrackStrategySingle单个监控，则要监控的tableview需要设置enableListTrack属性为YES
 设置为BaiduMobStatFeedTrackStrategyNone，则不监控任何列表
 */
@property (nonatomic, assign) BaiduMobStatFeedTrackStrategy feedTrackStrategy;

/**
 设置是否使用启动来源分析功能（V4.9.5新增）
 默认为YES
 */
@property (nonatomic, assign) BOOL enableLaunchRefererTrack;

/**
 设置Crash日志中附带的信息
 长度限制256字节，超出截断
 */
@property (nonatomic, copy) NSString *crashExtraInfo;

/**
 获取统计对象的实例
 
 @return 一个统计对象实例
 */
+ (BaiduMobStat *)defaultStat;

/**
 设置用户自定义的用户属性信息，在startWithAppId之前调用
 设置一次UserPorperty后，属性与该设备绑定。传入新的UserPorperty将替换老的UserPorperty内容。
 传入nil，可清空标记。
 key值为用户提前在网站创建的“属性名称”，若没有提前创建，则无统计效果。最多传入100个key值，超出部分无效
 每个value长度限制256字节
 调用例子见demo工程
 */
- (void)setUserProperty:(NSDictionary *)userProperty;

/**
 设置应用的appkey，启动统计SDK。
 注意！！！以下行为Api调用前，必须先调用该接口。
 
 @param appKey 用户在mtj网站上创建应用，获取对应的appKey
 */
- (void)startWithAppId:(NSString *)appKey;

/**
 设置全局附加信息
 此API调用后的日志信息才会有全局附加信息
 若多次调用，后续调用会覆盖之前的信息，以最后一次调用为准
 
 @param info 全局附加信息
 */
- (void)setGlobalExtraInfo:(BaiduMobStatExtraInfo*) info;

/**
 清空全局附加信息
 */
- (void)clearGlobalExtraInfo;

/**
 记录一次事件的点击，eventId请在网站上创建。未创建的evenId记录将无效。
 
 @param eventId 自定义事件Id，提前在网站端创建
 @param eventLabel 自定义事件Label，附加参数，不能为空字符串
 */
- (void)logEvent:(NSString *)eventId eventLabel:(NSString *)eventLabel;

/**
 记录一次事件的时长，eventId请在网站上创建。未创建的evenId记录将无效。
 
 @param eventId 自定义事件Id，提前在网站端创建
 @param eventLabel 自定义事件Label，附加参数，不能为空字符串
 @param duration 已知的自定义事件时长，单位为毫秒（ms）
 */
- (void)logEventWithDurationTime:(NSString *)eventId eventLabel:(NSString *)eventLabel durationTime:(unsigned long)duration;

/**
 记录一次事件的开始，eventId请在网站上创建。未创建的evenId记录将无效。
 
 @param eventId 自定义事件Id，提前在网站端创建
 @param eventLabel 自定义事件Label，附加参数，不能为空字符串
 */
- (void)eventStart:(NSString *)eventId eventLabel:(NSString *)eventLabel;

/**
 记录一次事件的结束，eventId请在网站上创建。未创建的evenId记录将无效。
 
 @param eventId 自定义事件Id，提前在网站端创建
 @param eventLabel 自定义事件Label，附加参数，不能为空字符串
 */
- (void)eventEnd:(NSString *)eventId eventLabel:(NSString *)eventLabel;

/**
 记录一次事件的点击，eventId和对应的attribute的key请在网站上创建，未创建的evenId和key将无法统计。
 
 @param eventId 事件Id，提前在网站端创建
 @param eventLabel 事件标签，附加参数，不能为空字符串
 @param attributes 事件属性，对应的key需要在网站上创建，注意：value只接受NSString
 */
- (void)logEvent:(NSString *)eventId eventLabel:(NSString *)eventLabel attributes:(NSDictionary *)attributes;

/**
 记录一次事件的时长，eventId和对应的attribute的key请在网站上创建，未创建的evenId和key将无法统计。
 
 @param eventId 自定义事件Id，提前在网站端创建
 @param eventLabel 自定义事件Label，附加参数，不能为空字符串
 @param duration 已知的自定义事件时长，单位为毫秒（ms）
 @param attributes 事件属性，对应的key需要在网站上创建，注意：value只接受NSString
 */
- (void)logEventWithDurationTime:(NSString *)eventId eventLabel:(NSString *)eventLabel durationTime:(unsigned long)duration attributes:(NSDictionary *)attributes;

/**
 记录一次事件的结束，eventId和对应的attribute的key请在网站上创建，未创建的evenId和key将无法统计。
 
 @param eventId 自定义事件Id，提前在网站端创建
 @param eventLabel 自定义事件Label，附加参数，不能为空字符串
 @param attributes 事件属性，对应的key需要在网站上创建，注意：value只接受NSString
 */
- (void)eventEnd:(NSString *)eventId eventLabel:(NSString *)eventLabel attributes:(NSDictionary *) attributes;

/**
 记录某个页面访问的开始，请参见Example程序，在合适的位置调用。
 建议在ViewController的viewDidAppear函数中调用
 
 @param name 页面名称
 */
- (void)pageviewStartWithName:(NSString *)name;

/**
 记录某个页面访问的结束，与pageviewStartWithName配对使用，请参见Example程序，在合适的位置调用。
 建议在ViewController的viewDidDisappear函数中调用
 
 @param name 页面名称
 */
- (void)pageviewEndWithName:(NSString *)name;

/**
 记录WkWebView中的行为（需要在网页的JS代码中进行相应配置，详见文档与Demo程序）
 在WkWebview的代理方法:
 -(void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message
 中，调用此接口，传入参数为message.name和message.body，开始统计JS中的操作
 
 @param name WKScriptMessage的name
 @param body WKScriptMessage的body 只接受NSDictionary类型
 */
- (void)didReceiveScriptMessage:(NSString*)name body:(NSDictionary *)body;

/**
 主动上传的Exception信息记录
 
 @param exception 自己捕获的，需要上传的exception
 */
- (void)recordException:(NSException *)exception;

/**
 主动上传的NSError信息记录
 
 @param error 自己捕获的，需要上传的error
 */
- (void)recordError:(NSError *)error;

/**
 获取cuid的值
 返回SDK生成的cuid
 
 @return 设备Cuid
 */
- (NSString *)getDeviceCuid;

/**
 获取设备的测试ID，同时有Log打印
 返回SDK生成的设备测试ID
 
 @return 设备测试ID
 */
- (NSString *)getTestDeviceId;

/**
 上传第三方Push平台的Id，pushId长度限制1024字节。设置为nil或者空字符串，则清空对应平台的pushId
 
 @prama pushId 从第三方Push SDK接口中获取的pushId
 @prama platform 指定Push平台类型，详见枚举声明
 */
- (void)setPushId:(NSString *)pushId platform:(BaiduMobStatPushPlatform)platform;
@end

/**
 Category 声明
 */
@interface UIViewController (BaiduMobStatViewController)
/**
 是否禁用自动收集此页面，默认为NO
 */
@property (nonatomic, assign) BOOL disableBaiduMobAutoRecord;

/**
 手动设置自动收集的页面名称
 */
@property (nonatomic, copy) NSString *titleForBaiduMobStat;

// SDK内部属性，不要设置
#define UIViewControllerInternalDefine @property (nonatomic, strong) UIScrollView *contentScorllView;@property (nonatomic, strong) NSNumber *pageStartTime;@property (nonatomic, copy) NSString *userHandle;@property (nonatomic, copy) NSString *eventTitle;@property (nonatomic, strong) NSDictionary *mtjDictionary;@property (nonatomic, strong) NSNumber *titleCount;
UIViewControllerInternalDefine

@end

/**
 百度移动统计UIWindow Category
 */
@interface UIWindow (BaiduMobStatWindow)
@end

/**
 百度移动统计UIView Category
 */
@interface UIView (BaiduMobStatView)

/**
 手动设置自动收集的附加信息
 对应的key需要在网站上创建，注意：value只接受NSString
 */
@property (nonatomic, strong) NSDictionary *attributesForBaiduMobStat;

// SDK内部属性，不要设置
#define UIViewInternalDefine @property (nonatomic, copy) NSString *hasTable;
UIViewInternalDefine
@end

/**
 百度移动统计NSInvocation Category
 */
@interface NSInvocation (BaiduMobStat)
- (id)baiduMtj_returnValue;
@end

/**
 百度移动统计WKWebView Category
 */
#ifdef __IPHONE_8_0
@interface WKWebView (BaiduMobStatWKWebView)
@property (nonatomic, assign) BOOL mtjCallBack;

@end
#endif

@interface UIScrollView (BaiduMobStatScrollView)

@end

/**
 百度移动统计UITableView Category
 */
@interface UITableView (BaiduMobStatTableView)

/**
 设置TableView的栏目名称，为MTJ分析信息流报表中的”栏目名称“,长度限制256字节，超出截断
 如果不设置，则默认采用tableview所在的Controller title作为“栏目名称”
 建议在TableView加载前设置。
 */
@property (nonatomic, copy) NSString *listName;

/**
 设置单个TableView是否需要被监控
 默认情况下，sdk监控全局TableView，不需要设置该接口
 当设置了全局关闭之后，可以设置单个tableview打开指定的TableView监控
 */
@property (nonatomic, assign) BOOL enableListTrack;

// SDK内部属性，不要设置
#define UITableViewInternalDefine @property (atomic, copy) NSString *viewLevel;@property (atomic, copy) NSString *viewStatu;@property (atomic, strong) NSArray *lastCellArr;@property (atomic, copy) NSString *autoName;@property (atomic, strong) NSNumber *lastTime;@property (atomic, strong) NSNumber *startTime;@property (atomic, strong) NSNumber *endTime;
UITableViewInternalDefine
@end

@interface UITableViewCell (BaiduMobStatTableViewCell)

/**
 设置Cell的信息Title，为MTJ分析信息流报表中的”信息标题“,长度限制256字节，超出截断
 如果不设置，则SDK会自动识别一个Title
 建议在cell加载前设置。
 */
@property (nonatomic, copy) NSString *contentTitle;

/**
 设置Cell的信息ID，是用户自身系统中的内容id,长度限制256字节，超出截断
 如果不设置，则id为空
 建议在cell加载前设置。
 */
@property (nonatomic, copy) NSString *contentId;

@end

@interface UIApplication (BaiduMobStatApplication)
@end

void import_BaiduMobStatViewController ();
void import_BaiduMobStatWindow ();
void import_BaiduMobStatView ();
void import_BaiduMobStatWKWebView ();
void import_BaiduMobStatNSInvocation ();
void import_BaiduMobStatScrollView ();
void import_BaiduMobStatTableView ();
void import_BaiduMobStatTableViewCell ();
void import_BaiduMobStatApplication ();
