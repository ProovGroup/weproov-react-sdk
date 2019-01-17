/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow
 */

import React, {Component} from 'react';
import {Platform, StyleSheet, Text, View, NativeModules, TextInput, Button} from 'react-native';

const instructions = Platform.select({
  ios: 'Press Cmd+R to reload,\n' + 'Cmd+D or shake for dev menu',
  android:
    'Double tap R on your keyboard to reload,\n' +
    'Shake or press menu button for dev menu',
});

type Props = {};
export default class App extends Component<Props> {
  constructor(props) {
    super(props);
    this.state = {
      status: 'Loading...',
      proovCode: 'M8FBSU'
    };
  }

  componentDidMount() {
    this.connect()
  }

  connect() {
    NativeModules.WPReportUploaderPlugin.sync();

    NativeModules.RNWeproov.setTheme({
      reportArchivedColor: "#cccccc",
      sectionHeaderDateFont: ["AvenirNext-Bold", 24]
    }, (error) => {
      console.log("[WeProovSDK] failed to set theme", error);
    });

    this.setState({status: "Connecting"})

    NativeModules.WPUserPlugin.connect(
      "YOUR_TOKEN",
      "YOUR_SECRET",
      (error) => {
        if (error) {
          this.setState({status: `Failed to connect: ${error}`})
          return
        }

        this.setState({status: "Connected"})
      }
    );
  }

  loadReport() {
    if (!this.state.proovCode || this.state.proovCode.length == 0) {
      this.setState({status: "No ProovCode given"})
      return
    }

    NativeModules.WPUserPlugin.isConnected((connected) =>{
      if (connected == 0) {
        this.setState({status: "Need to be connected"})
        return
      }

      this.setState({status: "Loading report"})

      NativeModules.RNWeproov.loadProovCode(this.state.proovCode, (error) => {
        if (error) {
          this.setState({status: `Failed to open: ${error}`})
        }
        else {
          this.setState({status: "Report loaded"})
        }
      })
    })
  }

  render() {
    return (
      <View style={styles.container}>
        <Text style={styles.welcome}>WeProovSDK</Text>
        <Text style={styles.instructions}>{this.state.status}</Text>
        <TextInput style={styles.input} placeholder="ProovCode" value={this.state.proovCode} onChangeText={(proovCode) => this.setState({proovCode})}/>
        <Button onPress={() => this.loadReport()} title="Load report" />
        <Text style={styles.instructions}>{instructions}</Text>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
  welcome: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
  },
  instructions: {
    textAlign: 'center',
    color: '#333333',
    marginTop: 10,
    marginBottom: 5,
  },
  input: {
    textAlign: 'center',
    color: '#333333',
    minWidth: 200,
    textTransform: 'uppercase',
    padding: 5,
    borderWidth: 1,
    borderStyle: 'solid',
    borderColor: 'black'
  }
});
