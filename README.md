# baidumobstat-react-native

##iOS
- 新建一个React Native工程，参考[React Native 官网](https://facebook.github.io/react-native/)

     ```bash
     react-native init hello
     cd hello
     yarn add baidumobstat-react-native
     react-native link
     ```

- 在iOS工程的Linked Frameworks and Libraries, 加入以下依赖
```
libz.tbd
libc++.tbd
libicucore.tbd
```

- 在 iOS 工程中如果找不到头文件可能要在 TARGETS-> BUILD SETTINGS -> Search Paths -> Header Search Paths 添加如下路径

    ```
    $(SRCROOT)/../node_modules/jpush-react-native/ios/RCTJPushModule/RCTJPushModule
    ```
    
- 打开ios下的工程，在AppDelegate.m内添加百度移动统计的启动代码
  
     ```objc
     #import "BaiduMobStat.h"
     
     // - (BOOL)application: didFinishLaunchingWithOptions:
     [[BaiduMobStat defaultStat] startWithAppId:@"xxx"];
     ```
 
- 在App.js 内使用对应的接口


##Android
* 新建一个React Native工程，参考[React Native 官网](https://facebook.github.io/react-native/)，添加百度移动统计react native插件支持
	
	```
	yarn add baidumobstat-react-native
	```
* 配置AndroidManifest.xml
	
	添加权限：
	
	```
	<uses-permission android:name="android.permission.INTERNET" />
	<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
	<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
	<uses-permission android:name="android.permission.READ_PHONE_STATE" />
	<uses-permission android:name="android.permission.WRITE_SETTINGS" />
	<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
	<uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" />
	<uses-permission android:name="android.permission.GET_TASKS" />
	<uses-permission android:name="android.permission.BLUETOOTH" />
	<uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
	<uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" />
	```
	
	添加数据配置：
	
	```
	     <!-- 您从百度网站获取的APP KEY -->
        <meta-data
            android:name="BaiduMobAd_STAT_ID"
            android:value="your appkey" /> 
        <!-- 渠道商编号 -->
        <meta-data
            android:name="BaiduMobAd_CHANNEL"
            android:value="Baidu Market" />
        <!-- 是否开启错误日志统计，默认为false -->
        <meta-data
            android:name="BaiduMobAd_EXCEPTION_LOG"
            android:value="true" />
        <meta-data
            android:name="BaiduMobAd_ONLY_WIFI"
            android:value="false" />
        <!-- 是否获取基站位置信息 ,默认为true -->
        <meta-data
            android:name="BaiduMobAd_CELL_LOCATION"
            android:value="true" />
        <!-- 是否获取GPS位置信息，默认为true -->
        <meta-data
            android:name="BaiduMobAd_GPS_LOCATION"
            android:value="true" />
        <!-- 是否获取WIFI位置信息，默认为true -->
        <meta-data
            android:name="BaiduMobAd_WIFI_LOCATION"
            android:value="true" />
	```
	
* 配置gradle
	
	project build.gradle，android studio项目默认已经配置好：
	
	```
	allprojects {
   		repositories {
        	jcenter()
    	}
	}
	```
	module build.gradle，需要添加如下配置：
	
	标准统计SDK:
	
	```
	dependencies {
    	compile 'com.baidu.mobstat:mtj-sdk:latest.integration'
	}
	```
	
* 在App.js 内使用对应的接口
