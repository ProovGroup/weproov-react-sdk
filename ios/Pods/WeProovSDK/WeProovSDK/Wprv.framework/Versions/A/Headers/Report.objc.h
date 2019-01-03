// Objective-C API for talking to bitbucket.org/weproov/weproovstrucgo/report Go package.
//   gobind -lang=objc bitbucket.org/weproov/weproovstrucgo/report
//
// File is generated by gobind. Do not edit.

#ifndef __Report_H__
#define __Report_H__

@import Foundation;
#include "Universe.objc.h"

#include "Fscache.objc.h"
#include "Geoloc.objc.h"
#include "Items.objc.h"
#include "Proover.objc.h"
#include "Pulldownload.objc.h"
#include "S3image.objc.h"
#include "Translations.objc.h"
#include "Wperr.objc.h"

@class ReportCProcess;
@class ReportChecklist;
@class ReportIdentifierItems;
@class ReportImageMetaData;
@class ReportInfo;
@class ReportInfosParameters;
@class ReportList;
@class ReportListUpload;
@class ReportMeta;
@class ReportPart;
@class ReportProcess;
@class ReportProcessInfos;
@class ReportProcessStateList;
@class ReportStruct;
@class ReportSupport;
@class ReportUpload;
@protocol ReportCloseDelegate;
@class ReportCloseDelegate;
@protocol ReportDeleteDelegate;
@class ReportDeleteDelegate;
@protocol ReportExistDelegate;
@class ReportExistDelegate;
@protocol ReportField;
@class ReportField;
@protocol ReportFullDelegate;
@class ReportFullDelegate;
@protocol ReportListDelegate;
@class ReportListDelegate;
@protocol ReportPDFDownloadDelegate;
@class ReportPDFDownloadDelegate;
@protocol ReportPhoto;
@class ReportPhoto;
@protocol ReportSignPartDelegate;
@class ReportSignPartDelegate;

@protocol ReportCloseDelegate <NSObject>
- (void)onCloseError:(NSError*)err;
- (void)onCloseSuccess;
@end

@protocol ReportDeleteDelegate <NSObject>
- (void)onDeleteError:(NSError*)err;
- (void)onDeleteSuccess;
@end

@protocol ReportExistDelegate <NSObject>
- (void)reportExist:(BOOL)p0;
- (void)reportExistError:(NSError*)p0;
@end

@protocol ReportField <NSObject>
- (NSString*)dropoffValueF;
- (id<ReportField>)getAsField;
- (ReportInfosParameters*)getParams;
- (ReportPart*)getPart;
- (ReportStruct*)getReport;
- (BOOL)haveDropoff;
- (BOOL)isRequire;
- (NSString*)nameF;
- (NSString*)titleTr;
- (NSString*)typeF;
- (NSString*)valueF;
- (NSString*)writeValue:(NSString*)p0;
@end

@protocol ReportFullDelegate <NSObject>
- (void)onReportFullError:(NSError*)err;
- (void)onReportFullSuccess:(ReportStruct*)report;
@end

@protocol ReportListDelegate <NSObject>
- (void)onReportFindError:(NSError*)err;
- (void)onReportFindsuccess:(ReportList*)list;
@end

@protocol ReportPDFDownloadDelegate <NSObject>
- (void)onPdfDownloadedError:(NSError*)err;
- (void)onPdfDownloadedSuccess:(NSString*)path;
@end

@protocol ReportPhoto <NSObject>
- (NSString*)getDropinPath;
- (NSString*)getDropoffPath;
- (BOOL)haveDropin;
- (BOOL)haveDropoff;
- (BOOL)haveDropoffState;
- (void)removeTemporary;
- (NSString*)titleTr;
- (NSString*)uTplName;
- (NSString*)writeImage:(NSData*)p0 error:(NSError**)error;
@end

@protocol ReportSignPartDelegate <NSObject>
- (void)onSignatureUploadError:(NSError*)err;
- (void)onSignatureUploadSuccess;
@end

@interface ReportCProcess : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (long)id_;
- (void)setId:(long)v;
- (NSString*)name;
- (void)setName:(NSString*)v;
- (long)title;
- (void)setTitle:(long)v;
- (long)cachedId;
- (void)setCachedId:(long)v;
- (long)number;
- (void)setNumber:(long)v;
- (long)categoryId;
- (void)setCategoryId:(long)v;
- (NSString*)orientation;
- (void)setOrientation:(NSString*)v;
// skipped field CProcess.CreatedAt with unsupported type: *types.Named

// skipped field CProcess.UpdatedAt with unsupported type: *types.Named

@end

@interface ReportChecklist : NSObject <goSeqRefInterface, ReportField> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
/**
 * 		id de la checklist
		dans la bdd 0 si non initiliser
 */
- (long)id_;
- (void)setId:(long)v;
/**
 * 		id du titre du champs
 */
- (long)titleId;
- (void)setTitleId:(long)v;
// skipped field Checklist.Title_ with unsupported type: *types.Named

/**
 * 		Nom du champs.
		seras utiliser lor de l'import de contact/items
 */
- (NSString*)name;
- (void)setName:(NSString*)v;
/**
 * 		Permet de savoir si un champs est requis ou pas
 */
- (BOOL)required;
- (void)setRequired:(BOOL)v;
/**
 * 		Permet de savoir si un champs devras etre resaisi en mode
		dropoff
 */
- (BOOL)dropoff;
- (void)setDropoff:(BOOL)v;
/**
 * 		Type du champs permet de sovire quelle est la forme du champs a afficher
		sur les checklist peut etre boolean/number
 */
