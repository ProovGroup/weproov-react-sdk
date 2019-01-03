#import "WPReportUploaderPlugin.h"
#import "WPCommon.h"

@implementation WPReportUploaderPlugin

- (dispatch_queue_t)methodQueue
{
  return dispatch_get_main_queue();
}
RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(sync)
{
  [[WPReportUploader shared] sync];
}

@end

