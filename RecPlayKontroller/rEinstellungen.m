#import "rEinstellungen.h"

@implementation rEinstellungen
- (id) init
{
	self=[super initWithWindowNibName:@"RPEinstellungen"];
	return self;
}

- (void)awakeFromNib
{
	NSFont* Tablefont;
	Tablefont=[NSFont fontWithName:@"Helvetica" size: 14];
//[TimeoutCombo synchronizeTitleAndSelectedItem];
	
}


- (IBAction)mitBewertung:(id)sender
{
	//NSLog(@"mitBewertung");
	NSNotificationCenter * nc;
	nc=[NSNotificationCenter defaultCenter];
	NSNumber* CheckboxStatus=[NSNumber numberWithInt:[sender state]];
	NSMutableDictionary* BewertungDic=[NSMutableDictionary dictionaryWithObject:CheckboxStatus forKey:@"Status"];
	[nc postNotificationName:@"mitBewertung" object:self userInfo:BewertungDic];
}

- (IBAction)mitNote:(id)sender
{
	//NSLog(@"mitNote");
	NSNotificationCenter * nc;
	nc=[NSNotificationCenter defaultCenter];
	NSNumber* CheckboxStatus=[NSNumber numberWithInt:[sender state]];
	NSMutableDictionary* NotenDic=[NSMutableDictionary dictionaryWithObject:CheckboxStatus forKey:@"Status"];
	[nc postNotificationName:@"mitNote" object:self userInfo:NotenDic];
	
}


- (void)setBewertung:(BOOL)mitBewertung
{
	//int s=[BewertungZeigen state];
	[BewertungZeigen setState:mitBewertung];
}

- (void)setTimeoutDelay:(NSTimeInterval)derDelay
{
NSLog(@"setTimeoutDelay: derDelay: %f",derDelay);
	[TimeoutCombo setIntValue:derDelay];
}



- (void)setNote:(BOOL)mitNote
{
	//int s=[BewertungZeigen state];
	[NoteZeigen setState:mitNote];
}

- (IBAction)reportClose:(id)sender
{
	NSNotificationCenter * nc;
	nc=[NSNotificationCenter defaultCenter];
	NSNumber* mitPWNumber=[NSNumber numberWithInt:[mitUserPasswort state]];
	NSMutableDictionary* StatusDic=[NSMutableDictionary dictionaryWithObject:mitPWNumber forKey:@"mituserpasswort"];
	NSNumber* NoteStatus=[NSNumber numberWithInt:[NoteZeigen state]];
	[StatusDic setObject:NoteStatus forKey:@"notenstatus"];
	NSNumber* BewertungStatus=[NSNumber numberWithInt:[BewertungZeigen state]];
	[StatusDic setObject:BewertungStatus forKey:@"bewertungstatus"];
	int TimeoutDelay=[TimeoutCombo  intValue];
	NSLog(@"TimeoutDelay: %d  ",TimeoutDelay  );
	[StatusDic setObject:[NSNumber numberWithInt:TimeoutDelay] forKey:@"timeoutdelay"];
	NSLog(@"reportClose: StatusDic: %@",[StatusDic description]);
	[nc postNotificationName:@"StartStatus" object:self userInfo:StatusDic];

    //[NSApp stopModalWithCode:1];
	[[self window]orderOut:NULL];

}
- (IBAction)reportCancel:(id)sender
{
    [NSApp stopModalWithCode:0];
	[[self window]orderOut:NULL];
}
- (void)setMitPasswort:(BOOL)mitPW
{
[mitUserPasswort setState:mitPW];
}

@end