- (NSString*)type;
- (void)setType:(NSString*)v;
- (BOOL)noRestart;
- (void)setNoRestart:(BOOL)v;
/**
 * 		Section permet de savoir ou afficher le champs
		sur les checklist se sera cheklist
 */
- (NSString*)section;
- (void)setSection:(NSString*)v;
/**
 * 		FieldId permet de remonter jusque au model du champs
 */
- (long)fieldId;
- (void)setFieldId:(long)v;
/**
 * 		Part id permet de savoire la part parent
 */
- (long)partId;
- (void)setPartId:(long)v;
/**
 * 		Report id permet de savoir la raport
 */
- (long)reportId;
- (void)setReportId:(long)v;
/**
 * 		Position va me permetre de trier la list
 */
- (long)position;
- (void)setPosition:(long)v;
/**
 * 		Value est la valeur du champs quand le rapport est en etat
		d'entrer('pending_first')
 */
- (NSString*)value;
- (void)setValue:(NSString*)v;
/**
 * 		DropoffValue est la valeur du champs quand le rapport est en etat
		de sortie('pending_second')
 */
- (NSString*)dropoffValue;
- (void)setDropoffValue:(NSString*)v;
// skipped field Checklist.CreatedAt with unsupported type: *types.Named

// skipped field Checklist.UpdatedAt with unsupported type: *types.Named

/**
 * 	Cette method sert a creer un lien entre le champs
	et le reste du rapport
 */
- (void)createLink:(ReportStruct*)rpt part:(ReportPart*)part;
/**
 * 	+ Permet de repondre au exigence de Field

	renvoie la valeur de retour du champs
 */
- (NSString*)dropoffValueF;
/**
 * 	Renvoyer la version caster en Field
 */
- (id<ReportField>)getAsField;
/**
 * 	Renvoy toujour nil mais permet de corespondre au type field
 */
- (ReportInfosParameters*)getParams;
/**
 * 	Peremet de recuperer la part a qui apartient le champs
 */
- (ReportPart*)getPart;
/**
 * 	Peremet de recuperer le rapport a qui apartient le champs
 */
- (ReportStruct*)getReport;
/**
 * 	Permet de savoir si un etat
	dropoff seras appliquer a ce champs
 */
- (BOOL)haveDropoff;
- (BOOL)isCompleted;
/**
 * 	permet de savoire si le champs est require
 */
- (BOOL)isRequire;
/**
 * 	Permet de recuperer le nom du champs
 */
- (NSString*)nameF;
- (void)removeLink;
- (void)setTemplateMode;
- (NSString*)titleTr;
/**
 * 	+ Permet de repondre au exigence de Field

	renvoie le type du champs (numeric | boolean)
 */
- (NSString*)typeF;
- (void)updateByApi:(ReportChecklist*)n;
/**
 * 	+ Permet de repondre au exigence de Field

	renvoie la valeur du champs
 */
- (NSString*)valueF;
- (NSString*)writeValue:(NSString*)value;
@end

@interface ReportIdentifierItems : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)value;
- (void)setValue:(NSString*)v;
- (NSString*)name;
- (void)setName:(NSString*)v;
// skipped field IdentifierItems.Title_ with unsupported type: *types.Named

@end

@interface ReportImageMetaData : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (long)width;
- (void)setWidth:(long)v;
- (long)height;
- (void)setHeight:(long)v;
- (double)longitude;
- (void)setLongitude:(double)v;
- (double)altitude;
- (void)setAltitude:(double)v;
- (double)latitude;
- (void)setLatitude:(double)v;
- (NSString*)orientation;
- (void)setOrientation:(NSString*)v;
// skipped field ImageMetaData.Infos with unsupported type: *types.Slice

@end

@interface ReportInfo : NSObject <goSeqRefInterface, ReportField> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (long)id_;
- (void)setId:(long)v;
- (long)titleId;
- (void)setTitleId:(long)v;
// skipped field Info.Title_ with unsupported type: *types.Named

- (NSString*)name;
- (void)setName:(NSString*)v;
- (BOOL)dropoff;
- (void)setDropoff:(BOOL)v;
- (BOOL)identifier;
- (void)setIdentifier:(BOOL)v;
- (BOOL)forced;
- (void)setForced:(BOOL)v;
- (BOOL)required;
- (void)setRequired:(BOOL)v;
- (BOOL)referenced;
- (void)setReferenced:(BOOL)v;
- (BOOL)noRestart;
- (void)setNoRestart:(BOOL)v;
- (long)categoryId;
- (void)setCategoryId:(long)v;
- (NSString*)section;
- (void)setSection:(NSString*)v;
- (NSString*)type;
- (void)setType:(NSString*)v;
- (long)fieldId;
- (void)setFieldId:(long)v;
- (long)partId;
- (void)setPartId:(long)v;
- (long)reportId;
- (void)setReportId:(long)v;
- (long)position;
- (void)setPosition:(long)v;
// skipped field Info.Parameters with unsupported type: *types.Named

- (NSString*)value;
- (void)setValue:(NSString*)v;
- (NSString*)dropoffValue;
- (void)setDropoffValue:(NSString*)v;
// skipped field Info.CreatedAt with unsupported type: *types.Named

// skipped field Info.UpdatedAt with unsupported type: *types.Named

- (void)createLink:(ReportStruct*)rpt part:(ReportPart*)part;
- (NSString*)dropoffValueF;
- (id<ReportField>)getAsField;
- (ReportInfosParameters*)getParams;
- (ReportPart*)getPart;
- (ReportStruct*)getReport;
- (BOOL)haveDropoff;
- (BOOL)isCompleted;
- (BOOL)isRequire;
- (NSString*)nameF;
- (void)removeLink:(ReportStruct*)rpt part:(ReportPart*)part;
- (void)setTemplateMode;
- (NSString*)titleTr;
/**
 * ////////////////////FIELD/////////////////////////////////
 */
