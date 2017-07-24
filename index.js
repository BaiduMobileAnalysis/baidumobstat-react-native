import React, { NativeModules } from "react-native";

var BaiduMobStat = NativeModules.BaiduMobStat;
console.log("A " + BaiduMobStat);
export default NativeModules.BaiduMobStat;
