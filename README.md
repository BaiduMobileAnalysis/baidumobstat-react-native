# baidumobstat-react-native
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