- (NSString*)typeF;
- (void)updateByApi:(ReportInfo*)n;
- (NSString*)valueF;
- (NSString*)writeValue:(NSString*)value;
@end

@interface ReportInfosParameters : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
// skipped field InfosParameters.List with unsupported type: *types.Slice

// skipped field InfosParameters.List_ with unsupported type: *types.Slice

- (long)getListIdByPosition:(NSString*)tr;
- (long)getListPosition:(long)pose;
- (NSString*)getListTr:(long)id_;
- (long)listCount;
@end

@interface ReportList : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)state;
- (void)setState:(NSString*)v;
- (NSString*)find;
- (void)setFind:(NSString*)v;
- (long)offset;
- (void)setOffset:(long)v;
- (long)limit;
- (void)setLimit:(long)v;
- (BOOL)haveMore;
- (void)setHaveMore:(BOOL)v;
// skipped field List.Result with unsupported type: *types.Slice

- (long)count;
- (ReportStruct*)get:(long)num;
- (void)next:(id<ReportListDelegate>)delegate;
@end

@interface ReportListUpload : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
// skipped field ListUpload.Uploads with unsupported type: *types.Slice

// skipped method ListUpload.Add with unsupported parameter or return types

- (long)count;
- (ReportUpload*)get:(long)num;
- (ReportUpload*)getBySessionKey:(NSString*)sessionKey;
- (ReportUpload*)getKey:(NSString*)key;
- (void)remove:(long)i;
- (void)save;
@end

@interface ReportMeta : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (long)title;
- (void)setTitle:(long)v;
- (NSString*)value;
- (void)setValue:(NSString*)v;
// skipped field Meta.Title_ with unsupported type: *types.Named

- (NSString*)getTitleTr;
@end

@interface ReportPart : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (long)id_;
- (void)setId:(long)v;
- (long)titleId;
- (void)setTitleId:(long)v;
// skipped field Part.Title_ with unsupported type: *types.Named

- (BOOL)signer;
- (void)setSigner:(BOOL)v;
- (BOOL)autorestart;
- (void)setAutorestart:(BOOL)v;
- (long)position;
- (void)setPosition:(long)v;
- (NSString*)note;
- (void)setNote:(NSString*)v;
- (NSString*)dropoffNote;
- (void)setDropoffNote:(NSString*)v;
- (long)sign;
- (void)setSign:(long)v;
- (long)dropoffSign;
- (void)setDropoffSign:(long)v;
- (BOOL)item;
- (void)setItem:(BOOL)v;
- (long)reportId;
- (void)setReportId:(long)v;
- (long)prooverId;
- (void)setProoverId:(long)v;
- (long)itemsId;
- (void)setItemsId:(long)v;
- (long)categorieId;
- (void)setCategorieId:(long)v;
// skipped field Part.CreatedAt with unsupported type: *types.Named

// skipped field Part.UpdatedAt with unsupported type: *types.Named

// skipped field Part.Infos with unsupported type: *types.Slice

// skipped field Part.Supports with unsupported type: *types.Slice

// skipped field Part.Checklists with unsupported type: *types.Slice

// skipped field Part.TempMetaData with unsupported type: *types.Named

- (BOOL)haveSigned;
- (void)setHaveSigned:(BOOL)v;
- (void)changeCguv:(BOOL)selected;
/**
 * ////////////////////// END Supports ////////////////////////
///////////////////////// Checklists ///////////////////////////

	ChecklistCount
	Permet de recuperer le nombre de supports
	presente dans le rapport
 */
- (long)checklistsCount;
- (void)close;
- (void)createLink:(ReportStruct*)rpt;
- (ReportChecklist*)getChecklistByName:(NSString*)name;
- (ReportChecklist*)getChecklists:(long)num;
- (ReportInfo*)getInfos:(long)num;
- (ReportInfo*)getInfosByName:(NSString*)name;
- (ReportStruct*)getReport;
- (ReportSupport*)getSupports:(long)num;
- (ReportSupport*)getSupportsByName:(NSString*)name;
- (NSString*)getTitle;
/**
 * ////////////////////// Infos ///////////////////////////

	InfosCount
	Permet de recuperer le nombre de supports
	presente dans le rapport
 */
- (long)infosCount;
- (BOOL)isCompleted;
/**
 * 	Permet de designer et d'importer les information de l'utilisateur dans la part
 */
- (void)itsMe;
- (void)noSign;
- (void)setTemplateMode;
/**
 * ////////////////////// END Infos ////////////////////////
////////////////////// Supports ///////////////////////////

	SupportsCount
	Permet de recuperer le nombre de supports
	presente dans le rapport
 */
- (long)supportsCount;
/**
 * ////////////////////// END Checklists ////////////////////////
 */
- (void)updateByApi:(ReportPart*)n;
- (void)updateByItem:(ItemsStruct*)item picture:(BOOL)picture;
- (void)updateByProover:(ProoverStruct*)proover;
- (void)writeSignature:(NSData*)data;
- (void)writeSignatureSync:(NSData*)data;
@end

@interface ReportProcess : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
/**
 * 		Id du process dans la bdd
		si = 0 le raport ne semble pas initialiser
 */
- (long)id_;
- (void)setId:(long)v;
/**
 * 		nom du process
		dois etre en minuscule sans accent et les mots
		son separer par un underscore(_)
		exemple:
		- font
		- back_left
		- ...
 */
