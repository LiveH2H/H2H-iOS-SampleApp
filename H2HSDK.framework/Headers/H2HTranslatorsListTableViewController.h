//
//  H2HTranslatorsListTableViewController.h
//  H2H
//
//  Created by charuta.rajopadhye on 17/05/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

#define TRANSLATOR_LIST_ROW_WIDTH 350
#define TRANSLATOR_LIST_ROW_HEIGHT 44

@protocol H2HTranslatorsListOptionSelectedDelegate <NSObject>

@optional

- (void) translatorsListOptionSelectedAtIndexPath:(NSIndexPath*) indexPath;

@end

@interface H2HTranslatorsListTableViewController : UITableViewController

/**
 * @brief data source to populate the table view (objects of type NSStrings)
 *
 */
@property (nonatomic) NSArray<RTCTranslatorUser *> *arrayDataSource;

@property (nonatomic, weak) id <H2HTranslatorsListOptionSelectedDelegate> delegate;

@property (nonatomic)NSString *translatorName;

@property (strong, nonatomic) IBOutlet UITableView *tableViewTranslatorsList;

@end
