//
//  H2HLiveSupportIssue.h
//  H2H
//
//  Created by Kalyani.Chinchane on 16/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface H2HLiveSupportIssue : NSObject
/**
 * The issue name.
 */
typedef NS_ENUM (NSInteger, LiveSupportIssue) {
    H2HLiveSupportIssueCamera,
    H2HLiveSupportIssueMicrophone,
    H2HLiveSupportIssueConnection,
    H2HLiveSupportIssueLiveBoard,
    H2HLiveSupportIssueInvitation,
    H2HLiveSupportIssueOther
};


/*denotes the issue */
@property (readwrite,nonatomic) LiveSupportIssue issueName;

/*denotes the issue list */
@property (readwrite,nonatomic) NSArray *issueList;

//issue name
@property (readwrite,nonatomic) NSString    *strIssueName;

-(id)initWithIssueName:(LiveSupportIssue)issueName;
@end
