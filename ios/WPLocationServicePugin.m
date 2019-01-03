#import "WPLocationServicePugin.h"
#import "WPCommon.h"

@implementation WPLocationServicePugin

- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}
RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(startUpdateLocation)
{
  [[WPLocationService shared] startUpdateLocation];
}

RCT_EXPORT_METHOD(startUpdateLocationIfAuthorized)
{
  [[WPLocationService shared] startUpdateLocationIfAuthorized];
}

RCT_EXPORT_METHOD(stopUpdateLocation)
{
  [[WPLocationService shared] stopUpdateLocation];
}

@end
