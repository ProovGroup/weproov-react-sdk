# react-native-weproov

This is a react adapter for:
- [weproov-ios-sdk](https://github.com/ProovGroup/weproov-ios-sdk)
- [AndroidSDK](https://github.com/ProovGroup/AndroidSDK)

## Installation

### iOS

    $ npm install -g react-native-cli
    $ react-native init example
    $ cd example
    $ npm install
    $ npm install --save https://github.com/ProovGroup/weproov-react-sdk.git
    $ react-native link react-native-weproov
    $ cp node_modules/react-native-weproov/ios/example/App.js ./
    $ cd ios
    $ nano Podfile

```
platform :ios, '10.0'
use_frameworks!

target "example" do
  pod 'WeProovSDK', :git => 'https://github.com/ProovGroup/weproov-ios-sdk'
end

```

    $ sudo gem install cocoapods
    $ pod install
    $ cd ../
    $ react-native run-ios

#### Requirements

- add keys `NSCameraUsageDescription`, `NSContactsUsageDescription` and `NSLocationWhenInUseUsageDescription` to `Info.plist`
- disable bitcode
- set `Background Fetch` for `Background Mode`

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
- signatureNavigationBarItemsColor
- signatureHeaderSectionFont
- signatureHeaderSectionColor
- signatureHeaderInfoFont
- signatureHeaderInfoColor
- signatureSubmitButtonBackgroundColor
- signatureSubmitButtonColor
- signatureSubmitButtonFont
- signatureClearButtonColor
- signatureClearButtonFont
- signatureSeeReportButtonColor
- signatureSeeReportButtonFont
- signatureFooterFont
- signatureFooterBackgroundColor
- signatureFooterColor
- signatureFooterHighlightColor
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


##Android

To set up your project to build with android:

in android/build.gradle, set

```
buildscript {
    ext {
        buildToolsVersion = "28.0.3"
        minSdkVersion = 16
        compileSdkVersion = 28
        targetSdkVersion = 26
        supportLibVersion = "28.0.0"
    }

    dependencies {
        classpath 'com.android.tools.build:gradle:3.2.1'
    }

    ...
}

```

in android/app/build.gradle, set

```

android {

    ...

    compileOptions {
        sourceCompatibility JavaVersion.VERSION_1_8
        targetCompatibility JavaVersion.VERSION_1_8
    }

    configurations.all {
        resolutionStrategy {
            force 'androidx.media:media:1.0.0'
            force 'androidx.legacy:legacy-support-v4:1.0.0'
            force 'androidx.test:monitor:1.1.0'
            force 'androidx.lifecycle:lifecycle-livedata-core:2.0.0'
            force 'androidx.print:print:1.0.0'
            force 'androidx.drawerlayout:drawerlayout:1.0.0'
            force 'androidx.viewpager:viewpager:1.0.0'
            force 'androidx.core:corer:1.0.1'
            force 'androidx.core:core:1.0.1'
            force 'androidx.vectordrawable:vectordrawable-animated:1.0.0'
            force 'androidx.vectordrawable:vectordrawable:1.0.1'
            force 'androidx.fragment:fragment:1.0.0'
            force 'androidx.appcompat:appcompat:1.0.0'
        }
    }
}

```

in android/app/gradle/wrapper/gradle-wrapper.properties, set

```
distributionUrl=https\://services.gradle.org/distributions/gradle-4.6-bin.zip
```

in android/gradle.properties, set

```
android.useAndroidX=true
android.enableJetifier=true
```


## Usage

Use Android resources (android/app/src/main/res) to set a custom theme. Check documentation at https://github.com/ProovGroup/AndroidSDK

