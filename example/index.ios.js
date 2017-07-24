/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from "react";
import { AppRegistry, StyleSheet, Text, View, Button } from "react-native";
import BaiduMobStat from "baidumobstat-react-native";

export default class example extends Component {
  onEvent() {
    BaiduMobStat.onEvent("event1", "事件一");
  }

  onEventDuration() {
    BaiduMobStat.onEventDuration("event2", "事件二", 1000);
  }

  onEventStart() {
    BaiduMobStat.onEventStart("event3", "事件三");
  }

  onEventEnd() {
    BaiduMobStat.onEventEnd("event3", "事件三");
  }

  onEventWithAttributes() {
    BaiduMobStat.onEventWithAttributes("event4", "事件四", { 分类: "分类一" });
  }

  onEventWithAttributesDuration() {
    BaiduMobStat.onEventDurationWithAttributes("event5", "事件五", 1000, {
      分类: "分类一"
    });
  }

  onEventStartAttribute() {
    BaiduMobStat.onEventStart("event6", "事件六");
  }

  onEventEndWithAttributes() {
    BaiduMobStat.onEventEndWithAttributes("event6", "事件六", { 分类: "分类一" });
  }

  onPageStart() {
    BaiduMobStat.onPageStart("页面一");
  }

  onPageEnd() {
    BaiduMobStat.onPageEnd("页面一");
  }
  render() {
    return (
      <View style={styles.container}>
        <Button onPress={() => this.onEvent()} title="事件一" />
        <Button onPress={() => this.onEventDuration()} title="事件二" />
        <Button onPress={() => this.onEventStart()} title="事件三开始" />
        <Button onPress={() => this.onEventEnd()} title="事件三结束" />
        <Button onPress={() => this.onEventWithAttributes()} title="事件四（带属性）" />
        <Button
          onPress={() => this.onEventWithAttributesDuration()}
          title="事件五"
        />
        <Button
          onPress={() => this.onEventStartAttribute()}
          title="事件六开始（带属性）"
        />
        <Button
          onPress={() => this.onEventEndWithAttributes()}
          title="事件六结束（带属性）"
        />
        <Button
          onPress={() => this.onPageStart()}
          title="页面开始"
          color="#841584"
        />
        <Button onPress={() => this.onPageEnd()} title="页面结束" color="#841584" />
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center",
    backgroundColor: "#F5FCFF"
  },
  welcome: {
    fontSize: 20,
    textAlign: "center",
    margin: 10
  },
  instructions: {
    textAlign: "center",
    color: "#333333",
    marginBottom: 5
  }
});

AppRegistry.registerComponent("example", () => example);
