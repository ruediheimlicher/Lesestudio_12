//
//  rUtils.h
//  RecPlayII
//
//  Created by sysadmin on 26.06.05.
//  Copyright 2005 __MyCompanyName__. All rights reserved.
//
#import <QuickTime/QuickTime.h>
#import <Cocoa/Cocoa.h>
#import "rProjektNamen.h"
#import "rNamenListe.h"
#import "rPasswortDialog.h"
#import "rPasswortRequest.h"
#import "rTimeoutDialog.h"
#import "rEinzelNamen.h"

@interface rUtils : NSObject 
{
	NSMutableString*	 ULeseboxPfad;
	NSMutableString*	 UArchivPfad;
	NSMutableString*	 UProjektPfad;
	NSMutableString*	 UaktuellesProjekt;
	NSMutableArray*		UProjektArray;
	NSMutableArray*		UProjektNamenArray;
	NSString*			UProjektName;
	
	rProjektNamen*						UProjektNamenPanel;
	rNamenListe*						UNamenListePanel;
	rEinzelNamen*						UEinzelNamenPanel;
	rPasswortDialog*					UPasswortDialogPanel;
	rPasswortRequest*					UPasswortRequestPanel;
	rTimeoutDialog*						UTimeoutDialogPanel;
	NSTimer*							TimeoutTimer;
	NSTimer*							TimeoutDialogTimer;
	int									TimeoutCount;
//Flags
}
- (NSString*)ULeseboxPfad;
- (void)setULeseboxPfad:(NSString*)derPfad;
- (NSString*)UArchivPfad;
- (void)setUArchivPfad:(NSString*)derPfad;
- (NSString*)UProjektPfad;
- (void)setUProjektPfad:(NSString*)derPfad;
- (NSArray*)UProjektArray;
- (void)setUProjektArray:(NSArray*)derArray;
#pragma mark -
- (NSArray*) checkUsersMitLesebox;
- (NSArray*) checkNetzwerkVolumes;
- (NSString*)checkHomeLesebox;
- (BOOL)setVersion;
- (BOOL)istSystemVolumeAnPfad:(NSString*)derLeseboxPfad;
- (BOOL)LeseboxValidAnPfad:(NSString*)derLeseboxPfad aufSystemVolume:(BOOL)istSystemVolume;
- (NSArray*)UOrdnernamenArrayVonKlassenliste;
- (BOOL)ArchivValidAnPfad:(NSString*)derLeseboxPfad;
- (IBAction)showProjektNamenListe:(NSArray*)derArray;
- (NSArray*)ProjektNamenArrayVon:(NSString*)derArchivPfad;
- (NSArray*)ProjektArrayAusPListAnPfad:(NSString*)derLeseboxPfad;
- (int)ProjektArrayInPList:(NSArray*)derProjektArray  anPfad:(NSString*)derLeseboxPfad;
- (BOOL)ProjektOrdnerEinrichtenAnPfad:(NSString *)derProjektPfad;
- (IBAction)showNamenListe:(id)sender;
- (void) showEinzelNamen:(id)sender;
- (NSArray*)EinzelNamenArray;
- (int) fileInPapierkorb:(NSString*) derFilepfad;
- (int)inPapierkorbMitPfad:(NSString*)derProjektPfad;
- (int)insMagazinMitPfad:(NSString*)derNamenPfad;
- (int)exMitPfad:(NSString*)derNamenPfad;
- (NSDictionary*)PListDicVon:(NSString*)derLeseboxPfad aufSystemVolume:(BOOL)istSysVol;
- (BOOL)deletePListAnPfad:(NSString*)derLeseboxPfad aufSystemVolume:(BOOL)istSysVol;
- (BOOL) setPListBusy:(BOOL)derStatus anPfad:(NSString*)derPfad;
//- (NSDictionary*)PListDicVon:(NSString*)derLeseboxPfad;

#pragma mark -
- (NSDictionary*)changePasswort:(NSDictionary*)derNamenDic;
- (BOOL)confirmPasswort:(NSDictionary*)derNamenDic;
#pragma mark -
- (void)showTimeoutDialog:(id)sender;
- (void)startTimeout:(NSTimeInterval)derTimeout;
- (void)delayTimeout:(NSTimeInterval)derDelay;
- (void)stopTimeout;

- (BOOL)createKommentarFuerLeser:(NSString*)derLeser FuerAufnahmePfad:(NSString*)derAufnahmePfad;

- (BOOL)setKommentar:(NSString*)derKommentarString inAufnahmeAnPfad:(NSString*)derAufnahmePfad;
- (NSString*)KommentarStringVonAufnahmeAnPfad:(NSString*)derAufnahmePfad;

@end