- (NSString*)name;
- (void)setName:(NSString*)v;
/**
 * 		Title
		represente l'id de la traduction dans la bdd
 */
- (long)title;
- (void)setTitle:(long)v;
// skipped field Process.Title_ with unsupported type: *types.Named

/**
 * 		ProcessId
		est l'id du Process utiliser pour la creation du champs
 */
- (long)processId;
- (void)setProcessId:(long)v;
// skipped field Process.Process_ with unsupported type: *types.Named

/**
 * 		CategoryId
		represente la category ou est classer dans WPA le preocess
 */
- (long)categoryId;
- (void)setCategoryId:(long)v;
/**
 * 		Orientation
		represente l'oritentation qui a ete definie dans process
 */
- (NSString*)orientation;
- (void)setOrientation:(NSString*)v;
/**
 * 		Dropoff = je sais pas trop ?
		Reqire = si le process est un process obligatoire
		Position = int repesentant sa position dans l'array
 */
- (BOOL)dropoff;
- (void)setDropoff:(BOOL)v;
- (BOOL)required;
- (void)setRequired:(BOOL)v;
- (long)position;
- (void)setPosition:(long)v;
- (BOOL)noRestart;
- (void)setNoRestart:(BOOL)v;
/**
 * 		PictureId = id de la s3Picture dans la bdd
		Picture_ = object de la s3picture recuperer pour voir la key s3
		infos = represent les anotation sur la photo
 */
- (long)pictureId;
- (void)setPictureId:(long)v;
// skipped field Process.Picture_ with unsupported type: *types.Named

// skipped field Process.Infos with unsupported type: *types.Slice

- (long)dropoffPictureId;
- (void)setDropoffPictureId:(long)v;
// skipped field Process.DropoffPicture_ with unsupported type: *types.Named

// skipped field Process.DropoffInfos with unsupported type: *types.Slice

/**
 * 		Id du raport ou il est lier
		si == 0 le rapport est un template
 */
- (long)reportId;
- (void)setReportId:(long)v;
// skipped field Process.CreatedAt with unsupported type: *types.Named

// skipped field Process.UpdatedAt with unsupported type: *types.Named

// skipped field Process.TempMetaData with unsupported type: *types.Named

- (BOOL)needToDelete;
- (void)setNeedToDelete:(BOOL)v;
/**
 * 	Ajout d'une information

	TODO: cas peut etre a gerer le met reviens faut il faire une copie
	en gros je commence -> juplod -> je recuper -> je modifie il se passe quoi ?
	voire pour peut etre gerer une version temporaire comme pour l'image
 */
- (void)addInfos:(long)index choice:(long)choice description:(NSString*)description x:(double)x y:(double)y width:(double)width height:(double)height;
/**
 * 	CreateLink & RemoveLink
	permet de lier/delier avec une structure raport
 */
- (void)createLink:(ReportStruct*)rpt;
- (long)dropoffInfosCount;
- (ReportProcessInfos*)dropoffInfosGet:(long)num;
- (NSString*)getDropoffPicturePath;
- (NSString*)getDropoffPicturePathS3;
- (NSString*)getPicturePath;
- (NSString*)getPicturePathS3;
/**
 * 	Permet de recuperer l'id d'un image calque

	TODO: serais peut etre interessans de permet
	la recuperation du path directement
 */
- (long)getProcessCachedId;
- (ReportStruct*)getReport;
- (NSString*)getTempPath;
// skipped method Process.GetTmpMeta with unsupported parameter or return types

- (BOOL)haveAnyDropoffPicture;
- (BOOL)haveAnyPicture;
/**
 * 	permet de savoire si il faut download
	une image dropoff en verifiant si un path s3 est present
 */
- (BOOL)haveDropoffPictureToDownload;
/**
 * 	permet de savoire si il faut download
	une image en verifiant si un path s3 est present
 */
- (BOOL)havePictureToDownload;
- (BOOL)haveTemporyData;
- (NSString*)imgType;
/**
 * 	Suprime tout les information d'entrer

	TODO: cas peut etre a gerer le met reviens faut il faire une copie
	en gros je commence -> juplod -> je recuper -> je modifie il se passe quoi ?
	voire pour peut etre gerer une version temporaire comme pour l'image
 */
- (void)infosClean;
/**
 * 	renvois le nombre d'info/annotation du dropin
 */
- (long)infosCount;
/**
 * 	Renvois l'information a l index x
	TODO: securiser du out of index
 */
- (ReportProcessInfos*)infosGet:(long)num;
- (BOOL)isCompared;
- (BOOL)isCompleted;
- (void)removeLink;
- (void)removeTemporary;
- (void)setCompared:(BOOL)to;
- (void)setTemplateMode;
- (NSString*)titleTr;
- (long)uid;
- (NSString*)uTplName;
- (void)updateByApi:(ReportProcess*)n;
- (void)updateByItem:(ItemsProcess*)item;
- (NSString*)writeImage:(NSData*)data error:(NSError**)error;
@end

@interface ReportProcessInfos : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (long)choice;
- (void)setChoice:(long)v;
- (long)index;
- (void)setIndex:(long)v;
- (NSString*)description;
- (void)setDescription:(NSString*)v;
- (double)height;
- (void)setHeight:(double)v;
- (double)width;
- (void)setWidth:(double)v;
- (double)left;
- (void)setLeft:(double)v;
- (double)top;
- (void)setTop:(double)v;
@end

