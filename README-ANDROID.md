#android project configuration

in android/build.gradle:

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

in android/app/build.gradle

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

in android/app/gradle/wrapper/gradle-wrapper.properties

```
distributionUrl=https\://services.gradle.org/distributions/gradle-4.6-bin.zip
```

in android/gradle.properties

```
android.useAndroidX=true
android.enableJetifier=true
```
