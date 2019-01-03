#import "WPCommon.h"

@interface WPUserPlugin: NSObject <RCTBridgeModule, WPUserDelegate> {
  RCTResponseSenderBlock _connectCallack;
}

@end

@implementation WPUserPlugin

- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}
RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(connect:(NSString * _Nonnull)token secret:(NSString * _Nonnull)secret callback:(RCTResponseSenderBlock)callback)
{
  // already connecting
  if (_connectCallack) {
    callback(@[@"already connecting"]);
    return;
  }
  
  _connectCallack = callback;

  [[WPUser shared] setDelegate:self];
  [[WPUser shared] connectWithToken:token secret:secret];
}

RCT_EXPORT_METHOD(logout)
{
  [[WPUser shared] logout];
}

RCT_EXPORT_METHOD(isConnected:(RCTResponseSenderBlock)callback)
{
  if ([[WPUser shared] connected]) {
    callback(@[@1]);
  }
  else {
    callback(@[@0]);
  }
}

RCT_EXPORT_METHOD(setLang:(NSString * _Nonnull)lang)
{
  [[WPUser shared] setLang:lang];
}

- (void)userDidConnectWithUser:(WPUser * _Nonnull)user
{
  if (!_connectCallack) {
    return;
  }
  
  _connectCallack(@[[NSNull null]]);
}

- (void)userFailedToConnectWithUser:(WPUser * _Nonnull)user error:(NSError * _Nullable)error
{
  if (!_connectCallack) {
    return;
  }
  
  _connectCallack(@[[error localizedDescription]]);
  _connectCallack = nil;
}

@end