@interface ReportProcessStateList : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (void)append:(ReportProcess*)process;
- (NSString*)compareStatus;
- (long)count;
- (ReportProcess*)get:(long)num;
- (long)getFirstIndexNotCompared;
- (void)resetAll;
- (NSString*)statusDropin;
- (NSString*)statusDropoff;
@end

@interface ReportStruct : NSObject <goSeqRefInterface, PulldownloadDownloadable> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
/**
 * 		Id Du Rapport
 */
- (long)id_;
- (void)setId:(long)v;
/**
 * 		Title du Rapport
		TitleId correspond a l'id dans la table translate
		Title_ correspond a l'object de la traduction
 */
- (long)titleId;
- (void)setTitleId:(long)v;
// skipped field Struct.Title_ with unsupported type: *types.Named

// skipped field Struct.Description_ with unsupported type: *types.Named

- (long)descriptionId;
- (void)setDescriptionId:(long)v;
/**
 * 		Dropoff
		permet de savoir si le rapport passeras par un state
		pending_second
 */
- (BOOL)dropoff;
- (void)setDropoff:(BOOL)v;
/**
 * 		FullDropoff
		permet de savoir si au rapport de retour(pending_second)
		il seras necessaire de forcer la reprise des photos de depard
		si le qu rapport de depard une photos etait obligatoire
		au raport de retour la photos le seras aussi
 */
- (BOOL)fullDropoff;
- (void)setFullDropoff:(BOOL)v;
// skipped field Struct.Meta with unsupported type: *types.Slice

/**
 * 		ProovCode = code unique du rapport
		6 character alpha numeric en upper case
 */
- (NSString*)proovCode;
- (void)setProovCode:(NSString*)v;
/**
 * 		Password n ais a se jour pas utiliser
		6 character alpha numeric en upper case
 */
- (NSString*)password;
- (void)setPassword:(NSString*)v;
/**
 * 		AutoRestart
		Definie comme quoi le raport redemare automatiquement quand son
		etas passe a 'finished'
 */
- (BOOL)autoRestart;
- (void)setAutoRestart:(BOOL)v;
/**
 * 		RestartState
		Permet de set l'etat du raport lors d'un auto restart
 */
- (NSString*)restartState;
- (void)setRestartState:(NSString*)v;
- (NSString*)state;
- (void)setState:(NSString*)v;
// skipped field Struct.Geoloc with unsupported type: *types.Named

// skipped field Struct.GeolocDropoff with unsupported type: *types.Named

/**
 * 		PreviewPicture
		est la photo qui dois etre afficher dans les list
		il est possible quelle soit vide (valeur = 0)
 */
- (long)previewPicture;
- (void)setPreviewPicture:(long)v;
// skipped field Struct.PreviewPictureProcess with unsupported type: *types.Named

/**
 * 		Mails
		liste d'emails d'on une copie du raport seras transmise
 */
- (NSString*)mails;
- (void)setMails:(NSString*)v;
/**
 * 		RefStr
		represent un liste de key=value separer par des ':'
		cette string permet de faire des recherche
 */
- (NSString*)refStr;
- (void)setRefStr:(NSString*)v;
/**
 * 		CategoryId
		id de la category du raport
 */
- (long)categoryId;
- (void)setCategoryId:(long)v;
// skipped field Struct.Webhook with unsupported type: *types.Slice

/**
 * 		id du proprietaire du rapport
		soit l'entreprise_id soit l'id de lutilisateur qui la initialiser
 */
- (long)owner;
- (void)setOwner:(long)v;
/**
 * 		TemplateId
		id du template qui a generer le raport
 */
- (long)templateId;
- (void)setTemplateId:(long)v;
/**
 * 		CustomRef
		reference passer a l'api pour les societer
 */
- (NSString*)customRef;
- (void)setCustomRef:(NSString*)v;
/**
 * 		ImageReport
		id representant un cachedImage
		Seras le logo aposer sur un rapport
		(prioritaire par raport au logo de l'utilisateur)
 */
- (long)imageReport;
- (void)setImageReport:(long)v;
- (NSString*)pdfHeaderBackgroundColor;
- (void)setPdfHeaderBackgroundColor:(NSString*)v;
- (NSString*)pdfHeaderTextColor;
- (void)setPdfHeaderTextColor:(NSString*)v;
// skipped field Struct.FinishedAt with unsupported type: *types.Named

// skipped field Struct.DropoffFinishedAt with unsupported type: *types.Named

// skipped field Struct.DeletedAt with unsupported type: *types.Named

// skipped field Struct.UpdatedAt with unsupported type: *types.Named

// skipped field Struct.CreatedAt with unsupported type: *types.Named

// skipped field Struct.CellTimeClose with unsupported type: *types.Named

// skipped field Struct.GeolocClose with unsupported type: *types.Named

- (long)userClose;
- (void)setUserClose:(long)v;
- (long)ownerClose;
- (void)setOwnerClose:(long)v;
// skipped field Struct.Parts with unsupported type: *types.Slice

// skipped field Struct.Process with unsupported type: *types.Slice

- (BOOL)needSetNextStep;
- (void)setNeedSetNextStep:(BOOL)v;
// skipped field Struct.Journal with unsupported type: *types.Named

// skipped field Struct.IdentiferItems with unsupported type: *types.Named

