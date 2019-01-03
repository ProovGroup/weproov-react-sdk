// Objective-C API for talking to bitbucket.org/weproov/weproovstrucgo/pulldownload Go package.
//   gobind -lang=objc bitbucket.org/weproov/weproovstrucgo/pulldownload
//
// File is generated by gobind. Do not edit.

#ifndef __Pulldownload_H__
#define __Pulldownload_H__

@import Foundation;
#include "Universe.objc.h"


@class PulldownloadStruct;
@protocol PulldownloadDownloadable;
@class PulldownloadDownloadable;
@protocol PulldownloadManagerDelegate;
@class PulldownloadManagerDelegate;

@protocol PulldownloadDownloadable <NSObject>
- (id<PulldownloadDownloadable>)asDownloadable;
- (PulldownloadStruct*)download:(id<PulldownloadManagerDelegate>)delegate;
@end

@protocol PulldownloadManagerDelegate <NSObject>
- (void)onDownloadProgress:(long)total finished:(long)finished;
@end

@interface PulldownloadStruct : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
/**
 * 		Total est le nombre de total de telechargement demander
		il seras aussi le premiers argument l'ors du callback
		du progress

		totalLock est le mutex pour proteger la variable
 */
- (long)total;
- (void)setTotal:(long)v;
/**
 * 		Finished est le nombre de total de telechargement terminer
		il seras aussi le second argument l'ors du callback
		du progress

		v est le mutex pour proteger la variable
 */
- (long)finished;
- (void)setFinished:(long)v;
/**
 * 		Success est le nombre de total de telechargement terminer Reussi

		successLock est le mutex pour proteger la variable
 */
- (long)success;
- (void)setSuccess:(long)v;
/**
 * 		Error est le nombre de total de telechargement terminer qui a rater

		successLock est le mutex pour proteger la variable
 */
- (long)error;
- (void)setError:(long)v;
// skipped field Struct.Errors with unsupported type: *types.Slice

/**
 * 		Manager est la classe qui serviras pour les callback

		managerLock est le mutex pour proteger la variable
 */
- (id<PulldownloadManagerDelegate>)manager;
- (void)setManager:(id<PulldownloadManagerDelegate>)v;
/**
 * 	Download un calque grace a son id (cached_id)
	une fois terminer la fonction OnCalqueSuccess
	du delegate sera appeler
 */
- (BOOL)downloadCalque:(long)id_;
/**
 * 	Download l'image en signalent que l'image sera un dropin

	une fois terminer la fonction OnDropinSuccess du
	delegate sera appeler

	@key = "image/{proov_code}/{hash}.jpeg"
	@delegate
 */
- (BOOL)downloadDropin:(NSString*)key;
/**
 * 	Download l'image en signalent que l'image sera un dropoff

	une fois terminer la fonction OnDropoffSuccess du
	delegate sera appeler

	@key = "image/{proov_code}/{hash}.jpeg"
 */
- (BOOL)downloadDropoff:(NSString*)key;
- (BOOL)haveInCacheS3:(NSString*)key;
- (BOOL)haveToDownload;
- (void)printError;
/**
 * 	Wait fait attendre un coeure pour le telechargement

	la fonction ne retourneras pas tant que le
	telechargement n'est pas terminer

	if true == tout ses bien passer
 */
- (BOOL)waits;
@end

FOUNDATION_EXPORT PulldownloadStruct* PulldownloadNew(id<PulldownloadManagerDelegate> manager);

@class PulldownloadDownloadable;

@class PulldownloadManagerDelegate;

/**
 * 	le delegate
	Serviras de callback de telechargement
 */
@interface PulldownloadDownloadable : NSObject <goSeqRefInterface, PulldownloadDownloadable> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (id<PulldownloadDownloadable>)asDownloadable;
- (PulldownloadStruct*)download:(id<PulldownloadManagerDelegate>)delegate;
@end

/**
 * 	ManagerDelegate
	permet de recuperer le pourcentage d'avancement du telechargment
 */
@interface PulldownloadManagerDelegate : NSObject <goSeqRefInterface, PulldownloadManagerDelegate> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onDownloadProgress:(long)total finished:(long)finished;
@end

#endif
