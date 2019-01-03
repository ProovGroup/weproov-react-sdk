#import "WPCommon.h"

@interface RNWeproov: NSObject <RCTBridgeModule, WPReportDownloadViewControllerDelegate, WPReportDownloaderDelegate> {
  WPReportDownloader *_downloader;
  RCTResponseSenderBlock _downloadCallback;
  __weak WPReportDownloadViewController *_downloadController;
  WPTheme *_theme;
}

@end

@implementation RNWeproov

- (instancetype)init
{
  self = [super init];
  if (self) {
    _downloader = [WPReportDownloader new];
    _downloader.delegate = self;
    _theme = [WPTheme new];
  }
  return self;
}

+ (BOOL)requiresMainQueueSetup
{
  return NO;
}

- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}
RCT_EXPORT_MODULE()

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
RCT_EXPORT_METHOD(setTheme:(NSDictionary * _Nonnull)values callback:(RCTResponseSenderBlock)callback)
{
  for (NSString *attribute in [values allKeys]) {
    let method = [NSString stringWithFormat:@"set%@:", [attribute stringByReplacingCharactersInRange:NSMakeRange(0,1)
                                                                                          withString:[[attribute substringToIndex:1] capitalizedString]]];
    
    let selector = NSSelectorFromString(method);
    
    if(![WPTheme instancesRespondToSelector:selector]) {
      let error = [NSString stringWithFormat:@"unknown attribute: %@", attribute];
      callback(@[error]);
      return;
    }
    
    if ([attribute hasSuffix:@"Color"]) {
      NSString *colorText = values[attribute];
      
      let color = [UIColor colorFromHexString:colorText];
      if (color) {
        [_theme performSelector:selector withObject:color];
      }
      else {
        NSLog(@"failed to parse color: %@", colorText);
      }
    }
    else if ([attribute hasSuffix:@"Font"]) {
      NSString *fontName = [values[attribute] objectAtIndex:0];
      NSNumber *fontSize = [values[attribute] objectAtIndex:1];
      
      let font = [UIFont fontWithName:fontName size:[fontSize floatValue]];
      if (font) {
        [_theme performSelector:selector withObject:font];
      }
      else {
        NSLog(@"[WeProovSDKPlugin] failed to parse font: %@", fontName);
      }
    }
    else if ([attribute hasSuffix:@"URL"]) {
      NSString *urlText = values[attribute];
      
      let url = [NSURL URLWithString:urlText];
      if (url) {
        [_theme performSelector:selector withObject:url];
      }
      else {
        NSLog(@"[WeProovSDKPlugin] failed to parse url: %@", urlText);
      }
    }
    else {
      NSString *text = values[attribute];
      [_theme performSelector:selector withObject:text];
    }
  }
  
  callback(@[]);
}
#pragma clang diagnostic pop

RCT_EXPORT_METHOD(loadProovCode:(NSString * _Nonnull)proovCode callback:(RCTResponseSenderBlock)callback)
{
  if (_downloadCallback) {
    callback(@[@"already loading"]);
    return;
  }
  
  _downloadCallback = callback;
  
  let controller = [WPReportDownloadViewController new];
  _downloadController = controller;
  controller.delegate = self;
  
  let rootViewController = [UIApplication sharedApplication].delegate.window.rootViewController;
  [rootViewController presentViewController:controller
                                    animated:true
                                  completion:^{
                                    [_downloader loadWithProovCode:proovCode];
                                  }];
}


RCT_EXPORT_METHOD(loadTemplate:(NSNumber * _Nonnull)templateId callback:(RCTResponseSenderBlock)callback)
{
  if (_downloadCallback) {
    callback(@[@"already loading"]);
    return;
  }
  
  _downloadCallback = callback;
  
  let controller = [WPReportDownloadViewController new];
  _downloadController = controller;
  controller.delegate = self;
  
  let rootViewController = [UIApplication sharedApplication].delegate.window.rootViewController;
  [rootViewController presentViewController:controller
                                    animated:true
                                  completion:^{
                                    [_downloader loadWithTemplateId:[templateId integerValue]];
                                  }];
}

RCT_EXPORT_METHOD(loadTemplate:(RCTResponseSenderBlock)callback)
{
  if (_downloadCallback) {
    callback(@[@"already loading"]);
    return;
  }
  
  _downloadCallback = callback;
  
  let controller = [WPReportDownloadViewController new];
  _downloadController = controller;
  controller.delegate = self;
  
  let rootViewController = [UIApplication sharedApplication].delegate.window.rootViewController;
  [rootViewController presentViewController:controller
                                    animated:true
                                  completion:^{
                                    [_downloader loadReportInCache];
                                  }];
}

RCT_EXPORT_METHOD(haveReportInCache:(RCTResponseSenderBlock)callback)
{
  if ([_downloader haveReportInCache]) {
    callback(@[@1]);
  }
  else {
    callback(@[@0]);
  }
}

// MARK: - WPReportDownloadViewControllerDelegate

- (void)reportCancelDownload
{
  // Cannot stop downloader, so create a new one
  [_downloader setDelegate:nil];
  
  _downloader = [WPReportDownloader new];
  _downloader.delegate = self;
  
  _downloadCallback(@[[NSError new]]);
  _downloadCallback = nil;
}

// MARK: - WPReportDownloaderDelegate

- (BOOL)reportCanShowSectionImportWithDownloader:(WPReportDownloader * _Nonnull)downloader section:(NSInteger)section
{
  return true;
}

- (BOOL)reportCanShowSectionWithDownloader:(WPReportDownloader * _Nonnull)downloader section:(NSInteger)section
{
  return true;
}

- (void)reportDidLoadWithDownloader:(WPReportDownloader * _Nonnull)downloader report:(WPReport * _Nonnull)report
{
  [_downloadController updateProgressionWithValue:1];
  [_downloadController dismissViewControllerAnimated:true completion:nil];
  
  let controller = [[WPReportViewController alloc] initWithReport:report theme:_theme];
  let navController = [[UINavigationController alloc] initWithRootViewController:controller];
  
  let rootViewController = [UIApplication sharedApplication].delegate.window.rootViewController;
  [rootViewController presentViewController:navController
                                    animated:true
                                  completion:nil];
  
  
  _downloadCallback(@[[NSNull null]]);
  _downloadCallback = nil;
}

- (void)reportFailedToLoadWithDownloader:(WPReportDownloader * _Nonnull)downloader error:(NSError * _Nullable)error
{
  [_downloadController dismissViewControllerAnimated:true completion:nil];
  
  _downloadCallback(@[[error localizedDescription]]);
  _downloadCallback = nil;
}

- (void)reportLoadingProgressWithDownloader:(WPReportDownloader * _Nonnull)downloader progress:(float)progress
{
  [_downloadController updateProgressionWithValue:progress];
}

- (void)reportLoadingWithDownloader:(WPReportDownloader * _Nonnull)downloader
{
}

@end