- (void)allOkNoSignaled;
- (id<PulldownloadDownloadable>)asDownloadable;
- (void)close;
- (void)createLink;
- (void)delete:(id<ReportDeleteDelegate>)delegate;
- (PulldownloadStruct*)download:(id<PulldownloadManagerDelegate>)delegate;
- (void)downloadLastPdf:(id<ReportPDFDownloadDelegate>)delegate;
- (NSString*)downloadLastPdfSync:(NSError**)error;
- (NSString*)getCachePath:(NSString*)name;
- (long)getCountAllPicture;
- (long)getCountAllPictureRequire;
- (long)getCountAllSignatories;
- (NSString*)getDescriptionTr;
- (NSString*)getDropoffFinishedAt;
- (int64_t)getDropoffFinishedAtUnix;
- (NSString*)getFinishedAt;
- (int64_t)getFinishedAtUnix;
- (NSString*)getIdentifier;
- (int64_t)getLastUpdateUnix;
/**
 * 	Permet de renvoyer la langue choisie pour le raport
	ou la langue du telephone a defaut
 */
- (NSString*)getLocal;
/**
 * 	Renvoy une metas d'on le num est l'index
 */
- (ReportMeta*)getMeta:(long)num;
/**
 * 	permet de recuperer la part dont
	le num est l'index dans l array
 */
- (ReportPart*)getParts:(long)num;
/**
 * 	Permet de recuperer l'image de preview au format 'thumb'
 */
- (void)getPreviewThumb:(id<S3imageThumbDelegate>)delegate;
/**
 * 	permet de recuperer le process dont
	le num est l'index dans l array
 */
- (ReportProcess*)getProcess:(long)num;
- (ReportProcess*)getProcessByName:(NSString*)name;
- (NSData*)getTempJson:(NSError**)error;
- (NSString*)getTitleTr;
- (NSString*)getUpdatedAt;
- (BOOL)haveCache:(NSString*)name;
- (BOOL)haveSignaledPicture;
/**
 * 	Verifie la totaliter du rapport si tout est pres
	pour passer a l'etape suivante
 */
- (BOOL)isCompleted;
/**
 * 	Permet de s'avoir si le raport en mode dropin
 */
- (BOOL)isDropin;
/**
 * 	Permet de s'avoir si le rapport en mode dropoff
	(en retour)
 */
- (BOOL)isDropoff;
/**
 * 	Permet de s'avoir si le rapport en mode historique / terminer
 */
- (BOOL)isHistory;
/**
 * 	Permet de s'avoir si le rapport peut etre ecrie
 */
- (BOOL)isLocked;
/**
 * 	Permet de connaitre le nombre de metas enregistrer
 */
- (long)metaCount;
/**
 * ////////////////////// PARTS ///////////////////////////

	PartsCount
	Permet de recuperer le nombre de partie
	presente dans le rapport
 */
- (long)partsCount;
- (BOOL)previewIs:(NSString*)path;
/**
 * ////////////////////// PROCESS ///////////////////////////

	PartsCount
	Permet de recuperer le nombre de partie
	presente dans le rapport
 */
- (long)processCount;
/**
 * 	vide tout les images qui ne son
	pas encors envoyer sur le server
 */
- (void)removeAllTemporaryProcess;
- (void)removeCache:(NSString*)name;
- (NSString*)saveCache:(NSString*)name data:(NSData*)data error:(NSError**)error;
- (void)saveTemp;
- (BOOL)saveToServer:(NSError**)error;
/**
 * 	Pemet de set la langue du raport
	elle ne changeras pas la lang global du framwork
 */
- (void)setLocal:(NSString*)lang;
- (BOOL)setNextStep:(NSError**)error;
- (void)setTemplateMode;
- (void)updateByApi:(ReportStruct*)n;
- (void)updateWithItem:(ItemsStruct*)item picture:(BOOL)picture optionalPicture:(BOOL)optionalPicture;
- (NSString*)urlForPreview;
@end

@interface ReportSupport : NSObject <goSeqRefInterface, ReportPhoto> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (long)id_;
- (void)setId:(long)v;
- (NSString*)name;
- (void)setName:(NSString*)v;
- (long)titleId;
- (void)setTitleId:(long)v;
// skipped field Support.Title_ with unsupported type: *types.Named

- (BOOL)required;
- (void)setRequired:(BOOL)v;
- (BOOL)dropoff;
- (void)setDropoff:(BOOL)v;
- (long)position;
- (void)setPosition:(long)v;
- (NSString*)section;
- (void)setSection:(NSString*)v;
- (NSString*)type;
- (void)setType:(NSString*)v;
- (BOOL)noRestart;
- (void)setNoRestart:(BOOL)v;
- (long)reportId;
- (void)setReportId:(long)v;
- (long)fieldId;
- (void)setFieldId:(long)v;
- (long)partId;
- (void)setPartId:(long)v;
- (long)pictureId;
- (void)setPictureId:(long)v;
// skipped field Support.Picture_ with unsupported type: *types.Named

// skipped field Support.Infos with unsupported type: *types.Slice

- (long)dropoffPictureId;
- (void)setDropoffPictureId:(long)v;
// skipped field Support.DropoffPicture_ with unsupported type: *types.Named

// skipped field Support.DropoffInfos with unsupported type: *types.Slice

// skipped field Support.CreatedAt with unsupported type: *types.Named

// skipped field Support.UpdatedAt with unsupported type: *types.Named

// skipped field Support.TempMetaData with unsupported type: *types.Named

/**
 * 	Ajout d'une information

	TODO: cas peut etre a gerer le met reviens faut il faire une copie
	en gros je commence -> juplod -> je recuper -> je modifie il se passe quoi ?
	voire pour peut etre gerer une version temporaire comme pour l'image
 */
- (void)addInfos:(long)index choice:(long)choice description:(NSString*)description x:(double)x y:(double)y width:(double)width height:(double)height;
- (id<ReportPhoto>)asPhoto;
- (void)createLink:(ReportStruct*)rpt part:(ReportPart*)part;
- (long)dropoffInfosCount;
- (ReportProcessInfos*)dropoffInfosGet:(long)num;
- (NSString*)getDropinPath;
- (NSString*)getDropoffPath;
- (NSString*)getDropoffPicturePath;
/**
 * /////////////////////////////////////
 */
