# react-native-weproov

This is a cordova adapter for:
- [weproov-ios-sdk](https://github.com/ProovGroup/weproov-ios-sdk)
- [AndroidSDK](https://github.com/ProovGroup/AndroidSDK)

## Installation

  $ npm install --save react-native-weproov
  $ react-native link react-native-weproov

### Requirements iOS

- add keys `NSCameraUsageDescription`, `NSContactsUsageDescription` and `NSLocationWhenInUseUsageDescription` to `Info.plist`
- disable bitcode
- set `Background Fetch` for `Background Mode`

Create a `Podfile` in `ios/Podfile`:

```
platform :ios, '10.0'
use_frameworks!

target "example" do
  pod 'RNWeproov'
  pod 'WeProovSDK'

  # https://facebook.github.io/react-native/docs/integration-with-existing-apps.html
  # Your 'node_modules' directory is probably in the root of your project,
  # but if not, adjust the `:path` accordingly
  pod 'React', :path => '../node_modules/react-native', :subspecs => [
    'Core',
    'CxxBridge', # Include this for RN >= 0.47
    'DevSupport', # Include this to enable In-App Devmenu if RN >= 0.43
    'RCTText',
    'RCTNetwork',
    'RCTWebSocket', # Needed for debugging
    'RCTAnimation', # Needed for FlatList and animations running on native UI thread
    # Add any other subspecs you want to use in your project
  ]
  # Explicitly include Yoga if you are using RN >= 0.42.0
  pod 'yoga', :path => '../node_modules/react-native/ReactCommon/yoga'

  # Third party deps podspec link
  pod 'DoubleConversion', :podspec => '../node_modules/react-native/third-party-podspecs/DoubleConversion.podspec'
  pod 'glog', :podspec => '../node_modules/react-native/third-party-podspecs/glog.podspec'
  pod 'Folly', :podspec => '../node_modules/react-native/third-party-podspecs/Folly.podspec'
end
```

Update your `AppDelegate.m`:

```
@import WeProovSDK;

@implementation AppDelegate

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
    [[WPReportUploader shared] sync];
    /* ... */
}

- (void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)(void))completionHandler
{
    if ([[WPReportUploader shared] handleEventsForBackgroundURLSessionWithIdentifier:identifier completionHandler:completionHandler]) {
        return;
    }
    
    completionHandler();
}

@end
```

## Usage

Connection:

```
NativeModules.WPUserPlugin.connect(
  "YOUR TOKEN",
  "YOUR SECRET",
  function(error) {
    if (error) {
      // Cannot log user
    }
    else {
      // User logged
    }
  }
);
```

Open a report:

```
// Location must be accepted before openning a report
NativeModules.WPLocationServicePugin.startUpdateLocation();

NativeModules.WeProovSDKPlugin.loadProovCode(
  "YOUR PROOVCODE",
  function(error) {
    if (error) {
      // Cannot load report
    }
    else {
      // Report loaded and open
    }
  }
);
```

Customize design:

```
NativeModules.WeProovSDKPlugin.setTheme({
    reportArchivedColor: "#cccccc",
    sectionHeaderDateFont: ["AvenirNext-Bold", 24]
  },
  function(error) {
    if (error) {
      // failed to set theme
    }
    else {
      // successfully set theme
    }
  }
);
```

The list of attributes are in `WPTheme` object:

- reportInitialColor
- reportFinalColor
- reportArchivedColor
- headerBackgroundColor
- headerBorderColor
- headerItemIndexColor
- headerItemIndexBackgroundColor
- headerItemIndexFont
- headerItemErrorColor
- headerItemErrorBackgroundColor
- headerItemErrorFont
- sectionHeaderDateTextColor
- sectionHeaderDateFont
- sectionHeaderInfoTextColor
- sectionHeaderInfoFont
- sectionHeaderImportTextColor
- sectionHeaderImportFont
- sectionBackgroundColor
- fieldSetBackgroundColor
- fieldSetTitleColor
- fieldSetTitleFont
- fieldSetSubtitleColor
- fieldSetSubtitleFont
- fieldSetLegendColor
- fieldSetLegendFont
- fieldSetBorderColor
- fieldInitialValueFont
- fieldInitialValueColor
- fieldInitialValueDifferenceColor
- fieldLabelFont
- fieldLabelDefaultColor
- fieldLabelErrorColor
- fieldBorderDefaultColor
- fieldBorderErrorColor
- fieldPlaceholderAndValueFont
- fieldPlaceholderColor
- fieldValueDefaultColor
- fieldValueErrorColor
- fieldValueEmptyColor
- fieldNumericValueFont
- fieldNumericValueColor
- fieldSwitchValueFont
- fieldSwitchValueColor
- fieldSwitchOffColor
- fieldSwitchOnColor
- fieldPhotoContainerBackgroundColor
- fieldPhotoContainerBorderColor
- fieldPhotoContainerBorderValidColor
- fieldPhotoContainerBorderErrorColor
- fieldPhotoBackgroundColor
- fieldPhotoPlaceholderColor
- fieldPhotoValidColor
- fieldPhotoTextColor
- fieldPhotoTextFont
- fieldPhotoStartTextColor
- fieldPhotoStartTextFont
- fieldPhotoAddTextFont
- fieldPhotoAnnotationFont
- fieldPhotoAnnotationTextColor
- fieldPhotoAnnotationBackgroundColor
- navigationBarBackgroundColor
- navigationBarTitleFont
- navigationBarTitleColor
- navigationBarItemsFont
- summaryLabelFont
- listBackgroundColor
- listTitleFont
- listTitleColor
- listCloseFont
- listCloseColor
- listSeparatorColor
- listCellFont
- listCellColor
- listCellSelectedBackgroundColor
- listSearchFont
- listSearchColor
- listSearchBackgroundColor
- signatureBackgroundColor
- signatureHeaderSectionFont
- signatureHeaderSectionColor
- signatureHeaderInfoFont
- signatureHeaderInfoColor
- signatureFooterFont
- signatureFooterBackgroundColor
- signatureFooterColor
- cameraBackgroundColor
- cameraHeaderTintColor
- cameraFooterButtonFont
- cameraFooterButtonColor
- cameraFooterImageStateFont
- cameraFooterButtonCloseColor
- cameraFooterButtonCloseFont
- cameraFooterButtonCloseBackgroundColor
- cameraContentLabelFont
- cameraContentLabelColor
- cameraContentLabelSeparatorColor
- cameraContentLabelBackgroundColor
- cameraContentLabelValidBackgroundColor
- cameraContentLabelErrorBackgroundColor
- cameraContentLabelStateFont
- cameraContentLabelStateColor
- cameraContentModalBackgroundColor
- cameraContentModalFont
- cameraContentModalTextColor
- cameraContentModalTextSecondaryColor
- cameraAnnotationEditorBackgroundColor
- cameraAnnotationEditorHeaderTextColor
- cameraAnnotationEditorHeaderTextFont
- cameraAnnotationEditorHeaderAnnotationBackgroundColor
- cameraAnnotationEditorHeaderAnnotationColor
- cameraAnnotationEditorHeaderAnnotationFont
- cameraAnnotationEditorContentBackgroundColor
- cameraAnnotationEditorContentBorderColor
- cameraAnnotationEditorContentFont
- cameraAnnotationEditorContentColor
- cameraAnnotationEditorContentPlaceholderColor
- cameraAnnotationEditorFooterDeleteColor
- cameraAnnotationEditorFooterButtonColor
- cameraAnnotationEditorFooterButtonFont
- cameraAnnotationEditorFooterButtonSaveBackgroundColor
- cameraAnnotationEditorFooterButtonSaveColor
- cameraAnnotationEditorFooterButtonSaveFont
- cameraPopupBackgroundColor
- cameraPopupTitleColor
- cameraPopupTitleFont
- cameraPopupContentColor
- cameraPopupContentFont
- cameraAnnotationsMenuItemIndexColor
- cameraAnnotationsMenuItemIndexBackgroundColor
- cameraAnnotationsMenuItemIndexFont
- cameraAnnotationsMenuItemTitleFont
- cameraAnnotationsMenuItemTitleColor
- cameraAnnotationsMenuItemContentFont
- cameraAnnotationsMenuItemContentColor
- termsOfService
- termsOfServiceURL
- privacyURL













## Dev iOS

Dans projet:

	$ react-native init example
	$ cd example
	$ npm install
	$ npm install --save ../Weproov/
	$ react-native link react-native-weproov
	$ cp ../example\ working/App.js ./
	$ cd ios
	$ nano Podfile

```
platform :ios, '10.0'
use_frameworks!

target "example" do
  pod 'RNWeproov', path: "../node_modules/react-native-weproov"
  pod 'WeProovSDK', path: "/Users/jonathan/Desktop/Codage/WeProov/weproov-ios-sdk"

  # https://facebook.github.io/react-native/docs/integration-with-existing-apps.html
  # Your 'node_modules' directory is probably in the root of your project,
  # but if not, adjust the `:path` accordingly
  pod 'React', :path => '../node_modules/react-native', :subspecs => [
    'Core',
    'CxxBridge', # Include this for RN >= 0.47
    'DevSupport', # Include this to enable In-App Devmenu if RN >= 0.43
    'RCTText',
    'RCTNetwork',
    'RCTWebSocket', # Needed for debugging
    'RCTAnimation', # Needed for FlatList and animations running on native UI thread
    # Add any other subspecs you want to use in your project
  ]
  # Explicitly include Yoga if you are using RN >= 0.42.0
  pod 'yoga', :path => '../node_modules/react-native/ReactCommon/yoga'

  # Third party deps podspec link
  pod 'DoubleConversion', :podspec => '../node_modules/react-native/third-party-podspecs/DoubleConversion.podspec'
  pod 'glog', :podspec => '../node_modules/react-native/third-party-podspecs/glog.podspec'
  pod 'Folly', :podspec => '../node_modules/react-native/third-party-podspecs/Folly.podspec'
end

```

	$ pod install
	$ cd ../
	$ react-native run-ios