- (ReportPart*)getPart;
- (NSString*)getPicturePath;
- (ReportStruct*)getReport;
- (NSString*)getTempPath;
// skipped method Support.GetTmpMeta with unsupported parameter or return types

- (BOOL)haveDropin;
- (BOOL)haveDropoff;
/**
 * 	permet de savoire si il faut download
	une image en verifiant si un path s3 est present
 */
- (BOOL)haveDropoffPictureToDownload;
- (BOOL)haveDropoffState;
/**
 * 	permet de savoire si il faut download
	une image en verifiant si un path s3 est present
 */
- (BOOL)havePictureToDownload;
- (BOOL)haveTemp;
- (NSString*)imgType;
/**
 * 	Suprime tout les information d'entrer

	TODO: cas peut etre a gerer le met reviens faut il faire une copie
	en gros je commence -> juplod -> je recuper -> je modifie il se passe quoi ?
	voire pour peut etre gerer une version temporaire comme pour l'image
 */
- (void)infosClean;
/**
 * 	renvois le nombre d'info/annotation du dropin
 */
- (long)infosCount;
/**
 * 	Renvois l'information a l index x
	TODO: securiser du out of index
 */
- (ReportProcessInfos*)infosGet:(long)num;
- (BOOL)isCompleted;
- (void)removeLink:(ReportStruct*)rpt part:(ReportPart*)part;
/**
 * /////////	Photo Protocol /////////////
 */
- (void)removeTemporary;
- (void)setTemplateMode;
- (NSString*)titleTr;
- (long)uid;
- (NSString*)uTplName;
- (void)updateByApi:(ReportSupport*)n;
- (NSString*)writeImage:(NSData*)data error:(NSError**)error;
@end

@interface ReportUpload : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)key;
- (void)setKey:(NSString*)v;
- (NSString*)hash;
- (void)setHash:(NSString*)v;
- (double)percent;
- (void)setPercent:(double)v;
- (NSString*)url;
- (void)setUrl:(NSString*)v;
- (long)step;
- (void)setStep:(long)v;
- (NSString*)sessionKey;
- (void)setSessionKey:(NSString*)v;
// skipped field Upload.Title_ with unsupported type: *types.Named

// skipped field Upload.Error with unsupported type: *types.Named

// skipped field Upload.FinishedAt with unsupported type: *types.Named

- (BOOL)autoUpload:(long*)ret0_ error:(NSError**)error;
- (void)delete;
- (double)getAdvencement;
- (WperrWperror*)getError;
/**
 * 	Renvoy l'url de l api pour avoire l'url presigner
 */
- (NSString*)getPackageApiUrl;
- (NSData*)getPackageCrypted:(NSError**)error;
- (NSData*)getPackageData:(NSError**)error;
- (NSString*)getPackageFullPath;
- (int64_t)getTimeFinished;
- (NSString*)getTitle;
- (void)setAdvencement:(double)value;
- (void)setError:(long)code value:(NSString*)value;
- (void)startStep:(long)step;
@end

/**
 * 	State
	toCompare = 0
	signaled = 0
 */
FOUNDATION_EXPORT const int64_t ReportProcessOk;
/**
 * 	State
	toCompare = 0
	signaled = 0
 */
FOUNDATION_EXPORT const int64_t ReportProcessSignaled;
/**
 * 	State
	toCompare = 0
	signaled = 0
 */
FOUNDATION_EXPORT const int64_t ReportProcessToCompate;

FOUNDATION_EXPORT void ReportDeleteReport(ReportStruct* r, id<ReportDeleteDelegate> delegate);

FOUNDATION_EXPORT void ReportExist(NSString* proovcode, id<ReportExistDelegate> delegate);

FOUNDATION_EXPORT BOOL ReportExistSync(NSString* proovcode, BOOL* ret0_, NSError** error);

/**
 * requiredProcessFieldsDropoff
requiredProcessFieldsDropoffWithImage

freeProcessFieldsDropoff          r:false
freeProcessFieldsDropoffWithImage r:false
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtract(ReportStruct* rpt, BOOL Required, BOOL haveTemporyData, BOOL WithFirst);

FOUNDATION_EXPORT ReportProcessStateList* ReportExtractAll(ReportStruct* rpt);

/**
 * freeProcessFields
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractFree(ReportStruct* rpt);

/**
 * freeProcessFieldsDropoff
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractFreeDropoff(ReportStruct* rpt);

/**
 * freeProcessFieldsDropoffWithImage
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractFreeDropoffWithImage(ReportStruct* rpt);

/**
 * libre au retour
processFieldsFreeForDropoff
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractFreeForDropoff(ReportStruct* rpt);

/**
 * freeProcessFieldsWithImage
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractFreeWithImage(ReportStruct* rpt);

/**
 * requiredProcessFields
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractRequired(ReportStruct* rpt);

/**
 * requiredProcessFieldsDropoff
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractRequiredDropoff(ReportStruct* rpt);

/**
 * requiredProcessFieldsDropoffWithImage
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractRequiredDropoffWithImage(ReportStruct* rpt);

/**
 * requiredProcessFieldsWithImage
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractRequiredWithImage(ReportStruct* rpt);

/**
 * processFieldsSignaled
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractSignaled(ReportStruct* rpt);

/**
 * processFieldsToCompare
 */
FOUNDATION_EXPORT ReportProcessStateList* ReportExtractToCompare(ReportStruct* rpt);

/**
 * 	Recuperer un Dossier sur le disque dur
 */
FOUNDATION_EXPORT ReportStruct* ReportGetCurrent(void);

FOUNDATION_EXPORT void ReportGetFromTemplate(BOOL forceRefresh, long id_, id<ReportFullDelegate> delegate);

FOUNDATION_EXPORT void ReportGetItemList(long itemId, NSString* states, NSString* find, long offset, long limit, id<ReportListDelegate> delegate);

FOUNDATION_EXPORT ReportList* ReportGetItemListSync(long itemId, NSString* states, NSString* find, long offset, long limit, NSError** error);

FOUNDATION_EXPORT void ReportGetList(NSString* state, NSString* find, long offset, long limit, id<ReportListDelegate> delegate);

FOUNDATION_EXPORT ReportList* ReportGetListSync(NSString* state, NSString* find, long offset, long limit, NSError** error);

/**
 * 	Permet de recuperer la liste de clee des fichier a upload
 */
FOUNDATION_EXPORT ReportListUpload* ReportGetListUpload(void);

// skipped function GetMetaImage with unsupported parameter or return types


FOUNDATION_EXPORT void ReportGetProovCode(NSString* proovCode, id<ReportFullDelegate> delegate);

FOUNDATION_EXPORT NSString* ReportGetProovCodeSync(NSString* proovCode, NSError** error);

/**
 * 	Verrifie si un dossier existe sur
	le disque dure

	il peut exister si il y a eu une coupure de l'app
	alors que l'utilisateur na pas fait
	signer et terminer / quitter proprement
 */
FOUNDATION_EXPORT BOOL ReportHaveCurrent(void);

FOUNDATION_EXPORT ReportStruct* ReportNewByProovCodeSync(NSString* proovCode, NSError** error);

FOUNDATION_EXPORT ReportStruct* ReportNewByStringReport(NSString* rptStr, NSError** error);

FOUNDATION_EXPORT ReportStruct* ReportNewByStringTemplate(NSString* templateStr, NSError** error);

FOUNDATION_EXPORT ReportStruct* ReportNewByTemplate(BOOL forceRefresh, long templateId, NSError** error);

FOUNDATION_EXPORT NSString* ReportPreparePackageSync(ReportStruct* r, NSError** error);

/**
 * 	suprime le dossier contenue dans le disque dure
	avec toute les photo
 */
FOUNDATION_EXPORT void ReportRemoveCurrent(void);

FOUNDATION_EXPORT void ReportRestor(void);

/**
 * 	Sauvgarde le rapport sur le disque dur
 */
FOUNDATION_EXPORT void ReportSaveReport(ReportStruct* r);

@class ReportCloseDelegate;

@class ReportDeleteDelegate;

@class ReportExistDelegate;

@class ReportField;

@class ReportFullDelegate;

@class ReportListDelegate;

@class ReportPDFDownloadDelegate;

@class ReportPhoto;

@class ReportSignPartDelegate;

@interface ReportCloseDelegate : NSObject <goSeqRefInterface, ReportCloseDelegate> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onCloseError:(NSError*)err;
- (void)onCloseSuccess;
@end

@interface ReportDeleteDelegate : NSObject <goSeqRefInterface, ReportDeleteDelegate> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onDeleteError:(NSError*)err;
- (void)onDeleteSuccess;
@end

@interface ReportExistDelegate : NSObject <goSeqRefInterface, ReportExistDelegate> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)reportExist:(BOOL)p0;
- (void)reportExistError:(NSError*)p0;
@end

/**
 * 	Field est une interface qui
	a pour but d'englober les champs infos et checkliste
	qui marche + / - de la meme façons
 */
@interface ReportField : NSObject <goSeqRefInterface, ReportField> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (NSString*)dropoffValueF;
- (id<ReportField>)getAsField;
- (ReportInfosParameters*)getParams;
- (ReportPart*)getPart;
- (ReportStruct*)getReport;
- (BOOL)haveDropoff;
- (BOOL)isRequire;
- (NSString*)nameF;
- (NSString*)titleTr;
- (NSString*)typeF;
- (NSString*)valueF;
- (NSString*)writeValue:(NSString*)p0;
@end

@interface ReportFullDelegate : NSObject <goSeqRefInterface, ReportFullDelegate> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onReportFullError:(NSError*)err;
- (void)onReportFullSuccess:(ReportStruct*)report;
@end

@interface ReportListDelegate : NSObject <goSeqRefInterface, ReportListDelegate> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onReportFindError:(NSError*)err;
- (void)onReportFindsuccess:(ReportList*)list;
@end

@interface ReportPDFDownloadDelegate : NSObject <goSeqRefInterface, ReportPDFDownloadDelegate> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onPdfDownloadedError:(NSError*)err;
- (void)onPdfDownloadedSuccess:(NSString*)path;
@end

/**
 * ReportPhotoProtocol
 */
@interface ReportPhoto : NSObject <goSeqRefInterface, ReportPhoto> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (NSString*)getDropinPath;
- (NSString*)getDropoffPath;
- (BOOL)haveDropin;
- (BOOL)haveDropoff;
- (BOOL)haveDropoffState;
- (void)removeTemporary;
- (NSString*)titleTr;
- (NSString*)uTplName;
- (NSString*)writeImage:(NSData*)p0 error:(NSError**)error;
@end

@interface ReportSignPartDelegate : NSObject <goSeqRefInterface, ReportSignPartDelegate> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onSignatureUploadError:(NSError*)err;
- (void)onSignatureUploadSuccess;
@end

#endif